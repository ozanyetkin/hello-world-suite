[Rainmeter]

[Variables]
SettingsMenuNumber=1.2.23

@Include99Settings=#@#Themes\99Settings.inc
@IncludeNumSettings=#@#Themes\#ThemeNum#Settings.inc

[MeasureTime]
Measure=Time
Format="%Y/%m/%d @ %H:%M"
DynamicVariables=1

[MeasureSaveTheme]
Measure=Plugin
Plugin=RunCommand
Parameter=RD /S /Q "#SKINSPATH#Droptop\@Resources\Themes\My saved theme" & mkdir "#SKINSPATH#Droptop\@Resources\Themes\My saved theme" & xcopy /y /f /i "#SKINSPATH#Droptop\@Resources\Themes\99.inc" "#SKINSPATH#Droptop\@Resources\Themes\My saved theme" & xcopy /y /f /i "#SKINSPATH#Droptop\@Resources\Themes\99Settings.inc" "#SKINSPATH#Droptop\@Resources\Themes\My saved theme" & cd "#SKINSPATH#Droptop\@Resources\Themes\My saved theme" & tar.exe -a -c -f "#CustomThemeName# by #CustomThemeAuthor#.zip" "99.inc" "99Settings.inc" & del /f "#SKINSPATH#Droptop\@Resources\Themes\My saved theme\99.inc" & del /f "#SKINSPATH#Droptop\@Resources\Themes\My saved theme\99Settings.inc"
State=Hide
OutputType=ANSI
OutputFile=
FinishAction=["#@#Themes\My saved theme"]

[MeasureSupporter]
Measure=Calc
IfCondition=(#Supporter#=0) && (#SettingsMenuIndex#>4) && (#SettingsMenuIndex#<23)
IfTrueAction=[!SetOption 1 Text "Get the supporter version"][!SetOption 1 LeftMouseDownAction """["https://gumroad.com/l/droptop"]#*CloseSettingsMenu*#"""]
UpdateDivider=-1

[Divider1]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*1)+(#DropdownItemHeight#*1)-(#DividerHeight#/2))

[2]
MeterStyle=InfoStyle | InfoStyleB
Y=(#DividerSpace#*2)R

[2Icon]
Y=(#DividerSpace#*2)R

[Divider2]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*3)+(#DropdownItemHeight#*2)-(#DividerHeight#/2))

[3]
MeterStyle=InfoStyle | InfoStyleB
Y=(#DividerSpace#*2)R
MiddleMouseDownAction=#HideSettingsMenu#["Notepad.exe" "#@#Themes\99.inc"]["Notepad.exe" "#@#Themes\99Settings.inc"]#CloseSettingsMenu#

[3Icon]
Y=(#DividerSpace#*2)R
