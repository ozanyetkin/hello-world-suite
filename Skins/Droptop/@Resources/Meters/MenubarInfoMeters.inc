[Rainmeter]
MouseActionCursor=Arrow
OnFocusAction=[!SetVariable Focused 1 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure CompareFocused "Droptop\Other\BackgroundProcesses"]
OnUnfocusAction=[!SetVariable Focused 0 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure MeasureIsFullScreen "Droptop\Other\BackgroundProcesses"]
OnRefreshAction=[!UpdateMeasureGroup Scrollbar][!UpdateMeterGroup Scrollbar]
RightMouseDownAction=[]
SkinWidth=(#DropdownMenuWidth#+#SysAppMenuXOffset#+#SysAppMenuWOffset#+2)
LeftMouseDownAction=[]
Update=-1

DefaultKeepOnScreen=1

[Variables]
MenuBlur=#DropdownMenuBlur#

LuaLoc=#@#Scripts\Lua\DropScroll.lua

;-----------------------------------
Padding0=(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),#DropdownItemPaddingY#,#DropdownItemPadding2#,(#DropdownItemPaddingY#*-1)
Padding1=#DropdownItemPadding2#,#DropdownItemPaddingY#,(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),(#DropdownItemPaddingY#*-1)
;---
Padding0B=#DropdownItemPadding1#,#DropdownItemPaddingY#,#DropdownItemPadding2#,(#DropdownItemPaddingY#*-1)
Padding1B=(#DropdownItemPadding1#*2),#DropdownItemPaddingY#,#DropdownNoIconPadding#,(#DropdownItemPaddingY#*-1)
;-----------------------------------

MaxItem=20
ScrollTracker=#MaxItem#

1Scroll=1
2Scroll=2
3Scroll=3
4Scroll=4
5Scroll=5
6Scroll=6
7Scroll=7
8Scroll=8
9Scroll=9
10Scroll=10
11Scroll=11
12Scroll=12
13Scroll=13
14Scroll=14
15Scroll=15
16Scroll=16
17Scroll=17
18Scroll=18
19Scroll=19
20Scroll=20

ScrollUpAction0=
ScrollUpAction1=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!SetVariable ScrollTracker ([#*ScrollTracker*]-([#*ScrollTracker*]-#MaxItem#<=#MaxItem#?([#*ScrollTracker*]-#MaxItem#):#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-#MaxItem#)][!#Hide#Group SM[#*MenubarInfo.NextFolder*]][!SetOptionGroup Items FontColor "[#*DropdownFontColor1*],[#*DropdownItemOpacity*]"][!SetOptionGroup Icons FontColor "[#*DropdownFontColor1*],[#*DropdownItemOpacity*]"][!SetOptionGroup Arrows FillColor "Fill Color [#*DropdownFontColor1*],[#*DropdownItemOpacity*]"][!HideMeter HighlightBackground][!HideMeter HighlightSelected][!UpdateMeasure *][!UpdateMeter *][!Redraw]

ScrollDownAction0=
ScrollDownAction1=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!SetVariable ScrollTracker ([#*ScrollTracker*]+([#*ScrollTracker*]+#MaxItem#>=[&GetMenuInfo:Count([#*FolderIndex*])]?([&GetMenuInfo:Count([#*FolderIndex*])]-[#*ScrollTracker*]):#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!SetOptionGroup Items FontColor "[#*DropdownFontColor1*],[#*DropdownItemOpacity*]"][!SetOptionGroup Icons FontColor "[#*DropdownFontColor1*],[#*DropdownItemOpacity*]"][!SetOptionGroup Arrows FillColor "Fill Color [#*DropdownFontColor1*],[#*DropdownItemOpacity*]"][!#Hide#Group SM[#*MenubarInfo.NextFolder*]][!HideMeter HighlightBackground][!HideMeter HighlightSelected][!UpdateMeasure *][!UpdateMeter *][!Redraw]

[BlurBehind]
Measure=Plugin
Plugin=FrostedGlass
BlurEnabled=#DropdownMenuBlur#
Type=[#BlurType[#BlurTypeNum]]
Border=[#Shadows[#DropdownMenuShadow]]
Corner=[#BlurCorner[#DropdownRoundCorners]]

[MeasureActionTimer1]
Measure=Plugin
Plugin=ActionTimer
Group=Animation
ActionList1=Wait [#FolderMouseOverTime[#FolderMouseOverTimeNum]]|StopBlock1|FolderMouseOver|StopBlock0
FolderMouseOver=
StopBlock1=[!SetVariable StopBlock 1][!UpdateMeterGroup Items]
StopBlock0=[!SetVariable StopBlock 0][!UpdateMeterGroup Items]
DynamicVariables=1
IgnoreWarnings=1
Disabled=1

[1Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[2Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[3Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[4Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[5Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[6Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[7Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[8Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[9Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[10Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[11Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[12Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[13Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[14Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[15Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[16Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[17Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[18Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[19Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

[20Scroll]
Measure=Calc
Formula=([##CURRENTSECTION#]+([#ScrollTracker]-#MaxItem#))
DynamicVariables=1

;----------------------------------------------------
; Styles
;----------------------------------------------------

[InfoStyle]
StringAlign=#TextDirection#Center
FontFace=[#FontName[#AltFont[#LanguageNum]]]
FontSize=#DropdownItemFontSize#
FontColor=#DropdownFontColor1#,#DropdownItemOpacity#
InlineSetting=CharacterSpacing | #DropdownCharacterSpacing#
InlineSetting2=[#DropdownTextShadow[#DropdownFontShadow][#ChamLum1]]
StringEffect=#DropdownStringEffect#
FontEffectColor=#DropdownFontEffectColor#
X=(1+(#DropdownMenuWidth#*#RTLText#)+#SysAppMenuXOffset#)
Y=R
W=(#DropdownMenuWidth#+#SysAppMenuWOffset#-#DropdownItemPadding2#-#DropdownItemPadding1#+(#DropdownItemPadding1#*#HideIcons#))
H=#DropdownItemHeight#
Text=[&GetMenuInfo:Text(#MenubarInfo.ItemName#)]
MouseScrollDownAction=[!SetVariable Scrollable (#ScrollTracker#>=[&GetMenuInfo:Count([#FolderIndex])]?0:1)][#ScrollDownAction[#Scrollable]]
MouseScrollUpAction=[!SetVariable Scrollable (#ScrollTracker#<=#MaxItem#?0:1)][#ScrollUpAction[#Scrollable]]
FontWeight=#FontWeight#
Padding=[#Padding[#RTLText]]
AntiAlias=#DropdownAntiAlias#
Hidden=(#NumberOfItems#>=#CURRENTSECTION#?0:1)
DynamicVariables=1
ClipString=1
Group=Items

[GetMenuInfo]
Measure=Plugin
Plugin=MenubarInfo
MenuUpdateAction=[!UpdateMeter *][!Redraw]
MenuDestroyAction=[!UpdateMeter *][!Redraw]

[IsSeparator0]

[IsSeparator1]
InlinePattern2=—
InlineSetting2=Color | #DropdownFontColor1#,(#DropdownItemOpacity#/3)
Text=————————————————————————————————————————————————————————
Prefix=""
ClipString=0
LeftMouseDownAction=
MouseOverAction=[]
MouseLeaveAction=[]
Padding=0,0,0,0
X=-10

[IsDisabled0]

[IsDisabled1]
InlineSetting2=Color | #DropdownFontColor1#,(#DropdownItemOpacity#/3)
LeftMouseDownAction=[]
MouseOverAction=[]
MouseLeaveAction=[]
Group=Disabled

[FolderStyle0]
LeftMouseDownAction=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!SetVariable ActiveAll 0 "Droptop\DropdownBar"][!SetVariable ActiveTray 0 "Droptop\DropdownBar"][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!HideGroup Tray][!DeactivateConfigGroup Tray][!UpdateMeter * "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!CommandMeasure GetMenuInfo "Command #MenubarInfo.CommandIndex#"]
MouseOverAction=[!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Icon FontColor "#*DropdownFontColor2*#,(#*HighlightFontOpacity1*#-(#*HighlightFontOpacity1*#*#HideIcons#))"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!ShowMeterGroup Highlight][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#Arrow][!Redraw]
MouseLeaveAction=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!HideMeter HighlightBackground][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Icon FontColor "#*DropdownFontColor1*#,(#DropdownItemOpacity#-(#DropdownItemOpacity#*#HideIcons#))"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!UpdateMeter #CURRENTSECTION#][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#Arrow][!Redraw]

[FolderStyle1]
LeftMouseDownAction=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!WriteKeyValue Variables SelectedFolderX [#CURRENTCONFIGX] "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!WriteKeyValue Variables SelectedFolderY [#CurrentSubFolder#:Y] "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!WriteKeyValue Variables NumberOfItems "[&GetMenuInfo:Count(#MenubarInfo.FolderIndex#)]" "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!WriteKeyValue Variables FolderIndex "#MenubarInfo.FolderIndex#" "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!WriteKeyValue Variables CommandIndex "#MenubarInfo.CommandIndex#" "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!ShowMeter HighlightSelected][!SetVariable HighlightSelectedY [#CURRENTSECTION#:Y]][!Hide "#CURRENTCONFIG#\Folder"][!HideGroup "Submenus"][!HideGroup "SM#MenubarInfo.NextFolder#"][!DeactivateConfig "#CURRENTCONFIG#\Folder"][!DeactivateConfigGroup "Submenus"][!DeactivateConfigGroup SM#MenubarInfo.NextFolder#][!ActivateConfig "#CURRENTCONFIG#\Folder" "Folder0#MenubarInfo.NextFolder#.ini"][!CommandMeasure GetMenuInfo "get [&GetMenuInfo:WindowInfo()]" "#CURRENTCONFIG#\Folder"][!Move ([#CURRENTCONFIGX]+#DropdownMenuWidth#+#DropdownSubMenuXOffset#) ([#CURRENTCONFIGY]+[#CURRENTSECTION#:Y]-#DropdownItemYOffset#-(#DropdownStrokeWidth#-(#DropdownStrokeWidth#%1))-1) "#CURRENTCONFIG#\Folder"][!#Show# "#CURRENTCONFIG#\Folder"][!UpdateMeter HighlightSelected][!Redraw]
MouseOverAction=[!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetOption MeasureActionTimer#AnimationOFF# FolderMouseOver """[!WriteKeyValue Variables SelectedFolderX [#CURRENTCONFIGX] "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!WriteKeyValue Variables SelectedFolderY [#CurrentSubFolder#:Y] "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!DeactivateConfig "#CURRENTCONFIG#\Folder"][!DeactivateConfigGroup "Submenus"][!DeactivateConfigGroup SM#MenubarInfo.NextFolder#][!WriteKeyValue Variables NumberOfItems "[&GetMenuInfo:Count(#MenubarInfo.FolderIndex#)]" "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!WriteKeyValue Variables FolderIndex "#MenubarInfo.FolderIndex#" "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!WriteKeyValue Variables CommandIndex "#MenubarInfo.CommandIndex#" "#SKINSPATH##CURRENTCONFIG#\Folder\Folder0#MenubarInfo.NextFolder#.ini"][!ShowMeter HighlightSelected][!SetVariable HighlightSelectedY [#CURRENTSECTION#:Y]][!Hide "#CURRENTCONFIG#\Folder"][!HideGroup "Submenus"][!HideGroup "SM#MenubarInfo.NextFolder#"][!ActivateConfig "#CURRENTCONFIG#\Folder" "Folder0#MenubarInfo.NextFolder#.ini"][!CommandMeasure GetMenuInfo "get [&GetMenuInfo:WindowInfo()]" "#CURRENTCONFIG#\Folder"][!Move ([#CURRENTCONFIGX]+#DropdownMenuWidth#+#DropdownSubMenuXOffset#) ([#CURRENTCONFIGY]+[#CURRENTSECTION#:Y]-#DropdownItemYOffset#-(#DropdownStrokeWidth#-(#DropdownStrokeWidth#%1))-1) "#CURRENTCONFIG#\Folder"][!#Show# "#CURRENTCONFIG#\Folder"][!UpdateMeter HighlightSelected][!Redraw]"""][!UpdateMeasure MeasureActionTimer#AnimationOFF#][!CommandMeasure MeasureActionTimer#AnimationOFF# "Execute 1"]   [!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Icon FontColor "#*DropdownFontColor2*#,(#*HighlightFontOpacity1*#-(#*HighlightFontOpacity1*#*#HideIcons#))"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!ShowMeterGroup Highlight][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#Arrow][!Redraw]
MouseLeaveAction=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!HideMeter HighlightBackground][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Icon FontColor "#*DropdownFontColor1*#,(#DropdownItemOpacity#-(#DropdownItemOpacity#*#HideIcons#))"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!UpdateMeter #CURRENTSECTION#][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#Arrow][!Redraw]
; =(#ApplicationX#+#DropdownMenuWidth#+#DropdownSubMenuXOffset#+#BarXposOffset#+[#WORKAREAX[#DroptopDisplayMonitor]])

@IncludeArrowStyle=#SKINSPATH#Droptop\@Resources\Meters\ArrowStyle\ArrowStyle#DropdownArrowStyle#.ini

[IconStyle]
StringAlign=#TextDirection#Center
FontColor=#DropdownFontColor1#,#DropdownItemOpacity#
FontFace=Segoe UI
FontSize=#DropdownItemFontSize#
; InlineSetting=CharacterSpacing | #DropdownCharacterSpacing#
InlineSetting=[#DropdownTextShadow[#DropdownFontShadow][#ChamLum1]]
StringEffect=#DropdownStringEffect#
FontEffectColor=#DropdownFontEffectColor#
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#)+#SysAppMenuXOffset#+(2*#DroptopSize#))
Y=R
W=(#DropdownMenuWidth#+#SysAppMenuWOffset#-#DropdownItemPadding2#-#DropdownItemPadding1#+(#DropdownItemPadding1#*#HideIcons#))
H=#DropdownItemHeight#
Text=[#MenubarInfoCheckmark[&GetMenuInfo:IsChecked(#MenubarInfo.ArrowPosition#)]]
Padding=#DropdownIconPadding#,0,#DropdownIconPadding#,0
AntiAlias=#DropdownAntiAlias#
Hidden=(#NumberOfItems#>=[##CURRENTSECTION#]?0:1)
DynamicVariables=1
Group=Icons

[MenuFolderArrowStyle]
Hidden=(([&GetMenuInfo:IsSubmenu(#MenubarInfo.ArrowPosition#)]-1)*-1)
Y=[[##CURRENTSECTION#]:Y]
DynamicVariables=1
Hidden=0
Group=Arrows

[BackgroundStyle]
LeftMouseUpAction=[]

;----------------------------------------------------
; Background Meters
;----------------------------------------------------

[Background]
Meter=Shape
MeterStyle=BackgroundStyle
Shape=Rectangle #DropdownMenuCutout#,(#DropdownMenuShapeOffsetH#+#DropdownMenuCutout#),(#DropdownMenuWidth#+#SysAppMenuWOffset#+2-(#DropdownMenuCutout#*2)),(#DropdownItemHeight#*([&GetMenuInfo:Count([#FolderIndex])]>#MaxItem#?#MaxItem#:[&GetMenuInfo:Count([#FolderIndex])]+#MenubarInfo.Additional#)+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(#DropdownMenuLandingHeight#-(#DropdownMenuLandingHeight#*([&GetMenuInfo:Count([#FolderIndex])]>#MaxItem#?#HideLanding#:1)))+(((#DividerSpace#*2)+#DividerHeight#)*#NumberOfDividers#)-#DropdownMenuCutout#),#DropdownBGCorner# | Fill Color #DropdownBGColor1#,(#DropdownMenuOpacity1#<1?1:#DropdownMenuOpacity1#) | StrokeWidth #DropdownStrokeWidth# | Stroke Color #DropdownStrokeColor#
; Shape2=#FlatTopShape#
; Shape3=Combine Shape | Union Shape2
X=#SysAppMenuXOffset#
DynamicVariables=1

;----------------------------------------------------
; Item Highlight

[HighlightBackground]
Meter=Shape
Shape=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),[#CurrentSubFolder#:Y],(#DropdownMenuWidth#+#SysAppMenuWOffset#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill Color #DropdownItemHL#,(#HighlightShapeOpacity#/#HighlightShapeOpacityDivisor1B#) | StrokeWidth 0
X=(1+#SysAppMenuXOffset#)
Group=Highlight | HL
DynamicVariables=1
Hidden=1

[HighlightSelected]
Meter=Shape
Shape=Rectangle [#HLSelectedShapeB[#HLSelectedShapeNum]]
ShapeOption=[#HLSelectedOptionB[#HLSelectedShapeNum]]
X=(1+#SysAppMenuXOffset#)
Y=#HighlightSelectedY#
Group=HighlightSelected
DynamicVariables=1
Hidden=1

;----------------------------------------------------
; Item Names
;----------------------------------------------------

[1]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+((#DropdownItemHeight#/2)*#MenubarInfo.Additional#)+(((#DropdownItemHeight#/2)+(#DividerSpace#*2))*#NumberOfDividers#))

[2]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[3]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[4]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[5]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[6]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[7]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[8]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[9]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[10]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[11]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[12]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[13]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[14]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[15]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[16]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[17]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[18]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[19]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

[20]
Meter=String
MeterStyle=[#MenubarInfo.Style[#MenubarInfo.Type]]

;----------------------------------------------------
; Icons
;----------------------------------------------------

[1Icon]
Meter=String
MeterStyle=IconStyle
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)

[2Icon]
Meter=String
MeterStyle=IconStyle

[3Icon]
Meter=String
MeterStyle=IconStyle

[4Icon]
Meter=String
MeterStyle=IconStyle

[5Icon]
Meter=String
MeterStyle=IconStyle

[6Icon]
Meter=String
MeterStyle=IconStyle

[7Icon]
Meter=String
MeterStyle=IconStyle

[8Icon]
Meter=String
MeterStyle=IconStyle

[9Icon]
Meter=String
MeterStyle=IconStyle

[10Icon]
Meter=String
MeterStyle=IconStyle

[11Icon]
Meter=String
MeterStyle=IconStyle

[12Icon]
Meter=String
MeterStyle=IconStyle

[13Icon]
Meter=String
MeterStyle=IconStyle

[14Icon]
Meter=String
MeterStyle=IconStyle

[15Icon]
Meter=String
MeterStyle=IconStyle

[16Icon]
Meter=String
MeterStyle=IconStyle

[17Icon]
Meter=String
MeterStyle=IconStyle

[18Icon]
Meter=String
MeterStyle=IconStyle

[19Icon]
Meter=String
MeterStyle=IconStyle

[20Icon]
Meter=String
MeterStyle=IconStyle

;----------------------------------------------------
; Arrows

[1Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle
Y=[1:Y]

[2Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[3Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[4Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[5Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[6Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[7Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[8Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[9Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[10Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[11Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[12Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[13Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[14Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[15Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[16Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[17Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[18Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[19Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

[20Arrow]
Meter=Shape
MeterStyle=ArrowStyle | MenuFolderArrowStyle

;----------------------------------------------------
; Scrollbar
;----------------------------------------------------

[AnalyzeTotal]
Measure=Calc
Formula=#NumberOfItems#
IfCondition=#NumberOfItems# > #MaxItem#
IfTrueAction=[!WriteKeyValue Variables AboveTotal 1][!SetVariable AboveTotal 1][!EnableMeasureGroup Scrollbar][!ShowMeterGroup Scrollbar][!UpdateMeasure *][!UpdateMeter *][!Redraw]
DynamicVariables=1
Group=Scrollbar

[ScrollbarTop]
Meter=Image
X=3
Y=(#DropdownIconYoffset#-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#-1)
UpdateDivider=-1
Group=Scrollbar

[Size]
Measure=Calc
Formula=((#DropdownItemHeight#*#MaxItem#)-#DropdownIconYoffset#)
UpdateDivider=-1
Group=Scrollbar

[ScrollH]
Measure=Calc
Formula=Size * (#MaxItem# / (AnalyzeTotal = 0 ? 1 : AnalyzeTotal))
Group=Scrollbar
Disabled=0

[ScrollbarScript]
Measure=Script
ScriptFile=#LuaLoc#
UpdateDivider=-1
Group=Scrollbar

[CurrentPos]
Meter=Shape
Shape=Rectangle 0,0,(3*#DroptopSize#),([ScrollH]<1?1:[ScrollH]),2 | Fill Color #DropdownFontColor1#,155 | StrokeWidth 0 | StrokeColor #DropdownBGColor1#,55
X=(#DropdownMenuWidth#-(3*#DroptopSize#)-(#DropdownStrokeWidth#/2))
Y=(#DropdownIconYoffset#-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+1)
DynamicVariables=1
Group=ScrollBar | Items
Hidden=1

;-------------------------------------------

; [OpenFolder]
; Meter=Image
; ImageName=#@#Icons\Fixed\Medium\dot.png
; ImageTint=#DropdownFontColor1#,#DropdownItemOpacity#
; ImageAlpha=55
; X=(8*#DroptopSize#)
; Y=(#DropdownIconYoffset#+(#DropdownItemHeight#*([&GetMenuInfo:Count([#FolderIndex])]>#MaxItem#?#MaxItem#:[&GetMenuInfo:Count([#FolderIndex])]+#MenubarInfo.Additional#))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+(((#DividerSpace#*2)+#DividerHeight#)*#NumberOfDividers#)+#DropdownItemYOffset#+#DropdownBottomButtonOffset#)
; H=(16*#DroptopSize#)
; LeftMouseDownAction=["#DownloadsLoc#"][!SetVariable ActiveTray 0 "Droptop\DropdownBar"][!HideGroup Tray][!UpdateMeterGroup SysTray "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
; MouseOverAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\open.png"][!SetOption #CURRENTSECTION# ImageAlpha #DropdownItemOpacity#][!UpdateMeter #CURRENTSECTION#][!Redraw]
; MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\dot.png"][!SetOption #CURRENTSECTION# ImageAlpha 55][!UpdateMeter #CURRENTSECTION#][!Redraw]
; DynamicVariables=1
; UpdateDivider=-1
; Hidden=#HideLanding#

[DownArrow]
Meter=Shape
Shape=Rectangle (-5*#DroptopSize#),(-1*#DroptopSize#),(21*#DroptopSize#),(21*#DroptopSize#),0 | Fill Color 0,0,0,0 | StrokeWidth 0
Shape2=Rectangle 0,(-1*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45 | Extend Look
Shape3=Rectangle 0,(-3*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45
Shape4=Combine Shape2 | Exclude Shape3
Look=Fill Color #DropdownFontColor1#,(#ScrollTracker#>=[&GetMenuInfo:Count([#FolderIndex])]?0:(#DropdownItemOpacity#/3))
LeftMouseDownAction=[!SetVariable ScrollTracker (#ScrollTracker#+(#ScrollTracker#+#MaxItem#>=[&GetMenuInfo:Count([#FolderIndex])]?([&GetMenuInfo:Count([#FolderIndex])]-#ScrollTracker#):#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!UpdateMeasure *][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#>=[&GetMenuInfo:Count([#FolderIndex])]?0:#DropdownItemOpacity#)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#>=[&GetMenuInfo:Count([#FolderIndex])]?0:(#DropdownItemOpacity#/3))"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#DropdownMenuWidth#-(25*#DroptopSize#))
Y=(#DropdownIconYoffset#+(#DropdownItemHeight#*([&GetMenuInfo:Count([#FolderIndex])]>#MaxItem#?#MaxItem#:0))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+(((#DividerSpace#*2)+#DividerHeight#)*#NumberOfDividers#)+#DropdownItemYOffset#+#DropdownBottomButtonOffset#)
Hidden=#HideLanding#
DynamicVariables=1

[UpArrow]
Meter=Shape
Shape=Rectangle (-5*#DroptopSize#),(-1*#DroptopSize#),(21*#DroptopSize#),(21*#DroptopSize#),0 | Fill Color 0,0,0,0 | StrokeWidth 0
Shape2=Rectangle 0,(6*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45 | Extend Look
Shape3=Rectangle 0,(8*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45
Shape4=Combine Shape2 | Exclude Shape3
Look=Fill Color #DropdownFontColor1#,(#ScrollTracker#<=#MaxItem#?0:(#DropdownItemOpacity#/3))
LeftMouseDownAction=[!SetVariable ScrollTracker (#ScrollTracker#-(#ScrollTracker#-#MaxItem#<=#MaxItem#?(#ScrollTracker#-#MaxItem#):#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-#MaxItem#)][!UpdateMeasure *][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#<=#MaxItem#?0:#DropdownItemOpacity#)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#<=#MaxItem#?0:(#DropdownItemOpacity#/3))"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#DropdownMenuWidth#-(45*#DroptopSize#))
Y=r
Hidden=#HideLanding#
DynamicVariables=1