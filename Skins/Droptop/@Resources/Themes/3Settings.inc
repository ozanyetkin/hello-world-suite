[Variables]

; --------------------------
; Menu options

TopBarBlur=1
TopBarHideGradient=1
TopBarHideHomeShape=1
TopBarHLSkew=0

DropdownMenuBlur=1
DropdownArrowStyle=1

;---

IconStyle=2

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

TopBarBGColor1=37,41,45
TopBarBGColor2=37,41,45
TopBarBGColor3=40,43,49
TopBarFontColor1=255,255,255
TopBarFontColor2=255,255,255
TopBarHLColor1=255,255,255
TopBarAssistantIconTint1=255,255,255
TopBarAssistantIconTint2=255,255,255
TopBarHomeIconColor=255,255,255
TopBarIconGreyscale=0
TopBarBorderTopColor=25,25,25,(92*(#TopBarOpacity1#/255))
TopBarBorderBottomColor=0,0,0,(43*(#TopBarOpacity1#/255))

DropdownBGColor1=0,0,0
DropdownFontColor1=255,255,255
DropdownFontColor2=255,255,255
DropdownItemHL=0,125,255
DropdownIconTint=255,255,255
DropdownIconGreyscale=0
DropdownSliderColor=255,255,255

BatteryChargingColor=47,207,91
BatteryDyingColor=233,86,70

;-------------------------
; Opacities

TopBarOpacity1=195
TopBarGradientOpacity1=76.5
TopBarHLOpacity1=255
TopBarHLOpacity2=85
TopBarHLOpacity2Offset=0
TopBarTitleOpacity=255

DropdownMenuOpacity1=185
DropdownHLOpacity1=255
DropdownHLOpacity2=85
DropdownHLOpacity2Offset=0
DropdownItemOpacity=255

HighlightShapeOpacity=255
HighlightShapeOpacityDivisor1A=5
HighlightShapeOpacityDivisor1B=1
HighlightShapeOpacityDivisor2A=5
HighlightShapeOpacityDivisor2B=2
HighlightFontOpacity1=255

BlurTypeNum=1
TopBarBlurType=Blur

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
TitleSpaOffset=0
FontSpaceOffset=0

FontName0=SF Pro Display

FontName1=#DefaultFont#
TopBarFontName=[#FontName[#AltFont[#LanguageNum]]]

TopBarTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*TopBarFontShadowBlur*] | 0,0,0,185
DropdownTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*DropdownFontShadowBlur*] | 0,0,0,100

;---

FontWeight=200
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
TopBarCornerMinMax1=6
DropdownCornerMinMax0=0
DropdownCornerMinMax1=8
HighlightCornerMinMax0=0
HighlightCornerMinMax1=6
TopBarRoundCorners=0
DropdownRoundCorners=1
TopBarCorner=([#TopBarCornerMinMax[#TopBarRoundCorners]]*#DroptopSize#)
TopGradientCorner=#TopBarCorner#
DropdownBGCorner=[#DropdownCornerMinMax[#DropdownRoundCorners]]
TopBarHighlightCorner=(#HighlightCornerMinMax1#*#DroptopSize#)
DropdownHighlightCorner=(#HighlightCornerMinMax1#*#DroptopSize#)

CurrentDayStrokeWidth=(2*#DroptopSize#)

TopBarStrokeWidth=(0*#DroptopSize#)
DropdownStrokeWidth=1

TopBarStrokeColor=#DropdownFontColor1#
DropdownStrokeColor=0,0,0,#DropdownStrokeOpacity#

TopBarStrokeOpacity=0
DropdownStrokeOpacity=60

HLSelectedShapeNum=1

TopBarHotCornerStrokeWidth=#TopBarStrokeWidth#
BLANK=195

;-------------------------
