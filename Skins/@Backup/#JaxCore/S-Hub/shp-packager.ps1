<#

>>==SCRIPT PARAMETERS==<<
$o_name             - Name of package
$o_useDiscord       - package BetterDiscord?
$o_useSpotify       - package Spicetify theme?
$o_useFirefox       - package Firefox profile?
$o_useWinVS         - package Windows visual style?
$o_RMLOC            - rainmeter installation location
$o_saveLocation     - location to save generated folder structure [==Default set when running==]
$o_saveLocationSHP  - location to export the package [==Default set when running==]
$o_keepGenerated    - keep generated folder structure?
$o_noCompile          - compile SHP package? (debug only)

#>

param(
    [Parameter(Mandatory=$true)][Alias("n")][ValidateNotNullOrEmpty()][string]$o_name,
    [Alias("uD")][switch]$o_useDiscord,
    [Alias("uS")][switch]$o_useSpotify,
    [Alias("uF")][switch]$o_useFirefox,
    [Alias("uW")][switch]$o_useWinVS,
    [Alias("locrm")][string]$o_RMLOC,
    [Alias("locsave")][string]$o_saveLocation,
    [Alias("locexport")][string]$o_saveLocationSHP,
    [Alias("devkeep")][switch]$o_keepGenerated,
    [Alias("dev")][switch]$o_noCompile
) 

$ErrorActionPreference = 'SilentlyContinue'

# ---------------------------------------------------------------------------- #
#                                   Functions                                  #
# ---------------------------------------------------------------------------- #

# -------------------------------- Write-Host -------------------------------- #

function Write-Task ([string] $Text) {
  Write-Host $Text -NoNewline
}

function Write-Done {
  Write-Host " > " -NoNewline
  Write-Host "OK" -ForegroundColor "Green"
}

function Write-Emphasized ([string] $Text) {
  Write-Host $Text -NoNewLine -ForegroundColor "Cyan"
}

function Write-Info ([string] $Text) {
  Write-Host $Text -ForegroundColor "Yellow"
}

function Write-Fail ([string] $Text) {
  Write-Host $Text -ForegroundColor "Red"
}

function debug ([string] $Text) {
  Write-Host $Text
}

# ------------------------------------ Ini ----------------------------------- #

function Get-IniContent ($filePath) {
    $ini = [ordered]@{}
    if (![System.IO.File]::Exists($filePath)) {
        throw "$filePath invalid"
    }
    # $section = ';ItIsNotAFuckingSection;'
    # $ini.Add($section, [ordered]@{})

    foreach ($line in [System.IO.File]::ReadLines($filePath)) {
        if ($line -match "^\s*\[(.+?)\]\s*$") {
            $section = $matches[1]
            $secDup = 1
            while ($ini.Keys -contains $section) {
                $section = $section + '||ps' + $secDup
            }
            $ini.Add($section, [ordered]@{})
        }
        elseif ($line -match "^\s*;.*$") {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $matches[1]
        }
        elseif ($line -match "^\s*(.+?)\s*=\s*(.+?)$") {
            $key, $value = $matches[1..2]
            $ini[$section][$key] = $value
        }
        else {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $line
        }
    }

    return $ini
}

function Set-IniContent($ini, $filePath) {
    $str = @()
    foreach ($section in $ini.GetEnumerator()) {
        if ($section -ne ';ItIsNotAFuckingSection;') {
            $str += "[" + ($section.Key -replace '\|\|ps\d+$', '') + "]"
        }
        foreach ($keyvaluepair in $section.Value.GetEnumerator()) {
            if ($keyvaluepair.Key -match "^;NotSection\d+$") {
                $str += $keyvaluepair.Value
            }
            else {
                $str += $keyvaluepair.Key + "=" + $keyvaluepair.Value
            }
        }
    }
    $finalStr = $str -join [System.Environment]::NewLine
    $finalStr | Out-File -filePath $filePath -Force -Encoding unicode
}

# ----------------------------------- Copy ----------------------------------- #

function Copy-Path {
    [CmdletBinding()]
    param(
        [Parameter(ValueFromPipeline = $true, ValueFromPipelineByPropertyName = $true, Position = 0)]
        [ValidateScript({Test-Path -Path $_ -PathType Container})]
        [string]$Source,

        [Parameter(Position = 1)]
        [string]$Destination,

        [string[]]$ExcludeFolders = $null,
        [switch]$IncludeEmptyFolders
    )
    $Source      = $Source.TrimEnd("\")
    $Destination = $Destination.TrimEnd("\")

    Get-ChildItem -Path $Source -Recurse | ForEach-Object {
        if ($_.PSIsContainer) {
            # it's a folder
            if ($ExcludeFolders.Count) {
                if ($ExcludeFolders -notcontains $_.Name -and $IncludeEmptyFolders) {
                    # create the destination folder, even if it is empty
                    $target = Join-Path -Path $Destination -ChildPath $_.FullName.Substring($Source.Length)
                    if (!(Test-Path $target -PathType Container)) {
                        # Write-Verbose "Create folder $target"
                        New-Item -ItemType Directory -Path $target | Out-Null
                    }
                }
            }
        }
        else {
            # it's a file
            $copy = $true
            if ($ExcludeFolders.Count) {
                # get all subdirectories in the current file path as array
                $subs = $_.DirectoryName.Replace($Source,"").Trim("\").Split("\")
                # check each sub folder name against the $ExcludeFolders array
                foreach ($folderName in $subs) {
                    if ($ExcludeFolders -contains $folderName) { $copy; break }
                }
            }

            if ($copy) {
                # create the destination folder if it does not exist yet
                $target = Join-Path -Path $Destination -ChildPath $_.DirectoryName.Substring($Source.Length)
                if (!(Test-Path $target -PathType Container)) {
                    # Write-Verbose "Create folder $target"
                    New-Item -ItemType Directory -Path $target | Out-Null
                }
                # Write-Verbose "Copy file $($_.FullName) to $target"
                $_ | Copy-Item -Destination $target -Force
            }
        }
    }
}

# ---------------------------------------------------------------------------- #
#                                     Start                                    #
# ---------------------------------------------------------------------------- #

# Test: .\S-Hub\shp-packager.ps1 -n "Test" -uD -uF -uS
# -dev

Write-Info "SHPPACKAGER REF: Experimental v1"
# ---------------------------- Installer variables --------------------------- #
$SHPdataContent = ""
# If rm location not provided, use standard paths
if (!($o_RMLOC)) {
    $s_RMSettingsFolder = "$env:APPDATA\Rainmeter\"
    $s_RMINIFile = "$($s_RMSettingsFolder)Rainmeter.ini"
    $RMEXEloc = "$Env:Programfiles\Rainmeter\Rainmeter.exe"
} else {
    $s_RMSettingsFolder = "$o_RMLOC\Rainmeter\"
    $s_RMINIFile = "$($s_RMSettingsFolder)Rainmeter.ini"
    $RMEXEloc = "$($s_RMSettingsFolder)Rainmeter.exe"
}
# Get the set skin path
If (Test-Path $s_RMINIFile) {
    $Ini = Get-IniContent $s_RMINIFile
    $s_RMSkinFolder = $Ini["Rainmeter"]["SkinPath"]
    $Ini = $null
} else {
    Write-Fail "Unable to locate $s_RMINIFile."
    Write-Info "S-Hub packages requires Rainmeter to be installed at the moment."
    Return
}
# ----------------------------- Default locations ---------------------------- #
if (!($o_saveLocation)) {$o_saveLocation = "$s_RMSkinFolder..\CoreData\S-Hub\Generated"}
if (!($o_saveLocationSHP)) {$o_saveLocationSHP = "$s_RMSkinFolder..\CoreData\S-Hub\Exports"}
# Set running directory
[System.IO.Directory]::SetCurrentDirectory($o_saveLocationSHP)

Write-Info "Getting required information..."
# -------------------------------- Get rm bit -------------------------------- #
$rmprocess_object = Get-Process Rainmeter
$rmprocess_id = $rmprocess_object.id
Write-Task "Getting Rainmeter bitness..."
$bit = '32bit'
Get-Process -Id $rmprocess_id | Foreach {
    $modules = $_.modules
    foreach($module in $modules) {
        $file = [System.IO.Path]::GetFileName($module.FileName).ToLower()
        if($file -eq "wow64.dll") {
            $bit = "32bit"
            Break
        } else {
            $bit = "64bit"
        }
    }
}
Write-Done
# ---------------------------------- Screen ---------------------------------- #
Write-Task "Getting screen sizes"
$vc = Get-WmiObject -class "Win32_VideoController"
$saw = $vc.CurrentHorizontalResolution
$sah = $vc.CurrentVerticalResolution
Write-Done

# ------------------------------- Start package ------------------------------ #
Write-Info "Start packaging..."
debug "-----------------"
debug "SetupName: $o_name"
debug "RainmeterPluginsBit: $bit"
debug "RainmeterPath: $s_RMSettingsFolder"
debug "RainmeterExePath: $RMEXEloc"
debug "RainmeterSkinsPath: $s_RMSkinFolder"
debug "SavingDirectory_Generated: $o_saveLocation"
debug "SavingDirectory_SHP: $o_saveLocationSHP"
debug "ScreenAreaSizes: $saw x $sah"
debug "-----------------"

$SHPdataContent += @"
[Data]
SetupName=$o_name
ScreenSizeW=$saw
ScreenSizeH=$sah
"@
# ------------------------------ Wipe directory ------------------------------ #
If (Test-Path -Path "$o_saveLocation") {Remove-Item "$o_saveLocation" -Recurse -Force > $null}
# ----------------------------- Create directory ----------------------------- #
New-Item -Path "$o_saveLocation" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\RainmeterSkins" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\Wallpaper" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins\Spicetify" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins\BetterDiscord" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocation\AppSkins\Firefox" -ItemType "Directory" > $null
New-Item -Path "$o_saveLocationSHP" -ItemType "Directory" > $null
# ---------------------------- Read Rainmeter.ini ---------------------------- #
Write-Info "Getting Rainmeter layout..."
$Ini = Get-IniContent $s_RMINIFile

debug "Found $($Ini.Count) sections in $s_RMINIFile"
# -------------------------- Filter through sections ------------------------- #
$s_RMINIFile_filterpattern = "^Rainmeter$","^#JaxCore","^#Keylaunch","^DropTop","@Start$" -join '|'
[string[]]$Ini.Keys | Where-Object { $Ini[$_].Active -contains "0" -or $_ -match $s_RMINIFile_filterpattern } | ForEach-Object { 
    $Ini.Remove($_)
}
# -------------------------------- Tag modules ------------------------------- #
$tagged_modules = "ValliStart|YourFlyouts|YourMixer|Keylaunch|IdleStyle"
$SHPdataContent += @"

SHP.Tags=
"@
[string[]]$Ini.Keys | Where-Object { $Ini[$_].Active -contains "0" -or $_ -match $tagged_modules } | ForEach-Object { 
    $_ = $_ -replace '\\.*$', ''
    debug "Valid SHP Tag: $_"
    $SHPdataContent += @"
$_ | 
"@
}
# ----------------------- Convert sections to skin name ---------------------- #
$valid_skins = [string[]]$Ini.Keys | ForEach-Object { $_ -replace '\\.*$', '' }
# --------------------------- Work with valid skins -------------------------- #
$i = 0
$SHPdataContent += @"

SHP.Skins=
"@
$valid_skins | select-object -unique | ForEach-Object { 
    $i = $i + 1
    # Add names to data
    $SHPdataContent += @"
$_, 
"@
    # Copy skin contents
    If (!($o_noCompile)) {Copy-Path -Source "$s_RMSkinFolder$_" -Destination "$o_saveLocation\RainmeterSkins\$_\" -ExcludeFolders '.git'}
}
debug "$i valid skins copied"

# ----------------------------- Export Rainmeter.ini ---------------------------- #
Set-IniContent -ini $Ini -filePath "$o_saveLocation\Rainmeter.ini" -Encoding unicode -Force
# --------------------------------- Spicetify -------------------------------- #
If ($o_useSpotify) {
    try {spicetify.exe > $null}
    catch {$spicetify_detected = $false}
    
    If ($spicetify_detected -ne $false) {
        Write-Info 'Getting spicetify assets...'
        $spicetifyconfig_path = spicetify.exe -c
        $spicetify_path = "$spicetifyconfig_path\..\"
        If (Test-Path -Path "$spicetifyconfig_path") {
            $Ini = Get-IniContent $spicetifyconfig_path
            $spicetify_current_theme = $Ini['Setting']["current_theme"]
            $spicetify_color_scheme = $Ini['Setting']["color_scheme"]
            # Copy spicetify theme 
            debug "> Found spicetify"
            debug "Exporting Theme: $spicetify_current_theme, ColorScheme: $spicetify_color_scheme"
            If (!($o_noCompile)) {Copy-Item -Path "$spicetify_path\Themes\$spicetify_current_theme\*" -Destination "$o_saveLocation\AppSkins\Spicetify" -Force}
            $SHPdataContent += @"


[Spicetify]
current_theme=$spicetify_current_theme
color_scheme=$spicetify_color_scheme
"@
            Write-Task "Spicetify"
            Write-Done
        }
    } else {
        Write-Fail 'Spicetify is expected to be detected, but failed to do so.'
        Write-Info 'Continuing...'
    }
}

# ------------------------------- BetterDiscord ------------------------------ #
If ($o_useDiscord) {
    $bd_path = "$env:APPDATA\BetterDiscord"
    If (Test-Path -Path $bd_path) {
        Write-Info 'Getting BetterDiscord assets...'

        $bd_data_folders = Get-ChildItem -Path "$bd_path\data" -Directory
        If ($bd_data_folders.Count -eq 1) {
            $bd_selected_folder = $bd_data_folders
        } else {
            $bd_selected_folder = $bd_data_folders[0]
        }
        debug "Extracting themes from bd:$bd_selected_folder"

        $bd_themes = Get-Content -Path "$bd_path\data\$($bd_selected_folder)\themes.json" | ConvertFrom-Json

        $i_found = $False
        $bd_themes | Get-Member | Where-Object -Property MemberType -match "NoteProperty" | Select-Object "Name" | ForEach-Object { 
            $i_bd_themename = "$([string]$_.Name)"
            
            If (($($bd_themes.$i_bd_themename) -match "True") -and ($i_found -eq $False)) {
                debug "Theme `"$i_bd_themename`" applied, trying to find css file"
                Get-ChildItem -Path "$bd_path\themes\*" -Include *.theme.css | ForEach-Object {
                    $a = Get-Content $_ -First 2
                    $a = [regex]::match($a,'/\*\*\s\s\*\s@name\s(.*)').Groups[1].Value
                    If ($i_bd_themename -contains $a) {
                        debug "Found theme in $_"
                        Copy-Item -Path "$_" -Destination "$o_saveLocation\AppSkins\BetterDiscord" -Force
                        $SHPdataContent += @"


[BetterDiscord]
themename=$i_bd_themename
"@

                    }
                }
            $i_found = $True
            
            }
        }
        Write-Task "BetterDiscord"
        Write-Done
    } else {
        Write-Fail 'BetterDiscord is expected to be detected, but failed to do so.'
        Write-Info 'Continuing...'
    }
}
# ---------------------------------- Firefox --------------------------------- #
If ($o_useFirefox) {
    $ff_path = "$env:APPDATA\Mozilla\Firefox\"
    $ffconfig_path = "$($ff_path)profiles.ini"
    If (Test-Path -Path "$ffconfig_path") {
        Write-Info 'Getting Firefox assets...'
        $Ini = Get-IniContent $ffconfig_path
        $ff_defaultprofile_path = $Ini[0]["Default"]
        debug "Found profile: $ff_defaultprofile_path"
        $ff_userchrome_path = "$($ff_path)$ff_defaultprofile_path\chrome\userChrome.css"
        If (Test-Path -Path "$ff_userchrome_path") {
            debug "Found custom css in profile"
            # Copy firefox theme 
            debug "Exporting userChrome $ff_userchrome_path"
            If (!($o_noCompile)) {Copy-Item -Path "$ff_userchrome_path" -Destination "$o_saveLocation\AppSkins\Firefox" -Force}
            $SHPdataContent += @"


[Firefox]
found=1
"@
            Write-Task "Firefox"
            Write-Done
        }
    } else {
        Write-Fail 'Firefox custom css is expected to be detected, but failed to do so.'
        Write-Info 'Continuing...'
    }
}

# --------------------------------- Wallpaper -------------------------------- #

Write-Info 'Getting Wallpaper...'
$wallpaper_path = Get-ItemProperty 'HKCU:\Control Panel\Desktop' | Select -exp 'Wallpaper'
Write-Task "Copying wallpaper from $wallpaper_path"
$wallpaper_ext = $wallpaper_path -replace '^.*\.', ''
Copy-Item -Path $wallpaper_path -Destination "$o_saveLocation\Wallpaper\Wallpaper.$wallpaper_ext" -Force
Write-Done

# ---------------------------------- Export ---------------------------------- #
Write-Info "Finalizing"
Write-Task "Exporting SHP-data.ini"
$SHPdataContent | Out-File -FilePath "$o_saveLocation\SHP-data.ini" -Encoding unicode -Force
Write-Done
Write-Task "Compiling SHP package"
If (!($o_noCompile)) {
    $ProgressPreference = 'SilentlyContinue'
    Compress-Archive -Path "$o_saveLocation\*" -DestinationPath "$o_saveLocationSHP\$o_name.zip" -Force -CompressionLevel "Fastest"
    Rename-Item -Path "$o_saveLocationSHP\$o_name.zip" -NewName "$o_name.shp"
} else {
    Compress-Archive -Path "$o_saveLocation\*" -DestinationPath "$o_saveLocationSHP\$o_name.zip" -Force -CompressionLevel "Fastest" -WhatIf
    Rename-Item -Path "$o_saveLocationSHP\$o_name.zip" -NewName "$o_name.shp" -WhatIf
}
If (!($o_keepGenerated)) {Remove-Item -Path "$o_saveLocation\*" -Recurse}
Write-Done
# Open folder
Invoke-Item $o_saveLocationSHP