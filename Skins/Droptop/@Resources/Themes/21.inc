[Variables]

AltFont1=0
AltFont2=0
AltFont3=0
AltFont4=0
AltFont5=0
AltFont6=0
AltFont7=0
AltFont8=1
AltFont9=0
AltFont10=0
AltFont11=0
AltFont12=0
AltFont13=0
AltFont14=1
AltFont15=0
AltFont16=0
AltFont17=0
AltFont18=0
AltFont19=1
AltFont20=1
AltFont21=0
AltFont22=0
AltFont23=0
AltFont24=0
AltFont25=0

;-------------------------

TopBarFontSize=((9*#DroptopSize#)+(#FontSizeOffset#*#DroptopSize#))
TopBarContentXOffset=((30*#DroptopSize#)-((30*#DroptopSize#)%1))
TopBarTitlePadding="((8*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),((2*#DroptopSize#)*(([#AltFont[#LanguageNum]]-1)*-1)),((8*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),0"
TopBarTextYOffset=((0*#DroptopSize#)+(#FontYposOffset#*#DroptopSize#))
TopBarSysIconYOffset=(0*#DroptopSize#)
TopBarSysIconTextOffset=((31*#DroptopSize#)+(#IconSizeOffset#*#DroptopSize#))
TopBarSysBatteryIconOffset=(3*#DroptopSize#)
TopBarSysBatteryTextOffset=(8*#DroptopSize#)
TopBarSysTextYPadding=((2*#DroptopSize#)*(([#AltFont[#LanguageNum]]-1)*-1))
TopBarSysTextWPadding=(6*#DroptopSize#)
TopBarSysAppWPadding=(0*#DroptopSize#)
TopBarRoundTop=1
TopBarBorderTopH=0
TopBarBorderBottomH=0
TopBarHLOffsetY=(6*#DroptopSize#)
TopBarHLOffsetH=(0*#DroptopSize#)
TopBarSkew=(-20*#TopBarHLSkew#)
TopBarIconHOffset=((-16*#DroptopSize#)+(#IconSizeOffset#*#DroptopSize#))
TopBarCutout=(6*#DroptopSize#)
TopBarGradientCutout=(6*#DroptopSize#)

;-------------------------

DropdownMenuWidth=((275*#DroptopSize#)-((275*#DroptopSize#)%1))
DropdownItemHeight=((26*#DroptopSize#)-((26*#DroptopSize#)%1))
DropdownItemFontSize=((8*#DroptopSize#)+(#FontSizeOffset#*#DroptopSize#))
DropdownMenuYOffset=(0*#DroptopSize#)
DropdownMenuShapeOffsetH=(0*#DroptopSize#)
DropdownIconPadding=((#DropdownItemHeight#-#IconH#)/2)
DropdownIconXoffset=(2*#DroptopSize#)
DropdownIconYoffset=((2*#DroptopSize#)-((2*#DroptopSize#)%1))
DropdownItemYOffset=((4*#DroptopSize#)-((4*#DroptopSize#)%1))
DropdownItemPadding1=(26*#DroptopSize#)
DropdownItemPadding2=(20*#DroptopSize#)
DropdownItemPaddingY=((1+#FontYposOffset#)*#DroptopSize#)
DropdownTopBottomSpacing=(#DropdownIconYoffset#+#DropdownItemYOffset#+1)
DropdownSubMenuWidth=(155*#DroptopSize#)
DropdownContextMenuYOffset=(3*#DroptopSize#)
DropdownNoIconPadding=(6*#DroptopSize#)
DropdownSysMenuOffset=(2*#DroptopSize#)
DropdownSysAppContentXOffset=(0*#DroptopSize#)
DropdownArrowHighlightW=((20*#DroptopSize#)-((20*#DroptopSize#)%1))
DropdownArrowXOffset=(0*#DroptopSize#)+(#DropdownMenuCutout#%1)
DropdownArrowXOffsetTray=(-1*#DroptopSize#)
DropdownArrowXOffsetRTL=(0*#DroptopSize#)
DropdownScrollButtonYOffset=(0*#DroptopSize#)
DropdownMenuFlatTop=0
DropdownSubMenuXOffset=(5*#DroptopSize#)
DropdownMenuCutout=(1*#DroptopSize#)
DropdownHLOffsetX=((0*#DroptopSize#)-((0*#DroptopSize#)%1))
DropdownMenuLandingHeight=(20*#DroptopSize#)
DropdownBottomButtonOffset=((1*#DroptopSize#)-((1*#DroptopSize#)%1))

;-------------------------
; Colors

ChamLum1=0
ChamLum2=0
ChamLumA=0,0,0
ChamLumB=255,255,255

ChamBG1=36,40,45
ChamBG2=33,36,40
ChamBG3=41,44,49
ChamFG1=149,150,148
ChamFG2=132,137,138

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

ChamTopBarBGColor1=35,44,61
ChamTopBarBGColor2=35,44,61
ChamTopBarBGColor3=35,44,61
ChamDropdownBGColor1=35,44,61
ChamFolderHL=251,72,72
ChamTopBarHL=251,72,72
ChamDropdownFontColor1=255,255,255
ChamDropdownFontColor2=255,255,255
ChamTopBarFontColor1=255,255,255
ChamTopBarFontColor2=255,255,255
ChamDropdownStrokeColor=0,0,0,#DropdownStrokeOpacity#
ChamTopBarStrokeColor=0,0,0
ChamTopBarHomeIconColor=255,255,255
ChamTopBarAssistantIconTint1=#ChamTopBarFontColor1#
ChamTopBarAssistantIconTint2=#ChamTopBarFontColor2#
ChamBatteryFillColor=255,255,255
ChamLightOffset=255
ChamDarkOffset=0
ChamLumThreshold=0.5

;-------------------------

