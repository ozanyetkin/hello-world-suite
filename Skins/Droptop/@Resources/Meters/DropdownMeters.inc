[Rainmeter]
OnFocusAction=[!SetVariable Focused 1 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure CompareFocused "Droptop\Other\BackgroundProcesses"]
OnUnfocusAction=[!SetVariable Focused 0 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure MeasureIsFullScreen "Droptop\Other\BackgroundProcesses"]
OnRefreshAction=[!Hide][!FadeDuration 105]
SkinWidth=(#DropdownMenuWidth#+2)
RightMouseDownAction=[]
MouseActionCursor=Arrow
Update=-1

[Variables]
MenuBlur=#DropdownMenuBlur#
ScrollTracker=#MaxItem#

FolderMode=0

;-----------------------------------
Padding0=(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),#DropdownItemPaddingY#,#DropdownItemPadding2#,(#DropdownItemPaddingY#*-1)
Padding1=0,#DropdownItemPaddingY#,0,(#DropdownItemPaddingY#*-1)
;---
Padding0B=(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),#DropdownItemPaddingY#,#DropdownArrowHighlightW#,(#DropdownItemPaddingY#*-1)
Padding1B=#DropdownArrowHighlightW#,#DropdownItemPaddingY#,(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),(#DropdownItemPaddingY#*-1)
;-----------------------------------

;----------------------------------------------------
; Measures
;----------------------------------------------------

[BlurBehind]
Measure=Plugin
Plugin=FrostedGlass
BlurEnabled=#DropdownMenuBlur#
Type=[#BlurType[#BlurTypeNum]]
Border=[#Shadows[#DropdownMenuShadow]]
Corner=[#BlurCorner[#DropdownRoundCorners]]
DynamicVariables=1

[MeasureActionTimer1]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait [#FolderMouseOverTime[#FolderMouseOverTimeNum]]|StopBlock1|FolderMouseOver#FolderMode#|StopBlock0
FolderMouseOver0=[]
FolderMouseOver1=[!DeactivateConfigGroup Folder0][!ShowMeter HighlightSelected][!SetVariable HighlightSelectedY [#CurrentSubFolder#:Y]][!WriteKeyValue Variables FolderNum #FolderNum# "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables SelectedFolderY [#CURRENTSECTION#:Y] "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables Folder01Loc "[mPath][mIndex#CurrentSubFolder#Name]" "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!ActivateConfig "Droptop\Other\Folders\Folder01"][!Move ([#CURRENTCONFIGX]+#DropdownMenuWidth#+#DropdownSubMenuXOffset#) ([#CURRENTCONFIGY]+[#CurrentSubFolder#:Y]-[1:Y]) "Droptop\Other\Folders\Folder01"][!#Show# "Droptop\Other\Folders\Folder01"][!Update "Droptop\Other\Folders\Folder01"][!UpdateMeter HighlightSelected][!Redraw]
StopBlock1=[!SetVariable StopBlock 1][!UpdateMeterGroup Items]
StopBlock0=[!SetVariable StopBlock 0][!UpdateMeterGroup Items]
DynamicVariables=1
IgnoreWarnings=1
Disabled=1

[CalcFolderNum]
Measure=Calc
Formula=Clamp(([FolderCount]-(#ScrollTracker#-#MaxItem#)),0,#MaxItem#)
OnChangeAction=[!HideMeterGroup F20][!ShowMeterGroup F[CalcFolderNum]][!UpdateMeter FolderBlock]
DynamicVariables=1
Group=Scrollbar

[ScrollCheck]
Measure=Calc
IfCondition=AnalyzeTotal = #ScrollTracker#
IfTrueAction=[!DisableMouseActionGroup "MouseScrollDownAction" ItemName]
IfFalseAction=[!EnableMouseActionGroup "MouseScrollDownAction" ItemName]
IfCondition2=#ScrollTracker# = #MaxItem#
IfTrueAction2=[!DisableMouseActionGroup "MouseScrollUpAction" ItemName]
IfFalseAction2=[!EnableMouseActionGroup "MouseScrollUpAction" ItemName]
DynamicVariables=1
UpdateDivider=-1
Group=mPath | Scrollbar

[ScrollTimer]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 40|RevertIcons
RevertIcons=[!SetOptionGroup ItemIcon ImageAlpha #DropdownItemOpacity#][!UpdateMeasureGroup IconImage][!UpdateMeterGroup ItemIcon]

;----------------------------------------------------
; Styles
;----------------------------------------------------

[InfoStyle]
FontColor=#DropdownFontColor1#,#DropdownItemOpacity#
FontFace=[#FontName[#AltFont[#LanguageNum]]]
FontSize=#DropdownItemFontSize#
FontWeight=#FontWeight#
AntiAlias=#DropdownAntiAlias#
InlineSetting=CharacterSpacing | #DropdownCharacterSpacing#
InlineSetting2=[#DropdownTextShadow[#DropdownFontShadow][#ChamLum1]]
StringEffect=#DropdownStringEffect#
FontEffectColor=#DropdownFontEffectColor#

[ItemStyle]
StringAlign=#TextDirection#Center
MeasureName=mIndex#CURRENTSECTION#Name
LeftMouseDownAction=[!CommandMeasure mIndex#CURRENTSECTION#Name "Open"][!HideGroup Folders][!SetVariable ActiveFolder 0 "Droptop\DropdownBar"][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup Folders "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
RightMouseDownAction=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!CommandMeasure mIndex#CURRENTSECTION#Name "ContextMenu"][!HideGroup Folders][!SetVariable ActiveFolder 0 "Droptop\DropdownBar"][!HideMeter HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup Folders "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
MiddleMouseDownAction=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!CommandMeasure mIndex#CURRENTSECTION#Name "[#MiddleClickBehavior[#MiddleClickNum]]"][!HideGroup Folders][!SetVariable ActiveFolder 0 "Droptop\DropdownBar"][!SetVariable UnfocusAction 0 "Droptop\DropdownBar"][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup Folders "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
MouseOverAction=[!SetVariable CurrentSubFolder #CURRENTSECTION#][!UpdateMeasure MeasureActionTimer#AnimationOFF#][!CommandMeasure MeasureActionTimer#AnimationOFF# "Execute 1"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!ShowMeterGroup Highlight][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#Arrow][!UpdateMeter FolderBlock][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!EnableMouseActionGroup "MouseOverAction" Items][!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!UpdateMeter #CURRENTSECTION#Arrow][!UpdateMeter #CURRENTSECTION#][!HideMeterGroup Highlight][!Redraw]
MouseScrollUpAction=[!CommandMeasure ScrollTimer "Stop 1"][!CommandMeasure ScrollTimer "Execute 1"][!SetOptionGroup ItemIcon ImageAlpha [#IconFlash[#IconFlashNum]]][!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!SetVariable ScrollTracker (#ScrollTracker#-(#ScrollTracker#-#MaxItem#<=#MaxItem#?(#ScrollTracker#-#MaxItem#):#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-#MaxItem#)][!CommandMeasure mPath "PageUp"][!DeactivateConfigGroup Folder0][!HideMeter HighlightSelected][!UpdateMeasureGroup Scrollbar][!UpdateMeter *][!Redraw]
MouseScrollDownAction=[!CommandMeasure ScrollTimer "Stop 1"][!CommandMeasure ScrollTimer "Execute 1"][!SetOptionGroup ItemIcon ImageAlpha [#IconFlash[#IconFlashNum]]][!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!SetVariable ScrollTracker (#ScrollTracker#+(#ScrollTracker#+#MaxItem#>=[AnalyzeTotal]?([AnalyzeTotal]-#ScrollTracker#):#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!CommandMeasure mPath "PageDown"][!DeactivateConfigGroup Folder0][!HideMeter HighlightSelected][!UpdateMeasureGroup Scrollbar][!UpdateMeter *][!Redraw]
W=(#DropdownMenuWidth#-#DropdownArrowHighlightW#-(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#))
H=#DropdownItemHeight#
Padding=[#Padding[#RTLText]B]
DynamicVariables=1
ClipString=1
Text="%1"
Hidden=1
X=(1+(#DropdownMenuWidth#*#RTLText#))
Y=R

@IncludeArrowStyle=#@#Meters\ArrowStyle\ArrowStyle#DropdownArrowStyle#.ini

[IconStyle]
MeasureName=mIndex#CURRENTSECTION#
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#))
Y=R
W=#IconW#
H=#IconH#
Greyscale=#DropdownIconGreyscale#
ImageAlpha=#DropdownItemOpacity#
ImageTint=#DropdownIconTint#
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
UpdateDivider=-1
Hidden=1

[BackgroundStyle]
LeftMouseDownAction=[]

;----------------------------------------------------
; Background Meters
;----------------------------------------------------

[Background]
Meter=Shape
MeterStyle=BackgroundStyle
Shape=Rectangle #DropdownMenuCutout#,(#DropdownMenuShapeOffsetH#+#DropdownMenuCutout#),(#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2)),(#DropdownItemHeight#*#NumberOfItems#+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(#DropdownMenuLandingHeight#-(#DropdownMenuLandingHeight#*#HideLanding#))-(#DropdownMenuCutout#*2)),#DropdownBGCorner# | Fill Color #DropdownBGColor1#,(#DropdownMenuOpacity1#<1?1:#DropdownMenuOpacity1#) | StrokeWidth #DropdownStrokeWidth# | Stroke Color #DropdownStrokeColor#
Shape2=#FlatTopShape#
Shape3=Combine Shape | Union Shape2
DynamicVariables=1

;----------------------------------------------------
; Item Highlight
;----------------------------------------------------

[HighlightBackground]
Meter=Shape
Shape=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),[#CurrentSubFolder#:Y],(#DropdownMenuWidth#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill Color #DropdownItemHL#,(#HighlightShapeOpacity#/#HighlightShapeOpacityDivisor1B#) | StrokeWidth 0
X=1
Group=Highlight | HL
DynamicVariables=1
Hidden=1

[HighlightSelected]
Meter=Shape
Shape=Rectangle [#HLSelectedShape[#HLSelectedShapeNum]]
ShapeOption=[#HLSelectedOption[#HLSelectedShapeNum]]
X=1
Y=#HighlightSelectedY#
Group=HighlightSelected
DynamicVariables=1
Hidden=1

;----------------------------------------------------
; Item Names
;----------------------------------------------------

[NA]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Text="#FoldersItem0A#"
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)
LeftMouseDownAction=["#FolderLoc#"][!HideGroup Folders][!SetVariable ActiveFolder 0 "Droptop\DropdownBar"][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup Folders "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
MouseOverAction=[!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Icon ImageAlpha (255-(255*#HideIcons#))][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!ShowMeterGroup Highlight][!SetOptionGroup Highlight W [#CURRENTSECTION#:W]][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!HideMeterGroup Highlight][!SetOption #CURRENTSECTION#Icon ImageTint #*DropdownFontColor1*#][!SetOption #CURRENTSECTION#Icon ImageAlpha (#DropdownItemOpacity#-(#DropdownItemOpacity#*#HideIcons#))][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=1
Group=0 | Items | ItemName

[1]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)
Group=1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[2]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[3]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[4]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[5]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[6]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[7]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[8]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[9]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[10]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[11]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[12]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[13]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[14]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=14 | 15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[15]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=15 | 16 | 17 | 18 | 19 | 20 | Items | ItemName

[16]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=16 | 17 | 18 | 19 | 20 | Items | ItemName

[17]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=17 | 18 | 19 | 20 | Items | ItemName

[18]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=18 | 19 | 20 | Items | ItemName

[19]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=19 | 20 | Items | ItemName

[20]
Meter=String
MeterStyle=InfoStyle | ItemStyle
Group=20 | Items | ItemName

;----------------------------------------------------
; Icons
;----------------------------------------------------

[NAIcon]
Meter=Image
MeterStyle=IconStyle
ImageName=#@#Icons\Fixed\#IconSize#\noitem.png
ImageTint=#DropdownFontColor1#
ImageAlpha=(#DropdownItemOpacity#-(#DropdownItemOpacity#*#HideIcons#))
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#)
DynamicVariables=1
UpdateDivider=1
Group=0 | ItemIcon

[1Icon]
Meter=Image
MeterStyle=IconStyle
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#)
Group=1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[2Icon]
Meter=Image
MeterStyle=IconStyle
Group=2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[3Icon]
Meter=Image
MeterStyle=IconStyle
Group=3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[4Icon]
Meter=Image
MeterStyle=IconStyle
Group=4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[5Icon]
Meter=Image
MeterStyle=IconStyle
Group=5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[6Icon]
Meter=Image
MeterStyle=IconStyle
Group=6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[7Icon]
Meter=Image
MeterStyle=IconStyle
Group=7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[8Icon]
Meter=Image
MeterStyle=IconStyle
Group=8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[9Icon]
Meter=Image
MeterStyle=IconStyle
Group=9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[10Icon]
Meter=Image
MeterStyle=IconStyle
Group=10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[11Icon]
Meter=Image
MeterStyle=IconStyle
Group=11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[12Icon]
Meter=Image
MeterStyle=IconStyle
Group=12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[13Icon]
Meter=Image
MeterStyle=IconStyle
Group=13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[14Icon]
Meter=Image
MeterStyle=IconStyle
Group=14 | 15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[15Icon]
Meter=Image
MeterStyle=IconStyle
Group=15 | 16 | 17 | 18 | 19 | 20 | ItemIcon

[16Icon]
Meter=Image
MeterStyle=IconStyle
Group=16 | 17 | 18 | 19 | 20 | ItemIcon

[17Icon]
Meter=Image
MeterStyle=IconStyle
Group=17 | 18 | 19 | 20 | ItemIcon

[18Icon]
Meter=Image
MeterStyle=IconStyle
Group=18 | 19 | 20 | ItemIcon

[19Icon]
Meter=Image
MeterStyle=IconStyle
Group=19 | 20 | ItemIcon

[20Icon]
Meter=Image
MeterStyle=IconStyle
Group=20 | ItemIcon

;----------------------------------------------------
; Folders
;----------------------------------------------------

[FolderBlock]
Meter=Image
SolidColor=0,0,0,0
X=1
Y=[1:Y]
W=#DropdownMenuWidth#
H=(#DropdownItemHeight#*[CalcFolderNum])
LeftMouseDownAction=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!ShowMeter HighlightSelected][!SetVariable HighlightSelectedY ([#CurrentSubFolder#:Y])][!WriteKeyValue Variables CurrentFolder #CurrentFolder# "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables CurrentFolder #CurrentFolder# "#SKINSPATH#Droptop\Other\Folders\Folder02\Folder02.ini"][!WriteKeyValue Variables FolderNum #FolderNum# "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables SelectedFolderY [#CurrentSubFolder#:Y] "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!WriteKeyValue Variables Folder01Loc "[mPath][mIndex#CurrentSubFolder#Name]" "#SKINSPATH#Droptop\Other\Folders\Folder01\Folder01.ini"][!HideGroup Folder0][!DeactivateConfigGroup Folder0][!ActivateConfig "Droptop\Other\Folders\Folder01"][!Move ([#CURRENTCONFIGX]+#DropdownMenuWidth#+#DropdownSubMenuXOffset#) ([#CURRENTCONFIGY]+[#CurrentSubFolder#:Y]-[1:Y]) "Droptop\Other\Folders\Folder01"][!#Show# "Droptop\Other\Folders\Folder01"][!Update "Droptop\Other\Folders\Folder01"][!UpdateMeter HighlightSelected][!Redraw]
MouseOverAction=[!SetVariable FolderMode 1]
MouseLeaveAction=[!SetVariable FolderMode 0]
DynamicVariables=1
Group=Item

;----------------------------------------------------
; Arrows
;----------------------------------------------------

[1Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20
Y=[1Icon:Y]

[2Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[3Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[4Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[5Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[6Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[7Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[8Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[9Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[10Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[11Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[12Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[13Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20

[14Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F14 | F15 | F16 | F17 | F18 | F19 | F20

[15Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F15 | F16 | F17 | F18 | F19 | F20

[16Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F16 | F17 | F18 | F19 | F20

[17Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F17 | F18 | F19 | F20

[18Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F18 | F19 | F20

[19Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F19 | F20

[20Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Group=F20

;----------------------------------------------------
; Scrollbar
;----------------------------------------------------

[ScrollbarTop]
Meter=Image
X=3
Y=(#DropdownIconYoffset#-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#-1)
UpdateDivider=-1

[Size]
Measure=Calc
Formula=((#DropdownItemHeight#*#MaxItem#)-#DropdownIconYoffset#)
UpdateDivider=-1
Group=Scrollbar

[ScrollH]
Measure=Calc
Formula=Size * (#MaxItem# / (AnalyzeTotal = 0 ? 1 : AnalyzeTotal))
UpdateDivider=-1
RegExpSubstitute=1
Substitute="^0$":"#DropdownItemHeight#"
Group=Scrollbar
Disabled=1

[ScrollbarScript]
Measure=Script
ScriptFile=#LuaLoc#
UpdateDivider=-1

[CurrentPos]
Meter=Shape
Shape=Rectangle 0,0,(3*#DroptopSize#),([ScrollH]<1?1:[ScrollH]),2 | Fill Color #DropdownFontColor1#,155 | StrokeWidth 0 | StrokeColor #DropdownBGColor1#,55
X=(#DropdownMenuWidth#-(3*#DroptopSize#)-(#DropdownStrokeWidth#/2))
Y=(#DropdownIconYoffset#-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+1)
DynamicVariables=1
Group=ScrollBar | Items
Hidden=1

;----------------------------------------------------
; Landing
;----------------------------------------------------

[OpenFolder]
Meter=Image
ImageName=#@#Icons\Fixed\Medium\dot.png
ImageTint=#DropdownFontColor1#,#DropdownItemOpacity#
ImageAlpha=55
X=(8*#DroptopSize#)
Y=(#DropdownIconYoffset#+(#DropdownItemHeight#*#NumberOfItems#)-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+#DropdownBottomButtonOffset#)
H=(16*#DroptopSize#)
LeftMouseDownAction=["#FolderLoc#"][!SetVariable ActiveFolder 0 "Droptop\DropdownBar"][!HideGroup Folders][!UpdateMeterGroup Folders "Droptop\DropdownBar"][!HideMeter HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup Folders "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
MouseOverAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\open.png"][!SetOption #CURRENTSECTION# ImageAlpha #DropdownItemOpacity#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\dot.png"][!SetOption #CURRENTSECTION# ImageAlpha 55][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=#HideLanding#
DynamicVariables=1

[OpenRefresh]
Meter=Image
ImageName=#@#Icons\Fixed\Medium\dot.png
ImageTint=#DropdownFontColor1#,#DropdownItemOpacity#
ImageAlpha=55
X=(30*#DroptopSize#)
Y=r
H=(16*#DroptopSize#)
LeftMouseDownAction=[!DeactivateConfig][!WriteKeyValue Variables CycleFolder #CurrentFolder# "#SKINSPATH#Droptop\Other\BackgroundProcesses\Tasks\ToggleFolders.ini"][!ActivateConfig "Droptop\Other\BackgroundProcesses\Tasks" "ToggleFolders.ini"]
MouseOverAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\refresh.png"][!SetOption #CURRENTSECTION# ImageAlpha #DropdownItemOpacity#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\dot.png"][!SetOption #CURRENTSECTION# ImageAlpha 55][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=#HideLanding#
DynamicVariables=1

[DownArrow]
Meter=Shape
Shape=Rectangle (-5*#DroptopSize#),(-1*#DroptopSize#),(21*#DroptopSize#),(21*#DroptopSize#),0 | Fill Color 0,0,0,0 | StrokeWidth 0
Shape2=Rectangle 0,(-1*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45 | Extend Look
Shape3=Rectangle 0,(-3*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45
Shape4=Combine Shape2 | Exclude Shape3
Look=Fill Color #DropdownFontColor1#,(#ScrollTracker#>=[AnalyzeTotal]?0:(#DropdownItemOpacity#/3))
LeftMouseDownAction=[!SetVariable ScrollTracker (#ScrollTracker#+(#ScrollTracker#+#MaxItem#>=[AnalyzeTotal]?([AnalyzeTotal]-#ScrollTracker#):#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!CommandMeasure mPath "PageDown"][!DeactivateConfigGroup Folder0][!HideMeter HighlightSelected][!UpdateMeasure *][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#>=[AnalyzeTotal]?0:#DropdownItemOpacity#)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#>=[AnalyzeTotal]?0:(#DropdownItemOpacity#/3))"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#DropdownMenuWidth#-(25*#DroptopSize#))
Y=r
Hidden=#HideLanding#
DynamicVariables=1

[UpArrow]
Meter=Shape
Shape=Rectangle (-5*#DroptopSize#),(-1*#DroptopSize#),(21*#DroptopSize#),(21*#DroptopSize#),0 | Fill Color 0,0,0,0 | StrokeWidth 0
Shape2=Rectangle 0,(6*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45 | Extend Look
Shape3=Rectangle 0,(8*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45
Shape4=Combine Shape2 | Exclude Shape3
Look=Fill Color #DropdownFontColor1#,(#ScrollTracker#<=#MaxItem#?0:(#DropdownItemOpacity#/3))
LeftMouseDownAction=[!SetVariable ScrollTracker (#ScrollTracker#-(#ScrollTracker#-#MaxItem#<=#MaxItem#?(#ScrollTracker#-#MaxItem#):#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-#MaxItem#)][!CommandMeasure mPath "PageUp"][!DeactivateConfigGroup Folder0][!HideMeter HighlightSelected][!UpdateMeasure *][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#<=#MaxItem#?0:#DropdownItemOpacity#)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#<=#MaxItem#?0:(#DropdownItemOpacity#/3))"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#DropdownMenuWidth#-(45*#DroptopSize#))
Y=r
Hidden=#HideLanding#
DynamicVariables=1
