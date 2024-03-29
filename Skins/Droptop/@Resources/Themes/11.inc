[Variables]

AltFont1=0
AltFont2=0
AltFont3=0
AltFont4=0
AltFont5=0
AltFont6=0
AltFont7=0
AltFont8=0
AltFont9=0
AltFont10=0
AltFont11=0
AltFont12=0
AltFont13=0
AltFont14=1
AltFont15=0
AltFont16=0
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

TopBarFontSize=((10*#DroptopSize#)+(#FontSizeOffset#*#DroptopSize#))
TopBarContentXOffset=((8*#DroptopSize#)-((8*#DroptopSize#)%1))
TopBarTitlePadding="((10*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),((0*#DroptopSize#)*(([#AltFont[#LanguageNum]]-1)*-1)),((6*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),0"
TopBarTextYOffset=((2*#DroptopSize#)+(#FontYposOffset#*#DroptopSize#))
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
TopBarHLOffsetY=(0*#DroptopSize#)
TopBarHLOffsetH=(0*#DroptopSize#)
TopBarSkew=(-20*#TopBarHLSkew#)
TopBarIconHOffset=((0*#DroptopSize#)+(#IconSizeOffset#*#DroptopSize#))
TopBarCutout=(0*#DroptopSize#)
TopBarGradientCutout=#TopBarCutout#

;-------------------------

DropdownMenuWidth=((325*#DroptopSize#)-((325*#DroptopSize#)%1))
DropdownItemHeight=((25*#DroptopSize#)-((25*#DroptopSize#)%1))
DropdownItemFontSize=((10*#DroptopSize#)+(#FontSizeOffset#*#DroptopSize#))
DropdownMenuYOffset=(2*#DroptopSize#)
DropdownMenuShapeOffsetH=(0*#DroptopSize#)
DropdownIconPadding=((#DropdownItemHeight#-#IconH#)/2)
DropdownIconXoffset=(6*#DroptopSize#)
DropdownIconYoffset=((4*#DroptopSize#)-((4*#DroptopSize#)%1))
DropdownItemYOffset=((3*#DroptopSize#)-((3*#DroptopSize#)%1))
DropdownItemPadding1=(32*#DroptopSize#)
DropdownItemPadding2=(20*#DroptopSize#)
DropdownItemPaddingY=((2+#FontYposOffset#)*#DroptopSize#)
DropdownTopBottomSpacing=(#DropdownIconYoffset#+#DropdownItemYOffset#+1)
DropdownSubMenuWidth=(215*#DroptopSize#)
DropdownContextMenuYOffset=(0*#DroptopSize#)
DropdownNoIconPadding=(6*#DroptopSize#)
DropdownSysMenuOffset=(2*#DroptopSize#)
DropdownSysAppContentXOffset=(25*#DroptopSize#)
DropdownArrowHighlightW=((23*#DroptopSize#)-((23*#DroptopSize#)%1))
DropdownArrowXOffset=(-1*#DroptopSize#)+(#DropdownMenuCutout#%1)
DropdownArrowXOffsetTray=(0*#DroptopSize#)
DropdownArrowXOffsetRTL=(0*#DroptopSize#)
DropdownScrollButtonYOffset=(0*#DroptopSize#)
DropdownMenuFlatTop=0
DropdownSubMenuXOffset=(6*#DroptopSize#)
DropdownMenuCutout=(1*#DroptopSize#)
DropdownHLOffsetX=((0*#DroptopSize#)-((0*#DroptopSize#)%1))
DropdownMenuLandingHeight=(17*#DroptopSize#)
DropdownBottomButtonOffset=((1*#DroptopSize#)-((1*#DroptopSize#)%1))

;-------------------------
; Colors

ChamLum1=1
ChamLum2=1
ChamLumA=255,255,255
ChamLumB=0,0,0

ChamBG1=204,212,232
ChamBG2=213,215,232
ChamBG3=213,175,208
ChamFG1=90,60,74
ChamFG2=69,56,64

TopBarSolidColor=0

DropdownStringEffect=None
DropdownFontEffectColor=0,0,0

LockSetColorByWallpaperOFF=0

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

ChamTopBarBGColor1=[ChamBG1]
ChamTopBarBGColor2=[ChamBG1]
ChamTopBarBGColor3=[ChamBG1]
ChamDropdownBGColor1=[ChamBG1]
ChamFolderHL=[ChamFG2]
ChamTopBarHL=[ChamFG2]
ChamDropdownFontColor1=[ChamFG1]
ChamDropdownFontColor2=[ChamBG1]
ChamTopBarFontColor1=[ChamFG1]
ChamTopBarFontColor2=[ChamBG1]
ChamDropdownStrokeColor=[ChamFG1],#DropdownStrokeOpacity#
ChamTopBarStrokeColor=[ChamFG2]
ChamTopBarHomeIconColor=[ChamFG1]
ChamTopBarAssistantIconTint1=#ChamTopBarFontColor1#
ChamTopBarAssistantIconTint2=#ChamTopBarFontColor2#
ChamBatteryFillColor=[ChamFG1]
ChamLightOffset=255
ChamDarkOffset=0
ChamLumThreshold=0.5

;-------------------------

