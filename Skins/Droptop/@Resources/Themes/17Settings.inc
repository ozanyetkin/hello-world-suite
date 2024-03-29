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

DropdownSliderStyle=3

;-------------------------
; Colors

SetColorByWallpaperOFF=0

TopBarBGColor1=204,212,232
TopBarBGColor2=213,214,231
TopBarBGColor3=222,205,224
TopBarFontColor1=0,0,0
TopBarFontColor2=204,212,232
TopBarHLColor1=67,55,63
TopBarAssistantIconTint1=0,0,0
TopBarAssistantIconTint2=204,212,232
TopBarHomeIconColor=0,0,0
TopBarIconGreyscale=0
TopBarBorderTopColor=25,25,25,(166*(#TopBarOpacity1#/255))
TopBarBorderBottomColor=0,0,0,(78*(#TopBarOpacity1#/255))

DropdownBGColor1=204,212,232
DropdownFontColor1=0,0,0
DropdownFontColor2=204,212,232
DropdownItemHL=67,55,63
DropdownIconTint=255,255,255
DropdownIconGreyscale=0
DropdownSliderColor=#DropdownItemHL#

BatteryChargingColor=47,207,91
BatteryDyingColor=233,86,70

;-------------------------
; Opacities

TopBarOpacity1=128
TopBarGradientOpacity1=76.5
TopBarHLOpacity1=255
TopBarHLOpacity2=85
TopBarHLOpacity2Offset=0
TopBarTitleOpacity=255

DropdownMenuOpacity1=200
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

FontName0=Montserrat

FontName1=#DefaultFont#
TopBarFontName=[#FontName[#AltFont[#LanguageNum]]]

TopBarTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*TopBarFontShadowBlur*] | 0,0,0,185
DropdownTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*DropdownFontShadowBlur*] | 0,0,0,100

;---

FontWeight=300
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
HighlightCornerMinMax1=6
TopBarRoundCorners=1
DropdownRoundCorners=0
TopBarCorner=([#TopBarCornerMinMax[#TopBarRoundCorners]]*#DroptopSize#)
TopGradientCorner=(0*#DroptopSize#)
DropdownBGCorner=[#DropdownCornerMinMax[#DropdownRoundCorners]]
TopBarHighlightCorner=(0*#DroptopSize#)
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

BLANK=200
