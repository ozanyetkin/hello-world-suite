[Rainmeter]
OnRefreshAction=[!ShowMeterGroup [#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber]ItemCount]][!ShowMeterGroup F[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber]FolderCount]][!ShowMeterGroup D[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber]DividerCount]][!Redraw]
OnFocusAction=[!SetVariable Focused 1 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure CompareFocused "Droptop\Other\BackgroundProcesses"]
OnUnfocusAction=[!SetVariable Focused 0 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure MeasureIsFullScreen "Droptop\Other\BackgroundProcesses"]
MouseActionCursor=Arrow
SkinWidth=(#DropdownMenuWidth#+2)
RightMouseDownAction=[]
MiddleMouseDoubleClickAction=["#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenuModule\[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber]ModuleName].inc"]
Update=-1

DefaultSavePosition=1
DefaultAlwaysOnTop=1
DefaultDraggable=1
DefaultSnapEdges=1
DefaultStartHidden=1
DefaultAlphaValue=255
DefaultHideOnMouseOver=0
DefaultFadeDuration=105
DefaultClickThrough=0
DefaultKeepOnScreen=1
DefaultAutoSelectScreen=0

[Metadata]
Name=Droptop Four
Author=Cariboudjan / Thomas Sven Whittaker
Information=The frogurt is also cursed
License=Creative Commons Attribution-Non-Commercial-Share Alike 3.0

[Variables]
@IncludeControl=#@#GlobalVar\Control.inc
@IncludeUserSettings=#@#GlobalVar\UserSettings.inc
@IncludeFolderSettings=#@#GlobalVar\FolderSettings.inc
@IncludeThemeOptions=#@#Themes\#ThemeNum#Settings.inc
@IncludeThemeDesign=#@#Themes\#ThemeNum#.inc
@IncludeThemeMeasures=#SKINSPATH#Droptop Folders\Other files\Themes\ThemeMeasures.inc
@IncludeSupporter=#@#GlobalVar\Supporter.inc
@IncludeLanguage=#@#GlobalVar\Languages\[#Language[#LanguageNum]].inc
@IncludeSettingsMenuOptions=#@#GlobalVar\SettingsMenuOptions.inc
@IncludeTopBarPos=#@#GlobalVar\TopBarPos.inc

NumberOfItems=[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber]ItemCount]
NumberOfFolders=[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber]FolderCount]
NumberOfDividers=[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber]DividerCount]

FolderNum=99
ContextSelect=99
BoxSize=0

ReservedPadding=#DropdownItemPadding1#

CurrentFolder=1

;-----------------------------------
Padding0=#DropdownItemPadding1#,#DropdownItemPaddingY#,#DropdownItemPadding2#,(#DropdownItemPaddingY#*-1)
Padding1=(#DropdownItemPadding1#*2),#DropdownItemPaddingY#,#DropdownNoIconPadding#,(#DropdownItemPaddingY#*-1)
;---
Padding0B=#DropdownItemPadding1#,#DropdownItemPaddingY#,(#DropdownNoIconPadding#*2),(#DropdownItemPaddingY#*-1)
Padding1B=(#DropdownNoIconPadding#*2),#DropdownItemPaddingY#,#DropdownItemPadding1#,(#DropdownItemPaddingY#*-1)
;-----------------------------------

1Icon=1
2Icon=2
3Icon=3
4Icon=4
5Icon=5
6Icon=6
7Icon=7
8Icon=8
9Icon=9
10Icon=10
11Icon=11
12Icon=12
13Icon=13
14Icon=14
15Icon=15
16Icon=16
17Icon=17
18Icon=18
19Icon=19
20Icon=20
21Icon=21
22Icon=22
22Icon=23

;----------------------------------------------------

[BlurBehind]
Measure=Plugin
Plugin=FrostedGlass
BlurEnabled=#DropdownMenuBlur#
Type=[#BlurType[#BlurTypeNum]]
Border=[#Shadows[#DropdownMenuShadow]]
Corner=[#BlurCorner[#DropdownRoundCorners]]
DynamicVariables=1

[NextBlock]
Measure=Calc
Formula=(#SettingsMenuBlock#+1)
UpdateDivider=-1

[MeasureActionTimer1]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait [#FolderMouseOverTime[#FolderMouseOverTimeNum]]|StopBlock1|FolderMouseOver#FolderMode#|StopBlock0
FolderMouseOver1=[!DeactivateConfig "Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]"][!SetTransparencyGroup 0 SM[NextBlock]][!ShowMeter HighlightSelected][!SetVariable HighlightSelectedY [#CurrentFolder#:Y]][!WriteKeyValue Variables SettingsMenuNumber "#SettingsMenuNumber#.#CurrentFolder#" "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]\SettingsMenu[NextBlock].ini"][!WriteKeyValue Variables SettingsMenuIndex#SettingsMenuBlock# #CurrentFolder# "#@#GlobalVar\SettingsMenuOptions.inc"][!WriteKeyValue Variables SettingsMenuIndex #CurrentFolder# "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]\SettingsMenu[NextBlock].ini"][!WriteKeyValue Variables SettingsMenuYpos (#SettingsMenuYpos#+[#CurrentFolder#:Y]-(#DropdownIconYoffset#+#DropdownItemYOffset#)) "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]\SettingsMenu[NextBlock].ini"][!ActivateConfig "Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]" "SettingsMenu[NextBlock].ini"][!Move ([#CURRENTCONFIGX]+#DropdownMenuWidth#+#DropdownSubMenuXOffset#-(((#DropdownMenuWidth#+#DropdownSubMenuXOffset#)*2)*#SettingsSubMenuOpenLeft#)) ([#CURRENTCONFIGY]+[#CurrentFolder#:Y]-[1:Y]) "Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]"][!#Show# "Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]"][!UpdateMeter HighlightSelected][!Redraw]
StopBlock1=[!SetVariable StopBlock 1][!UpdateMeterGroup Items]
StopBlock0=[!SetVariable StopBlock 0][!UpdateMeterGroup Items]
FolderMouseOver0=[]
FolderMouseOver1=
DynamicVariables=1
; IgnoreWarnings=1
Disabled=1

;----------------------------------------------------
; Styles
;----------------------------------------------------

[InfoStyle]
StringAlign=#TextDirection#Center
FontColor=#DropdownFontColor1#,#DropdownItemOpacity#
FontFace=[#FontName[#AltFont[#LanguageNum]]]
FontSize=#DropdownItemFontSize#
InlineSetting=CharacterSpacing | #DropdownCharacterSpacing#
InlineSetting2=[#DropdownTextShadow[#DropdownFontShadow][#ChamLum1]]
StringEffect=#DropdownStringEffect#
FontEffectColor=#DropdownFontEffectColor#
Text=[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber].[##CURRENTSECTION#Icon]]
LeftMouseDownAction=[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber].[##CURRENTSECTION#Icon].Action]
X=(1+(#DropdownMenuWidth#*#RTLText#))
Y=R
W=(#DropdownMenuWidth#-(#DropdownNoIconPadding#*2)-#DropdownItemPadding1#+((#DropdownItemPadding1#-#DropdownNoIconPadding#)*#HideIcons#))
H=#DropdownItemHeight#
FontWeight=#FontWeight#
Padding=[#Padding[#RTLText]B]
AntiAlias=#DropdownAntiAlias#
MouseOverAction=[!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetVariable CurrentFolder #CURRENTSECTION#][!UpdateMeasure MeasureActionTimer#AnimationOFF#][!CommandMeasure MeasureActionTimer#AnimationOFF# "Execute 1"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Folder FontColor #*DropdownFontColor2*#][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!ShowMeterGroup Highlight][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#Arrow][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#][!UpdateMeter FolderBlock][!Redraw]
MouseLeaveAction=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!HideMeterGroup Highlight][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Folder FontColor #*DropdownFontColor1*#][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!UpdateMeter #CURRENTSECTION#Arrow][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
ClipString=1
Group=Items

[IconStyle]
ImageName=[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber].[##CURRENTSECTION#].Icon]
ImageTint=#DropdownFontColor1#,#DropdownItemOpacity#
ImageAlpha=[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber].[##CURRENTSECTION#].IconAlpha]
ImageFlip=[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber].[##CURRENTSECTION#].IconFlip]
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#))
Y=R
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
Greyscale=#DropdownIconGreyscale#
Hidden=1
DynamicVariables=1
Group=Items

@IncludeArrowStyle=#@#Meters\ArrowStyle\ArrowStyle#DropdownArrowStyle#.ini

[CheckmarkStyle]
ImageTint=#DropdownFontColor1#
ImageName=#@#Icons\Fixed\#IconSize#\checkmark.png
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#))
Y=R
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
Greyscale=#DropdownIconGreyscale#
DynamicVariables=1
Group=Items

[BackgroundStyle]
LeftMouseDownAction=[]

;----------------------------------------------------
; Background Meters
;----------------------------------------------------

[Background]
Meter=Shape
MeterStyle=BackgroundStyle
Shape=Rectangle #DropdownMenuCutout#,#DropdownMenuCutout#,(#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2)),(#DropdownItemHeight#*#NumberOfItems#+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(((#DividerSpace#*2)+#DividerHeight#)*#NumberOfDividers#)-(#DividerHeight#*#NumberOfDividers#)-(#DropdownMenuCutout#*2)),#DropdownBGCorner# | Fill Color #DropdownBGColor1#,(#DropdownMenuOpacity1#<1?1:#DropdownMenuOpacity1#) | StrokeWidth #DropdownStrokeWidth# | Stroke Color #DropdownStrokeColor#
DynamicVariables=1

;----------------------------------------------------
; Item highlight

[HighlightBackground]
Meter=Shape
Shape=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),[#CurrentSubFolder#:Y],(#DropdownMenuWidth#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill Color #DropdownItemHL#,(#HighlightShapeOpacity#/#HighlightShapeOpacityDivisor1B#) | StrokeWidth 0
HighlightBackgroundGradient=180 | #DropdownItemHL#,(#HighlightShapeOpacity#/#HighlightShapeOpacityDivisor1B#) ; 0.4 | #DropdownItemHL#,0 ; 0.8 | #DropdownItemHL#,0 ; 1.0
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

[Divider1]
Meter=Shape
Shape=#DividerShape#
Group=D1 | D2 | D3 | D4 | D5
Hidden=1

[Divider2]
Meter=Shape
Shape=#DividerShape#
Group=D2 | D3 | D4 | D5
Hidden=1

[Divider3]
Meter=Shape
Shape=#DividerShape#
Group=D3 | D4 | D5
Hidden=1

[Divider4]
Meter=Shape
Shape=#DividerShape#
Group=D4 | D5
Hidden=1

[Divider5]
Meter=Shape
Shape=#DividerShape#
Group=D5
Hidden=1

;----------------------------------------------------
; Item Names
;----------------------------------------------------

[1]
Meter=String
MeterStyle=InfoStyle
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)
Hidden=1
Group=1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items 

[2]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items 

[3]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items 

[4]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[5]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[6]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[7]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes | SupporterFolders

[8]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes | SupporterFolders

[9]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes | SupporterFolders

[10]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes | SupporterFolders

[11]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes | SupporterFolders

[12]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes | SupporterFolders

[13]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[14]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[15]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[16]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[17]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=17 | 18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[18]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=18 | 19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[19]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=19 | 20 | 21 | 22 | 23 | Items | SupporterThemes

[20]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=20 | 21 | 22 | 23 | Items | SupporterThemes

[21]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=21 | 22 | 23 | Items | SupporterThemes

[22]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=22 | 23 | Items | SupporterThemes

[23]
Meter=String
MeterStyle=InfoStyle
Hidden=1
Group=23 | Items 

;----------------------------------------------------

[Slider1]
Meter=Shape

[Slider2]
Meter=Shape

[Slider3]
Meter=Shape

[Slider4]
Meter=Shape

[SliderText1]
Meter=String

[SliderText2]
Meter=String

[SliderText3]
Meter=String

[SliderText4]
Meter=String

;----------------------------------------------------
; Icons
;----------------------------------------------------

[1Icon]
Meter=Image
MeterStyle=IconStyle
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#))
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+1)
Group=1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon

[2Icon]
Meter=Image
MeterStyle=IconStyle
Group=2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon

[3Icon]
Meter=Image
MeterStyle=IconStyle
Group=3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon

[4Icon]
Meter=Image
MeterStyle=IconStyle
Group=4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon

[5Icon]
Meter=Image
MeterStyle=IconStyle
Group=5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[6Icon]
Meter=Image
MeterStyle=IconStyle
Group=6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[7Icon]
Meter=Image
MeterStyle=IconStyle
Group=7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes | SupporterFolders

[8Icon]
Meter=Image
MeterStyle=IconStyle
Group=8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes | SupporterFolders

[9Icon]
Meter=Image
MeterStyle=IconStyle
Group=9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes | SupporterFolders

[10Icon]
Meter=Image
MeterStyle=IconStyle
Group=10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes | SupporterFolders

[11Icon]
Meter=Image
MeterStyle=IconStyle
Group=11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes | SupporterFolders

[12Icon]
Meter=Image
MeterStyle=IconStyle
Group=12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes | SupporterFolders

[13Icon]
Meter=Image
MeterStyle=IconStyle
Group=13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[14Icon]
Meter=Image
MeterStyle=IconStyle
Group=14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[15Icon]
Meter=Image
MeterStyle=IconStyle
Group=15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[16Icon]
Meter=Image
MeterStyle=IconStyle
Group=16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[17Icon]
Meter=Image
MeterStyle=IconStyle
Group=17 | 18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[18Icon]
Meter=Image
MeterStyle=IconStyle
Group=18 | 19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[19Icon]
Meter=Image
MeterStyle=IconStyle
Group=19 | 20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[20Icon]
Meter=Image
MeterStyle=IconStyle
Group=20 | 21 | 22 | 23 | ItemIcon | SupporterThemes

[21Icon]
Meter=Image
MeterStyle=IconStyle
Group=21 | 22 | 23 | ItemIcon | SupporterThemes

[22Icon]
Meter=Image
MeterStyle=IconStyle
Group=22 | 23 | ItemIcon | SupporterThemes

[23Icon]
Meter=Image
MeterStyle=IconStyle
Group=23 | ItemIcon

;----------------------------------------------------
; Folders
;----------------------------------------------------

[FolderBlock]
Meter=Image
X=1
Y=[1:Y]
W=#DropdownMenuWidth#
H=(#DropdownItemHeight#*[#SettingsMenu[#SettingsMenuBlock].[#SettingsMenuNumber]FolderCount])
LeftMouseDownAction=[!HideGroup SettingsMenuInput][!DeactivateConfigGroup SettingsMenuInput][!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!ShowMeter HighlightSelected][!SetVariable HighlightSelectedY [#CurrentFolder#:Y]][!WriteKeyValue Variables SettingsMenuNumber "#SettingsMenuNumber#.#CurrentFolder#" "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]\SettingsMenu[NextBlock].ini"][!WriteKeyValue Variables SettingsMenuIndex#SettingsMenuBlock# #CurrentFolder# "#@#GlobalVar\SettingsMenuOptions.inc"][!WriteKeyValue Variables SettingsMenuIndex #CurrentFolder# "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]\SettingsMenu[NextBlock].ini"][!WriteKeyValue Variables SettingsMenuYpos (#SettingsMenuYpos#+[#CurrentFolder#:Y]-(#DropdownIconYoffset#+#DropdownItemYOffset#)) "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]\SettingsMenu[NextBlock].ini"][!HideGroup SM[NextBlock]][!DeactivateConfigGroup SM[NextBlock]][!ActivateConfig "Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]"][!Move ([#CURRENTCONFIGX]+#DropdownMenuWidth#+#DropdownSubMenuXOffset#-(((#DropdownMenuWidth#+#DropdownSubMenuXOffset#)*2)*#SettingsSubMenuOpenLeft#)) ([#CURRENTCONFIGY]+[#CurrentFolder#:Y]-[1:Y]) "Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]"][!#Show# "Droptop\Other\SettingsMenu\SettingsMenu[NextBlock]"][!UpdateMeter HighlightSelected][!Redraw]
MouseOverAction=[!SetVariable FolderMode 1]
MouseLeaveAction=[!SetVariable FolderMode 0]
DynamicVariables=1
Group=Items

;----------------------------------------------------
; Arrows
;----------------------------------------------------

[1Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Y=[1Icon:Y]
Group=F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23

[2Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23

[3Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23

[4Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F4 | F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23

[5Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F5 | F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes

[6Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F6 | F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes

[7Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F7 | F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes | SupporterFolders

[8Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F8 | F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes | SupporterFolders

[9Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F9 | F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes | SupporterFolders

[10Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F10 | F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes | SupporterFolders

[11Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F11 | F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes | SupporterFolders

[12Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F12 | F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes | SupporterFolders

[13Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F13 | F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes

[14Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F14 | F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes

[15Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F15 | F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes

[16Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F16 | F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes

[17Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F17 | F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes

[18Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F18 | F19 | F20 | F21 | F22 | F23 | SupporterThemes

[19Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F19 | F20 | F21 | F22 | F23 | SupporterThemes

[20Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F20 | F21 | F22 | F23 | SupporterThemes

[21Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F21 | F22 | F23 | SupporterThemes

[22Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F22 | F23 | SupporterThemes

[23Arrow]
Meter=Shape
MeterStyle=ArrowStyle
Hidden=1
Group=F23

;-------------------------

[LocationText]

[ScrollbarTop]

[Size]

[ScrollH]

[ScrollbarScript]

[CurrentPos]

[OpenFolder]

[OpenRefresh]

[DownArrow]

[UpArrow]

[BottomString]

[1ButtonBG]

[1Icon.1]

[1Icon.2]

[1Icon.3]

[DownloadApps]

[DownloadAppsString]