[Rainmeter]

[Variables]
SkinVersion=4.308
SkinVersionMini=2

ExecuteAnimation0=[!CommandMeasure LoadActions "Execute 2"]
ExecuteAnimation1=[!DeactivateConfig]

@IncludeSupporter=#@#GlobalVar\Supporter.inc

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[LoadActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 150 | Update | ExportVars | Start0 | Wait 1500 | Start1 | Wait 750 | Start2 | ClickOn
ActionList2=Start3 | Rewind2 | Rewind1 | Wait 1000 | EndUpdate | Exit
Update=[!CommandMeasure MeasureRunRegistry "Run"][!WriteKeyValue Variables DPIOverride 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables DPIRescaleOFF 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables TopIconSize "Medium" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables TopIconWH 32 "#@#GlobalVar\UserSettings.inc"][!SetVariable TopIconSize Medium "Droptop\DropdownBar"][!SetVariable TopIconWH 32 "Droptop\DropdownBar"][!WriteKeyValue Variables BarXposOffset "[#BarXposOffset[#BarXposOffsetNum]]" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ZposBehavior 1 "#@#GlobalVar\UserSettings.inc"][!AutoSelectScreenGroup 1 "DroptopSuite"]
EndUpdate=

[PSRM]
Measure=Plugin
Plugin=PowershellRM
ScriptFile=#@#Scripts\Powershell\FetchVars.ps1
FetchStringCount=3
Fetch1=UpdateTitleA|Des
Fetch2=UpdateTextA|Des2
Fetch3=SayContinue|ButtonText

[Tween:M]
Measure=Script
ScriptFile=#@#Scripts\Lua\Tween\Main.lua
TweenGroup=Tweenable
Tween0=Single | Variable | TweenNode1 | 0 | 1 | 1500
Tween1=Single | Variable | TweenNode2 | 0 | 1 | 750
Tween2=Single | Variable | TweenNode3 | 0 | 1 | 750
Tween3=Single | Variable | TweenNode4 | 0 | 1 | 750
Optional0=Easing InOutExpo
Optional1=Easing OutExpo
Optional2=Easing OutExpo
Optional3=Easing OutExpo
UpdateDivider=1

[MeasureRunRegistry]
Measure=Plugin
Plugin=RunCommand
Parameter=taskkill /f /im "Droptop Rainmeter.exe" & reg add "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers" /v "#PROGRAMPATH#Rainmeter.exe" /t "REG_SZ" /d "~ HIGHDPIAWARE" & xcopy /s /e /y /f /i "#SKINSPATH#Droptop\@Resources\Fonts" "#SKINSPATH#Droptop Community Apps\@Resources\Fonts"
State=Hide
OutputType=ANSI
OutputFile=

[MeasureOSVersion]
Measure=Plugin
Plugin=SysInfo
SysInfoType=OS_VERSION
Substitute=".*Windows 10.*":"1",".*Windows 11.*":"2"
RegExpSubstitute=1
IfMatch=1
IfMatchAction=[!WriteKeyValue Variables OSVERSION 10 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables Win10Apps 1 "#@#GlobalVar\UserSettings.inc"]
IfMatch2=2
IfMatchAction2=[!WriteKeyValue Variables OSVERSION 11 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables Win10Apps 0 "#@#GlobalVar\UserSettings.inc"]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Container]
Meter=String

[Shape]
Meter=Shape
X=((#SCREENAREAWIDTH#/2-#Sec.W#/2)*#TweenNode1#)
Y=((#SCREENAREAHEIGHT#/2-#Sec.H#/2)*#TweenNode1#)
Shape=Rectangle 0,0,(#SCREENAREAWIDTH#*(1-#TweenNode1#)+#Sec.W#*#TweenNode1#),(28+(#Sec.H#-28)*#TweenNode1#),(7*#Scale#) | StrokeWidth 0 | Stroke Color 34,34,34 | Fill Color 31,31,31
Group=Tweenable
DynamicVariables=1

[Slider2:C]
Meter=Shape
X=((#SCREENAREAWIDTH#/2-#Sec.W#/2))
Y=((#SCREENAREAHEIGHT#/2-#Sec.H#/2))
Shape=Rectangle 0,0,#Sec.W#,#Sec.H#,(10*#Scale#) | StrokeWidth 0 | Fill LinearGradient FillColor
FillColor=190 | 255,255,255,0 ; 0.2 | 255,255,255,255 ; 1

[Slider:C]
Meter=Shape
X=((#SCREENAREAWIDTH#/2-#Sec.W#/2)-50*#Scale#*(1-#TweenNode2#))
Y=((#SCREENAREAHEIGHT#/2-#Sec.H#/2))
Shape=Rectangle 0,0,#Sec.W#,#Sec.H#,(10*#Scale#) | StrokeWidth 0 | Fill Color 255,255,255,(#TweenNode2#*255)
Group=Tweenable
DynamicVariables=1

[Title2]
Meter=String
Text=droptop four
X=(#Sec.P#+(13*#Scale#))
Y=#Sec.p#
FontSize=(22*#Scale#)
InlineSetting=CharacterSpacing | 1 | 0
FontColor=43B553
MeterStyle=String:S
Container=Slider:C

[Des]
Meter=String
Text=Updated to version #SkinVersion#.#SkinVersionMini#
X=r
Y=(#Sec.H#*0.4)
H=(50*#Scale#)
InlineSetting=Shadow | 0 | 0 | 1 | 255,255,255,150
MeterStyle=String:S | Header:S
Container=Slider:C

[Des2]
Meter=String
Text=Visit Github to see change notes.
X=r
Y=(10*#Scale#)R
W=(500*#Scale#)
MeterStyle=String:S | Text:S
Container=Slider:C
InlinePattern=Github
InlinePattern2=Github
InlineSetting=Color | 56,250,138
MouseOverAction=[!SetOption #CURRENTSECTION# InlineSetting2 "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# InlineSetting2 ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["https://github.com/Droptop-Four/Update/releases/tag/Update"][!Zpos 1][!KeepOnScreen 0][!Draggable 1][!ShowMeter Title2][!HideMeter Title][!CommandMeasure LoadActions "Execute 2"]

[Button]
Meter=Shape
X=r
Y=(44*#Scale#)R
Shape=Rectangle 0,0,(180*#Scale#),(40*#Scale#),(20*#Scale#) | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color 39, 174, 96
MouseOverAction=[!SetOption #CURRENTSECTION# FillColor "Fill Color 56,250,138"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FillColor "Fill Color 39,174,96"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!ActivateConfig "Droptop\DropdownBar" "DropdownBar.ini"][!Show "Droptop\DropdownBar"][!Zpos 1][!KeepOnScreen 0][!Draggable 1][!ShowMeter Title2][!HideMeter Title][!CommandMeasure LoadActions "Execute 2"]
Container=Slider:C

[ButtonText]
Meter=String
X=(180/2*#Scale#)r
Y=(21*#Scale#)r
FontSize=(15*#Scale#)
Text=Continue
StringAlign=CenterCenter
FontColor=255,255,255
InlineSetting=Shadow | 0 | 1 | 2 | 0,0,0,175
MeterStyle=String:S
Container=Slider:C

; --------------------------------- Section 2 -------------------------------- ;

[Image]
Meter=Image
ImageName=#@#Images\Setup\ThankYou.png
X=0
W=(#Sec.W#)
H=(#Sec.H#)
PreserveAspectRatio=1
ImageAlpha=(255*#TweenNode3#)
Container=Slider2:C
Group=Tweenable
DynamicVariables=1
