[Variables]

AltFont1=0
AltFont2=0
AltFont3=0
AltFont4=1
AltFont5=0
AltFont6=0
AltFont7=0
AltFont8=0
AltFont9=0
AltFont10=0
AltFont11=0
AltFont12=0
AltFont13=1
AltFont14=1
AltFont15=0
AltFont16=1
AltFont17=1
AltFont18=1
AltFont19=1
AltFont20=1
AltFont21=0
AltFont22=0
AltFont23=0
AltFont24=0
AltFont25=0

;-------------------------

TopBarFontSize=((12*#DroptopSize#)+(#FontSizeOffset#*#DroptopSize#))
TopBarContentXOffset=((6*#DroptopSize#)-((6*#DroptopSize#)%1))
TopBarTitlePadding="((9*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),((0*#DroptopSize#)*(([#AltFont[#LanguageNum]]-1)*-1)),((5*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),0"
TopBarTextYOffset=((1*#DroptopSize#)+(#FontYposOffset#*#DroptopSize#))
TopBarSysIconYOffset=(0*#DroptopSize#)
TopBarSysIconTextOffset=((30*#DroptopSize#)+(#IconSizeOffset#*#DroptopSize#))
TopBarSysBatteryIconOffset=(3*#DroptopSize#)
TopBarSysBatteryTextOffset=(8*#DroptopSize#)
TopBarSysTextYPadding=((0*#DroptopSize#)*(([#AltFont[#LanguageNum]]-1)*-1))
TopBarSysTextWPadding=(6*#DroptopSize#)
TopBarSysAppWPadding=(0*#DroptopSize#)
TopBarRoundTop=0
TopBarBorderTopH=0
TopBarBorderBottomH=0
TopBarHLOffsetY=(1.25*#DroptopSize#)
TopBarHLOffsetH=(1*#DroptopSize#)
TopBarSkew=(-20*#TopBarHLSkew#)
TopBarIconHOffset=((0*#DroptopSize#)+(#IconSizeOffset#*#DroptopSize#))
TopBarCutout=(1*#DroptopSize#)
TopBarGradientCutout=#TopBarCutout#

;-------------------------

DropdownMenuWidth=((370*#DroptopSize#)-((370*#DroptopSize#)%1))
DropdownItemHeight=((27*#DroptopSize#)-((27*#DroptopSize#)%1))
DropdownItemFontSize=((12*#DroptopSize#)+(#FontSizeOffset#*#DroptopSize#))
DropdownMenuYOffset=(3*#DroptopSize#)
DropdownMenuShapeOffsetH=(0*#DroptopSize#)
DropdownIconPadding=((#DropdownItemHeight#-#IconH#)/2)
DropdownIconXoffset=(8*#DroptopSize#)
DropdownIconYoffset=((2*#DroptopSize#)-((2*#DroptopSize#)%1))
DropdownItemYOffset=((3*#DroptopSize#)-((3*#DroptopSize#)%1))
DropdownItemPadding1=(34*#DroptopSize#)
DropdownItemPadding2=(20*#DroptopSize#)
DropdownItemPaddingY=((2+#FontYposOffset#)*#DroptopSize#)
DropdownTopBottomSpacing=(#DropdownIconYoffset#+#DropdownItemYOffset#+1)
DropdownSubMenuWidth=(215*#DroptopSize#)
DropdownContextMenuYOffset=(3*#DroptopSize#)
DropdownNoIconPadding=(6*#DroptopSize#)
DropdownSysMenuOffset=(5*#DroptopSize#)
DropdownSysAppContentXOffset=(48*#DroptopSize#)
DropdownArrowHighlightW=((21*#DroptopSize#)-((21*#DroptopSize#)%1))
DropdownArrowXOffset=(1*#DroptopSize#)+(#DropdownMenuCutout#%1)
DropdownArrowXOffsetTray=(0*#DroptopSize#)
DropdownArrowXOffsetRTL=(-1*#DroptopSize#)
DropdownScrollButtonYOffset=(0*#DroptopSize#)
DropdownMenuFlatTop=0
DropdownSubMenuXOffset=(4*#DroptopSize#)
DropdownMenuCutout=(1*#DroptopSize#)
DropdownHLOffsetX=((3*#DroptopSize#)-((3*#DroptopSize#)%1))
DropdownMenuLandingHeight=(20*#DroptopSize#)
DropdownBottomButtonOffset=((1*#DroptopSize#)-((1*#DroptopSize#)%1))

;-------------------------
; Colors

ChamLum1=0
ChamLum2=0
ChamLumA=0,0,0
ChamLumB=255,255,255

ChamBG1=36,40,44
ChamBG2=34,37,41
ChamBG3=42,45,50
ChamFG1=132,136,137
ChamFG2=149,149,147

TopBarSolidColor=0

DropdownStringEffect=None
DropdownFontEffectColor=0,0,0

LockSetColorByWallpaperOFF=1

LockReverseDarkLightTopBar=0
LockReverseDarkLightDropdownMenu=0

;---
; ColorMode/Charging/BatteryLow
BatteryFillColor000=[#*TopBarFontColor1*]
BatteryFillColor001=[#*TopBarFontColor1*]
BatteryFillColor010=[#*TopBarFontColor1*]
BatteryFillColor011=[#*TopBarFontColor1*]

BatteryFillColor100=[#*TopBarFontColor1*]
BatteryFillColor101=#BatteryDyingColor#
BatteryFillColor110=#BatteryChargingColor#
BatteryFillColor111=#BatteryDyingColor#

;---

BatteryFillColor000B=[#*TopBarFontColor2*]
BatteryFillColor001B=[#*TopBarFontColor2*]
BatteryFillColor010B=[#*TopBarFontColor2*]
BatteryFillColor011B=[#*TopBarFontColor2*]

BatteryFillColor100B=[#*TopBarFontColor2*]
BatteryFillColor101B=#BatteryDyingColor#
BatteryFillColor110B=#BatteryChargingColor#
BatteryFillColor111B=#BatteryDyingColor#

;-------------------------
; Opacities

BatteryFillOpacity=355

;-------------------------
; Shapes & backgrounds

DividerX=(#DropdownStrokeWidth#+1)
DividerSpace=(#DropdownIconYoffset#+#DropdownItemYOffset#)
DividerHeight=(1*#DroptopSize#)

DividerShape=Rectangle (#DividerX#+1),0,(#DropdownMenuWidth#-(#DividerX#*2)),#DividerHeight#,(0*#DroptopSize#) | Fill Color #DropdownFontColor1#,40 | StrokeWidth 0

HomeShape=Rectangle #TopBarContentXOffset#,(#TopBarHLOffsetH#+#TopBarHLOffsetY#),[Home:W],(#TopHeight#-(#TopBarCutout#*2)),#TopBarHighlightCorner# | StrokeWidth 0 | Stroke Color #TopBarBGColor1# | Skew #TopBarSkew#,0 | Extend HomeFillColor#TopBarHideHomeShape#

FlatTopShape=Rectangle #DropdownMenuCutout#,0,((#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2))*#DropdownMenuFlatTop#),((#DropdownBGCorner#+2)*#DropdownMenuFlatTop#),0 | Fill Color 255,55,55 | StrokeWidth 0

;-------------------------
; Chameleon settings

ChamTopBarBGColor1=1,38,20
ChamTopBarBGColor2=1,38,20
ChamTopBarBGColor3=1,38,20
ChamDropdownBGColor1=1,38,20
ChamFolderHL=15,255,132
ChamTopBarHL=15,255,132
ChamDropdownFontColor1=15,255,132
ChamDropdownFontColor2=15,255,132
ChamTopBarFontColor1=15,255,132
ChamTopBarFontColor2=15,255,132
ChamDropdownStrokeColor=15,255,132,#DropdownStrokeOpacity#
ChamTopBarStrokeColor=15,255,132
ChamTopBarHomeIconColor=15,255,132
ChamTopBarAssistantIconTint1=#ChamTopBarFontColor1#
ChamTopBarAssistantIconTint2=#ChamTopBarFontColor2#
ChamBatteryFillColor=15,255,132
ChamLightOffset=255
ChamDarkOffset=0
ChamLumThreshold=0.5

;-------------------------

