[Variables]
ExitDroptopNum=0
ExitDroptopAction0=[!SetVariable ExitDroptopNum 1][!UpdateMeter [#*CURRENTSECTION*]][!Redraw]
ExitDroptopAction1=#HideSettingsMenu#[!HideGroup ContextBox][!DeactivateConfigGroup ContextBox][!DeactivateConfigGroup DroptopSuite]

[MeasureRegistry]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize
RegValue=SystemUsesLightTheme
Substitute="0":"Temp","1":"0","Temp":"1"
UpdateDivider=-1

[RunCommand.ToggleLightMode]
Measure=Plugin
Plugin=RunCommand
Parameter=reg add "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Themes\Personalize" /v SystemUsesLightTheme /t REG_DWORD /d [MeasureRegistry] /f
State=Hide
OutputType=ANSI
OutputFile=
DynamicVariables=1

[Divider1]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*1)+(#DropdownItemHeight#*1)-(#DividerHeight#/2))

[2]
Y=(#DividerSpace#*2)R
FontColor=#DropdownFontColor1#,([#DropdownItemOpacity]/3)
MouseOverAction=[]
MouseLeaveAction=[]

[2Icon]
Y=(#DividerSpace#*2)R

[Divider2]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*3)+(#DropdownItemHeight#*3)-(#DividerHeight#/2))

[4]
Y=(#DividerSpace#*2)R

[4Icon]
Y=(#DividerSpace#*2)R

[Divider3]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*5)+(#DropdownItemHeight#*4)-(#DividerHeight#/2))

[5]
Y=(#DividerSpace#*2)R

[5Icon]
Y=(#DividerSpace#*2)R

[6]
DynamicVariables=1