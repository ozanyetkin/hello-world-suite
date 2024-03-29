[Variables]

; --------------------------
; Menu options

TopBarBlur=1
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

TopBarBGColor1=31,31,31
TopBarBGColor2=31,31,31
TopBarBGColor3=31,31,31
TopBarFontColor1=255,255,255
TopBarFontColor2=255,255,255
TopBarHLColor1=255,255,255
TopBarAssistantIconTint1=255,255,255
TopBarAssistantIconTint2=255,255,255
TopBarHomeIconColor=255,255,255
TopBarIconGreyscale=0
TopBarBorderTopColor=25,25,25,(105*(#TopBarOpacity1#/255))
TopBarBorderBottomColor=0,0,0,(52*(#TopBarOpacity1#/255))

DropdownBGColor1=31,31,31
DropdownFontColor1=255,255,255
DropdownFontColor2=255,255,255
DropdownItemHL=255,255,255
DropdownIconTint=255,255,255
DropdownIconGreyscale=0
DropdownSliderColor=#DropdownItemHL#

BatteryChargingColor=47,207,91
BatteryDyingColor=233,86,70

;-------------------------
; Opacities

TopBarOpacity1=185
TopBarGradientOpacity1=128
TopBarHLOpacity1=35
TopBarHLOpacity2=85
TopBarHLOpacity2Offset=0
TopBarTitleOpacity=255

DropdownMenuOpacity1=255
DropdownHLOpacity1=35
DropdownHLOpacity2=85
DropdownHLOpacity2Offset=0
DropdownItemOpacity=255

HighlightShapeOpacity=45
HighlightShapeOpacityDivisor1A=1
HighlightShapeOpacityDivisor1B=1
HighlightShapeOpacityDivisor2A=1
HighlightShapeOpacityDivisor2B=1
HighlightFontOpacity1=255

BlurTypeNum=0
TopBarBlurType=[#BlurType[#BlurTypeNum]]

;---

TopBarShadow=0
DropdownMenuShadow=0

TopBarFontShadow=1
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

FontName0=Product Sans

FontName1=#DefaultFont#
TopBarFontName=[#FontName[#AltFont[#LanguageNum]]]

TopBarTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*TopBarFontShadowBlur*] | 0,0,0,185,185
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

TopBarCornerMinMax0=0
TopBarCornerMinMax1=10
DropdownCornerMinMax0=2
DropdownCornerMinMax1=8
HighlightCornerMinMax0=0
HighlightCornerMinMax1=6
TopBarRoundCorners=1
DropdownRoundCorners=1
TopBarCorner=[#TopBarCornerMinMax[#TopBarRoundCorners]]
TopGradientCorner=#TopBarCorner#
DropdownBGCorner=[#DropdownCornerMinMax[#DropdownRoundCorners]]
TopBarHighlightCorner=#TopBarCorner#
DropdownHighlightCorner=([#DropdownCornerMinMax[#DropdownRoundCorners]]*0.83)

CurrentDayStrokeWidth=(2*#DroptopSize#)

TopBarStrokeWidth=(0*#DroptopSize#)
DropdownStrokeWidth=(1*#DroptopSize#)

TopBarStrokeColor=#DropdownFontColor1#
DropdownStrokeColor=0,0,0,#DropdownStrokeOpacity#

TopBarStrokeOpacity=0
DropdownStrokeOpacity=30

HLSelectedShapeNum=1

TopBarHotCornerStrokeWidth=#TopBarStrokeWidth#

;-------------------------

BLANK=185
