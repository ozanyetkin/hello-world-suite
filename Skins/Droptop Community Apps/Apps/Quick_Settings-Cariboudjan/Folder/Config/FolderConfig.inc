[Rainmeter]
Group=DroptopSuite | Tray | Folders | Submenus
LeftMouseDownAction=[]

DefaultSavePosition=1
DefaultAlwaysOnTop=1
DefaultDraggable=1
DefaultSnapEdges=1
DefaultStartHidden=0
DefaultAlphaValue=255
DefaultHideOnMouseOver=0
DefaultFadeDuration=105
DefaultClickThrough=0
DefaultKeepOnScreen=1
DefaultAutoSelectScreen=0

[Variables]
@IncludeControl=#SKINSPATH#Droptop\@Resources\GlobalVar\Control.inc
@IncludeUserSettings=#SKINSPATH#Droptop\@Resources\GlobalVar\UserSettings.inc
@IncludeThemeOptions=#SKINSPATH#Droptop\@Resources\Themes\#ThemeNum#Settings.inc
@IncludeThemeDesign=#SKINSPATH#Droptop\@Resources\Themes\#ThemeNum#.inc
@IncludeSystemTrayMeters=#SKINSPATH#Droptop\@Resources\Meters\SystemTraySubMenuMeters.inc
@IncludeLanguage=#SKINSPATH#Droptop\@Resources\GlobalVar\Languages\[#Language[#LanguageNum]].inc
@IncludeVariablesDefault=#SKINSPATH#Droptop Community Apps\Apps\[#CustomAppID[#CustomApp[#CustomAppPosition]Num]]\Variables\VariablesDefault.inc
@IncludeVariables=#SKINSPATH#Droptop Community Apps\Apps\[#CustomAppID[#CustomApp[#CustomAppPosition]Num]]\Variables\Variables.inc

;-----------------------------------------

CustomAppPosition=3

;-----------------------------------------

FolderNumber=2

DropdownMenuWidth=#DropdownSubMenuWidth#

CloseMenu=[!SetVariable ActiveTray 0 "Droptop\DropdownBar"][!HideGroup Tray][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup SysTray "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]

Action0=#CloseMenu#[#ItemAction[#*CURRENTSECTION*]]

NumberOfDividers=0

;-----------------------------------------

[InfoStyle]
Text=[#ItemText[##CURRENTSECTION#]]
LeftMouseDownAction=#Action0#
Hidden=(#NumberOfItems#>=[##CURRENTSECTION#]?0:1)

[IconStyle]
ImageName=#CURRENTPATH#Icons\#FolderNumber#\[##CURRENTSECTION#]Icon.png
W=#IconW#
H=#IconW#
Hidden=(#NumberOfItems#>=[##CURRENTSECTION#]?0:1)

;-----------------------------------------

[1]
Meter=String
MeterStyle=InfoStyle
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)

[2]
Meter=String
MeterStyle=InfoStyle

[3]
Meter=String
MeterStyle=InfoStyle

[4]
Meter=String
MeterStyle=InfoStyle

[5]
Meter=String
MeterStyle=InfoStyle

[6]
Meter=String
MeterStyle=InfoStyle

[7]
Meter=String
MeterStyle=InfoStyle

[8]
Meter=String
MeterStyle=InfoStyle

[9]
Meter=String
MeterStyle=InfoStyle

[10]
Meter=String
MeterStyle=InfoStyle

;-----------------------------------------

[1Icon]
Meter=Image
MeterStyle=IconStyle
Y=[1:Y]

[2Icon]
Meter=Image
MeterStyle=IconStyle

[3Icon]
Meter=Image
MeterStyle=IconStyle

[4Icon]
Meter=Image
MeterStyle=IconStyle

[5Icon]
Meter=Image
MeterStyle=IconStyle

[6Icon]
Meter=Image
MeterStyle=IconStyle

[7Icon]
Meter=Image
MeterStyle=IconStyle

[8Icon]
Meter=Image
MeterStyle=IconStyle

[9Icon]
Meter=Image
MeterStyle=IconStyle

[10Icon]
Meter=Image
MeterStyle=IconStyle