#SingleInstance Force
#NoTrayIcon
SetTitleMatchMode Regex
DetectHiddenWindows On

IniRead, OutputVar, Hotkeys.ini, Variables, Key
IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH
IniRead, Media, ..\Vars.inc, Variables, Media
IniRead, OptionalKey, ..\Vars.inc, Variables, OptionalKey
IniRead, LegacyVol, ..\Vars.inc, Variables, LegacyVol
IniRead, LegacyBright, ..\Vars.inc, Variables, LegacyBright
IniRead, OverrideLocks, ..\Vars.inc, Variables, OverrideLocks
IniRead, SmartVolume, ..\Vars.inc, Variables, SmartVolume

Name = ValliStart.ahk

DetectHiddenWindows On
SetTitleMatchMode RegEx
IfWinExist, i)%Name%.* ahk_class AutoHotkey
{
    ValliScriptPath = % RegExReplace(a_scriptdir,"YourFlyouts.*\\?$")"Vallistart\@Resources\Actions\Source code\Vallistart.ahk"
    ValliAhkPath = % RegExReplace(a_scriptdir,"YourFlyouts.*\\?$")"Vallistart\@Resources\Actions\"
    Run, %ValpliAhkPath%AHKv1.exe `"%ValliScriptPath%`", %ValliAhkPath%
}

if (OptionalKey = 1)
{
    Hotkey,%OutputVar%,Button
}
if (SmartVolume = 1)
{
    Hotkey +Volume_Up, MediaUp
    Hotkey +Volume_Down, MediaDown
}
if (LegacyVol = 1)
{
    Hotkey Volume_Up, LoadUp
    Hotkey Volume_Down, LoadDown
    Hotkey Volume_Mute, LoadMute
}
if (LegacyBright = 1)
{
    IniRead, OutputVar2, Hotkeys.ini, Variables, Key2
    IniRead, OutputVar3, Hotkeys.ini, Variables, Key3
    Hotkey,%OutputVar2%, BrightDown
    Hotkey,%OutputVar3%, BrightUp
}
if (OverrideLocks = 1)
{
    Hotkey CapsLock, LoadCapsLock
    Hotkey NumLock, LoadNumLock
    Hotkey ScrollLock, LoadScrollLock
}
Return

LoadUp:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('vol'`, 'up')" "YourFlyouts\Main" "
Return
LoadDown:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('vol'`, 'down')" "YourFlyouts\Main" "
Return
LoadMute:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('vol'`, 'mute')" "YourFlyouts\Main" "
Return
BrightUp:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('bright'`, 'up')" "YourFlyouts\Main" "
Return
BrightDown:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('bright'`, 'down')" "YourFlyouts\Main" "
Return

LoadCapsLock:
    SetCapsLockState % !GetKeyState("CapsLock", "T") ;
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('locks')" "YourFlyouts\Main" "
Return
LoadNumLock:
    SetNumLockState % !GetKeyState("NumLock", "T") ;
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('locks')" "YourFlyouts\Main" "
Return
LoadScrollLock:
    SetScrollLockState % !GetKeyState("ScrollLock", "T") ;
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('locks')" "YourFlyouts\Main" "
Return


Button:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad()" "YourFlyouts\Main" "
Return


MediaUp:
    Run "%RainmeterPath% "!CommandMeasure "Func" "mediaVol('up')" "YourFlyouts\Main" "
Return

MediaDown:
    Run "%RainmeterPath% "!CommandMeasure "Func" "mediaVol('down')" "YourFlyouts\Main" "
Return
