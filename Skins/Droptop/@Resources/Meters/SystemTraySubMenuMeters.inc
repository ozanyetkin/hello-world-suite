[Rainmeter]
OnFocusAction=[!SetVariable Focused 1 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure CompareFocused "Droptop\Other\BackgroundProcesses"]
OnUnfocusAction=[!SetVariable Focused 0 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure MeasureIsFullScreen "Droptop\Other\BackgroundProcesses"]
Group=DroptopSuite | Tray | Folders | Submenus
MouseActionCursor=Arrow
; SkinWidth=(#DropdownSubMenuWidth#+2)
RightMouseDownAction=[]
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
;-----------------------------------
Padding0=(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),#DropdownItemPaddingY#,#DropdownItemPadding2#,(#DropdownItemPaddingY#*-1)
Padding1=#DropdownItemPadding2#,#DropdownItemPaddingY#,(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),(#DropdownItemPaddingY#*-1)
;---
Padding0B=(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),#DropdownItemPaddingY#,(#DropdownNoIconPadding#*2),(#DropdownItemPaddingY#*-1)
Padding1B=(#DropdownNoIconPadding#*2),#DropdownItemPaddingY#,(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),(#DropdownItemPaddingY#*-1)
;-----------------------------------

[BlurBehind]
Measure=Plugin
Plugin=FrostedGlass
BlurEnabled=#MenuBlur#
Type=[#BlurType[#BlurTypeNum]]
Border=[#Shadows[#DropdownMenuShadow]]
Corner=[#BlurCorner[#DropdownRoundCorners]]
DynamicVariables=1

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
X=(1+(#DropdownMenuWidth#*#RTLText#))
Y=R
W=(#DropdownMenuWidth#-(#DropdownNoIconPadding#*2)-#DropdownItemPadding1#+((#DropdownItemPadding1#-#DropdownNoIconPadding#)*#HideIcons#))
H=#DropdownItemHeight#
Text="%1"
FontWeight=#FontWeight#
Padding=[#Padding[#RTLText]B]
AntiAlias=#DropdownAntiAlias#
MouseOverAction=[!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor2*#,(#*HighlightFontOpacity1*#-(#*HighlightFontOpacity1*#*#HideIcons#))"][!SetOption #CURRENTSECTION#Folder FontColor #*DropdownFontColor2*#][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!ShowMeterGroup Highlight][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!HideMeterGroup Highlight][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor1*#,(#DropdownItemOpacity#-(#DropdownItemOpacity#*#HideIcons#))"][!SetOption #CURRENTSECTION#Folder FontColor #*DropdownFontColor1*#][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
ClipString=1
Group=Items

[IconStyle]
ImageTint=#DropdownFontColor1#,(#DropdownItemOpacity#-(#DropdownItemOpacity#*#HideIcons#))
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#))
Y=R
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
Greyscale=#DropdownIconGreyscale#
DynamicVariables=1
Group=Items

[CheckmarkStyle]
ImageTint=#DropdownFontColor1#
ImageName=#@#Icons\Fixed\#IconSize#\checkmark.png
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#))
Y=R
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
Greyscale=#DropdownIconGreyscale#
DynamicVariables=1
Group=Items

[ToggleStyle]
ImageTint=#DropdownFontColor1#
ImageName=#@#Icons\Fixed\#IconSize#\toggle.png
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#))
Y=R
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
Greyscale=#DropdownIconGreyscale#
DynamicVariables=1
Group=Items

[FolderStyle]
StringAlign=Right
FontColor=#DropdownFontColor1#,(#DropdownItemOpacity#*#SlideOpac2#)
FontFace=[#FontName[#AltFont[#LanguageNum]]]
FontSize=#DropdownItemFontSize#
X=(#DropdownMenuWidth#+1)
Y=R
W=(#DropdownMenuWidth#-3)
H=#DropdownItemHeight#
Text=❯
Padding=0,0,3,0
AntiAlias=#DropdownAntiAlias#
DynamicVariables=1
ClipString=1
Group=Folders

[BackgroundStyle]
LeftMouseDownAction=[]
UpdateDivider=-1

;----------------------------------------------------
; Background Meters
;----------------------------------------------------

[Background]
Meter=Shape
MeterStyle=BackgroundStyle
Shape=Rectangle #DropdownMenuCutout#,#DropdownMenuCutout#,(#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2)),(#DropdownItemHeight#*#NumberOfItems#+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(((#DividerSpace#*2)+#DividerHeight#)*#NumberOfDividers#)-(#DropdownMenuCutout#*2)),#DropdownBGCorner# | Fill Color #DropdownBGColor1#,(#DropdownMenuOpacity1#<1?1:#DropdownMenuOpacity1#) | StrokeWidth #DropdownStrokeWidth# | Stroke Color #DropdownStrokeColor#
UpdateDivider=-1

;----------------------------------------------------
; Item highlight

[HighlightBackground]
Meter=Shape
Shape=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),[#CurrentSubFolder#:Y],(#DropdownMenuWidth#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill Color #DropdownItemHL#,(#HighlightShapeOpacity#/#HighlightShapeOpacityDivisor1B#) | StrokeWidth 0
X=1
Group=Highlight | HL
DynamicVariables=1
Hidden=1