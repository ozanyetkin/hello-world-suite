[Variables]

; --------------------------
; Menu options

TopBarBlur=0
TopBarHideGradient=1
TopBarHideHomeShape=1
TopBarHLSkew=0

DropdownMenuBlur=0
DropdownArrowStyle=1

;---

IconStyle=1

NewDesktopStyle=#IconStyle#
ActionStyle=#IconStyle#
SearchStyle=#IconStyle#
TimeStyle=#IconStyle#
MailStyle=#IconStyle#
AlarmStyle=#IconStyle#
VolumeStyle=#IconStyle#
WeatherStyle=#IconStyle#
WifiStyle=#IconStyle#
BatteryStyle=#IconStyle#
BatteryMaskStyle=#IconStyle#
DownloadsStyle=#IconStyle#
RecentStyle=#IconStyle#
NotesStyle=#IconStyle#
CopyStyle=#IconStyle#
ExchangeStyle=#IconStyle#
LanguageStyle=#IconStyle#
AppDrawerStyle=#IconStyle#
AssistantStyle=#IconStyle#

DropdownSliderStyle=1

;-------------------------
; Colors

SetColorByWallpaperOFF=0

TopBarBGColor1=253,21,101
TopBarBGColor2=253,21,101
TopBarBGColor3=253,21,101
TopBarFontColor1=255,255,255
TopBarFontColor2=253,21,101
TopBarHLColor1=255,255,255
TopBarAssistantIconTint1=255,255,255
TopBarAssistantIconTint2=253,21,101
TopBarHomeIconColor=255,255,255
TopBarIconGreyscale=0
TopBarBorderTopColor=25,25,25,(55*(#TopBarOpacity1#/255))
TopBarBorderBottomColor=0,0,0,(26*(#TopBarOpacity1#/255))

DropdownBGColor1=253,21,101
DropdownFontColor1=255,255,255
DropdownFontColor2=253,21,101
DropdownItemHL=255,255,255
DropdownIconTint=255,255,255
DropdownIconGreyscale=0
DropdownSliderColor=#DropdownItemHL#

BatteryChargingColor=47,207,91
BatteryDyingColor=233,86,70

;-------------------------
; Opacities

TopBarOpacity1=255
TopBarGradientOpacity1=115
TopBarHLOpacity1=255
TopBarHLOpacity2=85
TopBarHLOpacity2Offset=0
TopBarTitleOpacity=255

DropdownMenuOpacity1=255
DropdownHLOpacity1=255
DropdownHLOpacity2=85
DropdownHLOpacity2Offset=0
DropdownItemOpacity=255

HighlightShapeOpacity=255
HighlightShapeOpacityDivisor1A=1
HighlightShapeOpacityDivisor1B=1
HighlightShapeOpacityDivisor2A=3
HighlightShapeOpacityDivisor2B=3
HighlightFontOpacity1=255

BlurTypeNum=1
TopBarBlurType=[#BlurType[#BlurTypeNum]]

;---

TopBarShadow=0
DropdownMenuShadow=1

TopBarFontShadow=0
TopBarFontShadowBlur=2.5

DropdownFontShadow=0
DropdownFontShadowBlur=2.5

;-------------------------
; Font options

FontYposOffset=0
FontSizeOffset=0
IconSizeOffset=0
FontSpaceOffset=0
TitleSpaOffset=0

FontName0=FF DIN Round Pro

FontName1=#DefaultFont#
TopBarFontName=[#FontName[#AltFont[#LanguageNum]]]

TopBarTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*TopBarFontShadowBlur*] | 0,0,0,185
DropdownTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*DropdownFontShadowBlur*] | 0,0,0,100

;---

FontWeight=400
ApplicationFontWeight=600

TopBarTitleCase=None
DegreeSymbol=°
PercentSymbol=%
MusicSymbol=#NotificationPlaying#
MailSymbol=#NotificationMail#

TopBarCharacterSpacing=#FontSpaceOffset# | #FontSpaceOffset#
DropdownCharacterSpacing=#FontSpaceOffset# | #FontSpaceOffset#

TopBarAntiAlias=1
DropdownAntiAlias=#TopBarAntiAlias#

;-------------------------
; Shapes & backgrounds

TopBarCornerMinMax0=1
TopBarCornerMinMax1=4
DropdownCornerMinMax0=1
DropdownCornerMinMax1=8
HighlightCornerMinMax0=0
HighlightCornerMinMax1=4
TopBarRoundCorners=1
DropdownRoundCorners=0
TopBarCorner=([#TopBarCornerMinMax[#TopBarRoundCorners]]*#DroptopSize#)
TopGradientCorner=#TopBarCorner#
DropdownBGCorner=[#DropdownCornerMinMax[#DropdownRoundCorners]]
TopBarHighlightCorner=(#TopBarCorner#*0.83)
DropdownHighlightCorner=(#DropdownBGCorner#*0.83)

CurrentDayStrokeWidth=(2*#DroptopSize#)

TopBarStrokeWidth=(1*#DroptopSize#)
DropdownStrokeWidth=(1*#DroptopSize#)

TopBarStrokeColor=#DropdownFontColor1#
DropdownStrokeColor=#DropdownFontColor1#,#DropdownStrokeOpacity#

TopBarStrokeOpacity=55
DropdownStrokeOpacity=55

HLSelectedShapeNum=1

TopBarHotCornerStrokeWidth=0

;-------------------------

BLANK=1,40,45
