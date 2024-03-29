[Variables]

; --------------------------
; Menu options

TopBarBlur=1
TopBarHideGradient=0
TopBarHideHomeShape=1
TopBarHLSkew=0

DropdownMenuBlur=1
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

DropdownSliderStyle=2

;-------------------------
; Colors

SetColorByWallpaperOFF=1

TopBarBGColor1=1,38,20
TopBarBGColor2=1,38,20
TopBarBGColor3=1,38,20
TopBarFontColor1=15,255,132
TopBarFontColor2=15,255,132
TopBarHLColor1=15,255,132
TopBarAssistantIconTint1=15,255,132
TopBarAssistantIconTint2=15,255,132
TopBarHomeIconColor=15,255,132
TopBarIconGreyscale=0
TopBarBorderTopColor=25,25,25,(92*(#TopBarOpacity1#/255))
TopBarBorderBottomColor=0,0,0,(43*(#TopBarOpacity1#/255))

DropdownBGColor1=1,38,20
DropdownFontColor1=15,255,132
DropdownFontColor2=15,255,132
DropdownItemHL=15,255,132
DropdownIconTint=255,255,255
DropdownIconGreyscale=0
DropdownSliderColor=#DropdownItemHL#

BatteryChargingColor=47,207,91
BatteryDyingColor=233,86,70

;-------------------------
; Opacities

TopBarOpacity1=215
TopBarGradientOpacity1=76.5
TopBarHLOpacity1=15
TopBarHLOpacity2=85
TopBarHLOpacity2Offset=0
TopBarTitleOpacity=255

DropdownMenuOpacity1=235
DropdownHLOpacity1=15
DropdownHLOpacity2=85
DropdownHLOpacity2Offset=0
DropdownItemOpacity=255

HighlightShapeOpacity=255
HighlightShapeOpacityDivisor1A=5
HighlightShapeOpacityDivisor1B=5
HighlightShapeOpacityDivisor2A=5
HighlightShapeOpacityDivisor2B=3
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
FontSpaceOffset=0
TitleSpaOffset=0

FontName0=Glass TTY VT220

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

TopBarCornerMinMax0=0
TopBarCornerMinMax1=6
DropdownCornerMinMax0=1
DropdownCornerMinMax1=8
HighlightCornerMinMax0=0
HighlightCornerMinMax1=5
TopBarRoundCorners=1
DropdownRoundCorners=1
TopBarCorner=([#TopBarCornerMinMax[#TopBarRoundCorners]]*#DroptopSize#)
TopGradientCorner=#TopBarCorner#
DropdownBGCorner=[#DropdownCornerMinMax[#DropdownRoundCorners]]
TopBarHighlightCorner=(#TopBarCorner#*0.83)
DropdownHighlightCorner=(#DropdownBGCorner#*0.83)

CurrentDayStrokeWidth=(2*#DroptopSize#)

TopBarStrokeWidth=(1*#DroptopSize#)
DropdownStrokeWidth=(1*#DroptopSize#)

TopBarStrokeColor=#TopBarFontColor1#
DropdownStrokeColor=#DropdownFontColor1#,#DropdownStrokeOpacity#

TopBarStrokeOpacity=255
DropdownStrokeOpacity=255

HLSelectedShapeNum=2

TopBarHotCornerStrokeWidth=#TopBarStrokeWidth#
BLANK=215

;-------------------------
