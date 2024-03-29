[Rainmeter]
Group=Tray | Folders | Submenus | SettingsMenu | SettingsMenu3 | SM1 | SM2 | SM3

[Variables]

SettingsMenuNumber=1.3.1

; -------------------------

Slider1=1
Slider2=2
Slider3=3
Slider4=4

SliderText1=1
SliderText2=2
SliderText3=3
SliderText4=4

; -------------------------

SliderColorMode1=1
SliderColorMode2=1
SliderColorMode3=1
SliderColorMode4=0

SliderColorMode=0

; -------------------------

SliderMin2.1=0
SliderMin2.2=0
SliderMin2.3=0
SliderMin2.4=0

SliderMin3.1=0
SliderMin3.2=0
SliderMin3.3=0
SliderMin3.4=50

SliderMin4.1=0
SliderMin4.2=0
SliderMin4.3=0
SliderMin4.4=0

SliderMin5.1=0
SliderMin5.2=0
SliderMin5.3=0
SliderMin5.4=50

SliderMin6.1=0
SliderMin6.2=0
SliderMin6.3=0
SliderMin6.4=0

SliderMin7.1=0
SliderMin7.2=0
SliderMin7.3=0
SliderMin7.4=50

SliderMin7.1=0
SliderMin7.2=0
SliderMin7.3=0
SliderMin7.4=0

; -------------------------

Selected=1

Color2.1=TopBarBGColor1
Color2.2=TopBarBGColor2
Color2.3=TopBarBGColor3
Opacity2.1=TopBarOpacity1
Opacity2.2=BLANK

Color3.1=TopBarFontColor1
Color3.2=TopBarHomeIconColor
Color3.3=TopBarAssistantIconTint1
Opacity3.1=TopBarTitleOpacity
Opacity3.2=BLANK

Color4.1=DropdownBGColor1
Color4.2=BLANK
Color4.3=BLANK
Opacity4.1=DropdownMenuOpacity1
Opacity4.2=BLANK

Color5.1=DropdownFontColor1
Color5.2=BLANK
Color5.3=BLANK
Opacity5.1=DropdownItemOpacity
Opacity5.2=BLANK

Color6.1=DropdownItemHL
Color6.2=TopBarHLColor1
Color6.3=BLANK
Opacity6.1=HighlightShapeOpacity
Opacity6.2=BLANK

Color7.1=DropdownFontColor2
Color7.2=TopBarFontColor2
Color7.3=TopBarAssistantIconTint2
Opacity7.1=HighlightFontOpacity1
Opacity7.2=BLANK

Color8.1=HomeButtonTint
Color8.2=BLANK
Color8.3=BLANK
Opacity8.1=TopBarTitleOpacity
Opacity8.2=BLANK

; -------------------------

SliderPartition1=[RedParititonCalc]
SliderPartition2=[GreenParititonCalc]
SliderPartition3=[BlueParititonCalc]

SliderPartition4=[#[#Opacity[#SettingsMenuIndex].1]]

; -------------------------

SliderOutput1=[#*SliderPartition1*],[#*SliderPartition2*],[#*SliderPartition3*]
SliderOutput2=[#*SliderPartition1*],[#*SliderPartition2*],[#*SliderPartition3*]
SliderOutput3=[#*SliderPartition1*],[#*SliderPartition2*],[#*SliderPartition3*]

SliderOutput4=[SliderMouseXCalc]

; -------------------------

SliderColor1=255,0,0
SliderColor2=0,255,0
SliderColor3=0,0,255

SliderColor4=200,200,200

; -------------------------

SliderActive=0

; ---

SliderColorAction0=[!SetVariableGroup [#Opacity[#SettingsMenuIndex].1] [#*SliderPartition4*] "DroptopSuite"][!SetVariableGroup [#Opacity[#SettingsMenuIndex].2] [#*SliderPartition4*] "DroptopSuite"][!WriteKeyValue Variables [#Opacity[#SettingsMenuIndex].1] [#*SliderPartition4*] "#@#Themes\#ThemeNum#Settings.inc"][!WriteKeyValue Variables [#Opacity[#SettingsMenuIndex].2] [#*SliderPartition4*] "#@#Themes\#ThemeNum#Settings.inc"][!UpdateGroup DroptopSuite]

SliderColorAction1=[!SetVariableGroup [#Color[#SettingsMenuIndex].1] "[#SliderOutput[#*Selected*]]" "DroptopSuite"][!SetVariableGroup [#Color[#SettingsMenuIndex].2] "[#SliderOutput[#*Selected*]]" "DroptopSuite"][!SetVariableGroup [#Color[#SettingsMenuIndex].3] "[#SliderOutput[#*Selected*]]" "DroptopSuite"][!WriteKeyValue Variables [#Color[#SettingsMenuIndex].1] "[#SliderOutput[#*Selected*]]" "#@#Themes\#ThemeNum#Settings.inc"][!WriteKeyValue Variables [#Color[#SettingsMenuIndex].2] "[#SliderOutput[#*Selected*]]" "#@#Themes\#ThemeNum#Settings.inc"][!WriteKeyValue Variables [#Color[#SettingsMenuIndex].3] "[#SliderOutput[#*Selected*]]" "#@#Themes\#ThemeNum#Settings.inc"][!UpdateGroup DroptopSuite]

; ---

SliderDeactivateAction0=[!SetOption [#*CURRENTSECTION*] FillColor "Fill Color [#SliderColor[##*CURRENTSECTION*#]],75"][!SetOption [#*CURRENTSECTION*] KnobColor "Fill Color 255,255,255,185"]

SliderDeactivateAction1=#OptionChanged#[!SetVariable SliderActive 0][#SliderColorAction[#*SliderColorMode*]][!DisableMeasure SliderMouseXCalc]

; -------------------------

ChangeAction2=[!SetVariableGroup TopBarBGColor1 "#TopBarBGColor1#" "DroptopSuite"][!SetVariableGroup TopBarBGColor2 "#TopBarBGColor1#" "DroptopSuite"][!SetVariableGroup TopBarBGColor3 "#TopBarBGColor1#" "DroptopSuite"][!UpdateGroup DroptopSuite]
ChangeAction3=[!Refresh "Droptop\DropdownBar"]
ChangeAction4=[]
ChangeAction5=[!DeactivateConfig]
ChangeAction6=[!DeactivateConfig]
ChangeAction7=[!DeactivateConfig]

; -------------------------

[RedParititon]
Measure=String
String=[#[#Color[#SettingsMenuIndex].1]]
RegExpSubstitute=1
Substitute="^(.*),(.*),(.*)$":"\1"
OnChangeAction=[!UpdateMeasure RedParititonCalc]
Group=ColorVars | MouseMove

[GreenParititon]
Measure=String
String=[#[#Color[#SettingsMenuIndex].1]]
RegExpSubstitute=1
Substitute="^(.*),(.*),(.*)$":"\2"
OnChangeAction=[!UpdateMeasure GreenParititonCalc]
Group=ColorVars | MouseMove

[BlueParititon]
Measure=String
String=[#[#Color[#SettingsMenuIndex].1]]
RegExpSubstitute=1
Substitute="^(.*),(.*),(.*)$":"\3"
OnChangeAction=[!UpdateMeasure BlueParititonCalc]
Group=ColorVars | MouseMove

;---

[RedParititonCalc]
Measure=Calc
Formula=([RedParititon]>255?255:([RedParititon]<0?0:[RedParititon]))
DynamicVariables=1
UpdateDivider=-1
Group=ColorVars | MouseMove
MaxValue=255

[GreenParititonCalc]
Measure=Calc
Formula=([GreenParititon]>255?255:([GreenParititon]<0?0:[GreenParititon]))
DynamicVariables=1
UpdateDivider=-1
Group=ColorVars | MouseMove

[BlueParititonCalc]
Measure=Calc
Formula=([BlueParititon]>255?255:([BlueParititon]<0?0:[BlueParititon]))
DynamicVariables=1
UpdateDivider=-1
Group=ColorVars | MouseMove

;---

[MeasureMouseX]
Measure=Plugin
Plugin=MouseXY
Dimension=X
Group=MouseMove

[SliderMouseXCalc]
Measure=Calc
Formula=Round(Clamp(((MeasureMouseX-[#CURRENTCONFIGX]-#DropdownHLOffsetX#-#DropdownItemHeight#-2)/(((#DropdownMenuWidth#-((#DropdownItemHeight#+#DropdownHLOffsetX#+2)*2))/255))),[#SliderMin[#SettingsMenuIndex].[#Selected]],255),0)
OnUpdateAction=[!SetVariable SliderPartition#Selected# [#CURRENTSECTION#]][!SetOption SliderText#Selected# Text "[#CURRENTSECTION#]"][!SetVariable [#[#Color[#SettingsMenuIndex].1]] "[#SliderOutput[#Selected]]"][!SetVariable [#[#Color[#SettingsMenuIndex].2]] "[#SliderOutput[#Selected]]"][!SetVariable [#[#Color[#SettingsMenuIndex].3]] "[#SliderOutput[#Selected]]"][!SetOption #SettingsMenuIndex#Icon ImageTint "#SliderPartition1#,#SliderPartition2#,#SliderPartition3#" "Droptop\Other\SettingsMenu\SettingsMenu2"][!Delay 10][!UpdateMeasureGroup MouseMove][!UpdateMeterGroup MouseMove][!UpdateMeter #SettingsMenuIndex#Icon "Droptop\Other\SettingsMenu\SettingsMenu2"][!Redraw "Droptop\Other\SettingsMenu\SettingsMenu2"][!Redraw]
DynamicVariables=1
Disabled=1
Group=MouseMove

; -------------------------

[Background]
Meter=Shape
MeterStyle=BackgroundStyle
Shape=Rectangle #DropdownMenuCutout#,#DropdownMenuCutout#,(#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2)),(#DropdownItemHeight#*#NumberOfItems#+(1.5*#DroptopSize#)+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(((#DividerSpace#*2)+#DividerHeight#)*#NumberOfDividers#)-(#DividerHeight#*#NumberOfDividers#)-(#DropdownMenuCutout#*2)),#DropdownBGCorner# | Fill Color #DropdownBGColor1#,(#DropdownMenuOpacity1#<1?1:#DropdownMenuOpacity1#) | StrokeWidth #DropdownStrokeWidth# | Stroke Color #DropdownStrokeColor#
DynamicVariables=1
MouseLeaveAction=[!SetOptionGroup SliderBar FillColor ""][!SetOptionGroup SliderBar KnobColor ""][!UpdateMeterGroup SliderBar][!Redraw]

[InfoStyle]
StringAlign=CenterCenter
FontColor=0,0,0,185
FontFace=[#FontName[#AltFont[#LanguageNum]]]
FontSize=#DropdownItemFontSize#
InlineSetting=
FontWeight=#FontWeight#
Padding=0,0,0,0
AntiAlias=#DropdownAntiAlias#
LeftMouseDownAction=
MouseOverAction=
MouseLeaveAction=
DynamicVariables=1
ClipString=1
X=((#DropdownMenuCutout#+#DropdownHLOffsetX#)+((#DropdownMenuWidth#-((#DropdownMenuCutout#+#DropdownHLOffsetX#)*2)-(#DropdownItemHeight#*2))*([#SliderPartition[##CURRENTSECTION#]]/255))+#DropdownItemHeight#)
Y=([Slider[##CURRENTSECTION#]:Y]+(#DropdownItemHeight#/2))
W=(#DropdownItemHeight#*2)
H=#DropdownItemHeight#
FontColor=0,0,0,185
Text=[#SliderPartition[##CURRENTSECTION#]]
Group=MouseMove | SliderText

[SliderStyle]
Shape=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),0,(#DropdownMenuWidth#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | StrokeWidth 1 | Stroke Color 0,0,0,55 | Extend FillColor
Shape2=Rectangle ((#DropdownMenuCutout#+#DropdownHLOffsetX#)+((#DropdownMenuWidth#-((#DropdownMenuCutout#+#DropdownHLOffsetX#)*2)-(#DropdownItemHeight#*2))*([#SliderPartition[##CURRENTSECTION#]]/255))+1),1,((#DropdownItemHeight#*2)-2),(#DropdownItemHeight#-2),#DropdownHighlightCorner# | StrokeWidth 1 | Stroke Color 0,0,0,55 | Extend KnobColor
FillColor=Fill Color [#SliderColor[##CURRENTSECTION#]],75
KnobColor=Fill Color 255,255,255,185
LeftMouseDownAction=[!SetVariable SliderActive 1][!SetVariable Selected [##CURRENTSECTION#]][!SetVariable SliderColorMode [#SliderColorMode[##CURRENTSECTION#]]][!EnableMeasure SliderMouseXCalc][!UpdateMeasureGroup MouseMove][!UpdateMeterGroup MouseMove][!UpdateMeter #CURRENTSECTION#]
LeftMouseUpAction=[#SliderDeactivateAction[#SliderActive]][!UpdateMeter #CURRENTSECTION#]
MouseLeaveAction=[#SliderDeactivateAction[#SliderActive]][!UpdateMeter #CURRENTSECTION#]
MouseOverAction=[!SetOptionGroup SliderBar FillColor ""][!SetOptionGroup SliderBar KnobColor ""][!SetOption #CURRENTSECTION# FillColor "Fill Color [#SliderColor[##CURRENTSECTION#]],255"][!UpdateMeter #CURRENTSECTION#][!SetOption #CURRENTSECTION# KnobColor "Fill Color 255,255,255,245"][!UpdateMeterGroup SliderBar][!Redraw]
DynamicVariables=1
X=1
Y=R
Group=MouseMove | SliderBar

; -------------------------

[1]
FontColor=0,0,0,0

[2]
FontColor=0,0,0,0

[3]
FontColor=0,0,0,0

[4]
FontColor=0,0,0,0

; -------------------------

[Slider1]
Meter=Shape
MeterStyle=SliderStyle
X=1
Y=[1:Y]

[Slider2]
Meter=Shape
MeterStyle=SliderStyle

[Slider3]
Meter=Shape
MeterStyle=SliderStyle

; -------------------------

[4]
Y=(#DividerSpace#*2)R

[4Icon]
Y=(#DividerSpace#*2)R

[Divider1]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*1)+(#DropdownItemHeight#*3)+2)

[Slider4]
Meter=Shape
MeterStyle=SliderStyle
Y=(#DividerSpace#*2)R

; -------------------------

[SliderText1]
Meter=String
MeterStyle=InfoStyle

[SliderText2]
Meter=String
MeterStyle=InfoStyle

[SliderText3]
Meter=String
MeterStyle=InfoStyle

[SliderText4]
Meter=String
MeterStyle=InfoStyle

[5]
MeterStyle=

[5Icon]
MeterStyle=

[6]
MeterStyle=

[6Icon]
MeterStyle=

[7]
MeterStyle=

[7Icon]
MeterStyle=

[8]
MeterStyle=

[8Icon]
MeterStyle=

[9]
MeterStyle=

[9Icon]
MeterStyle=

[10]
MeterStyle=

[10Icon]
MeterStyle=

[11]
MeterStyle=

[11Icon]
MeterStyle=

[12]
MeterStyle=

[12Icon]
MeterStyle=

[13]
MeterStyle=

[13Icon]
MeterStyle=

[14]
MeterStyle=

[14Icon]
MeterStyle=

[15]
MeterStyle=

[15Icon]
MeterStyle=

[16]
MeterStyle=

[16Icon]
MeterStyle=

[17]
MeterStyle=

[17Icon]
MeterStyle=

[18]
MeterStyle=

[18Icon]
MeterStyle=

[19]
MeterStyle=

[19Icon]
MeterStyle=

[20]
MeterStyle=

[20Icon]
MeterStyle=

[21]
MeterStyle=

[21Icon]
MeterStyle=

[22]
MeterStyle=

[22Icon]
MeterStyle=