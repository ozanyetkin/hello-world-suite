[Variables]

; --------------------------
; Menu options

TopBarBlur=1
TopBarHideGradient=1
TopBarHideHomeShape=1
TopBarHLSkew=0

DropdownMenuBlur=1
DropdownArrowStyle=2

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

SetColorByWallpaperOFF=1

TopBarBGColor1=154,207,130
TopBarBGColor2=154,207,130
TopBarBGColor3=154,207,130
TopBarFontColor1=21,30,21
TopBarFontColor2=230,255,214
TopBarHLColor1=49,105,82
TopBarAssistantIconTint1=21,30,21
TopBarAssistantIconTint2=230,255,214
TopBarHomeIconColor=21,30,21
TopBarIconGreyscale=0
TopBarBorderTopColor=55,55,55,(55*(#TopBarOpacity1#/255))
TopBarBorderBottomColor=55,55,55,(26*(#TopBarOpacity1#/255))

DropdownBGColor1=230,255,214
DropdownFontColor1=21,30,21
DropdownFontColor2=230,255,214
DropdownItemHL=49,105,82
DropdownIconTint=255,255,255
DropdownIconGreyscale=0
DropdownSliderColor=#DropdownItemHL#

BatteryChargingColor=47,207,91
BatteryDyingColor=233,86,70

;-------------------------
; Opacities

TopBarOpacity1=155
TopBarGradientOpacity1=76.5
TopBarHLOpacity1=155
TopBarHLOpacity2=85
TopBarHLOpacity2Offset=0
TopBarTitleOpacity=255

DropdownMenuOpacity1=155
DropdownHLOpacity1=155
DropdownHLOpacity2=85
DropdownHLOpacity2Offset=0
DropdownItemOpacity=255

HighlightShapeOpacity=215
HighlightShapeOpacityDivisor1A=1
HighlightShapeOpacityDivisor1B=1
HighlightShapeOpacityDivisor2A=3
HighlightShapeOpacityDivisor2B=3
HighlightFontOpacity1=255

BlurTypeNum=1
TopBarBlurType=[#BlurType[#BlurTypeNum]]

;---

TopBarShadow=0
DropdownMenuShadow=0

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

FontName0=Diary of an 8-bit mage

FontName1=#DefaultFont#
TopBarFontName=[#FontName[#AltFont[#LanguageNum]]]

TopBarTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*TopBarFontShadowBlur*] | 0,0,0,185
DropdownTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*DropdownFontShadowBlur*] | 0,0,0,100

;---

FontWeight=400
ApplicationFontWeight=600

TopBarTitleCase=None
DegreeSymbol=°
PercentSymbol="%"
MusicSymbol=#NotificationPlaying#
MailSymbol=#NotificationMail#

TopBarCharacterSpacing=#FontSpaceOffset# | #FontSpaceOffset#
DropdownCharacterSpacing=#FontSpaceOffset# | #FontSpaceOffset#

TopBarAntiAlias=0
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
DropdownRoundCorners=1
TopBarCorner=([#TopBarCornerMinMax[#TopBarRoundCorners]]*#DroptopSize#)
TopGradientCorner=#TopBarCorner#
DropdownBGCorner=[#DropdownCornerMinMax[#DropdownRoundCorners]]
TopBarHighlightCorner=(0*#DroptopSize#)
DropdownHighlightCorner=(0*#DroptopSize#)

CurrentDayStrokeWidth=(2*#DroptopSize#)

TopBarStrokeWidth=(2*#DroptopSize#)
DropdownStrokeWidth=(2*#DroptopSize#)

TopBarStrokeColor=#DropdownFontColor1#
DropdownStrokeColor=#DropdownFontColor1#,#DropdownStrokeOpacity#

TopBarStrokeOpacity=255
DropdownStrokeOpacity=255

HLSelectedShapeNum=1

TopBarHotCornerStrokeWidth=0

;-------------------------

BLANK=155
