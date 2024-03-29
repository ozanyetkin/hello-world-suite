[Rainmeter]

[Variables]

;----------------------------------------------------
; # # ADD BACKGROUND PROCESSES BELOW # # # # # # # #
; # # Measures that run even when the app isn't open
;----------------------------------------------------

[PhanlockRecycleSize]
Measure=RecycleManager
RecycleType=Size
Drives=ALL
IfCondition=PhanlockRecycleSize <= 214748364
IfTrueAction=[!SetOption CustomApp#Recycle_Bin-Phanlock# ImageName "#SKINSPATH#Droptop Community Apps\Apps\[#CustomAppID[#Recycle_Bin-Phanlock]]\Button\#TopIconSize#\Button0[#TopIconShadows[#TopBarFontShadow][#ChamLum1][#ReverseDarkLight]]].png" "Droptop\DropdownBar"]
IfCondition2=PhanlockRecycleSize > 214748364
IfTrueAction2=[!SetOption CustomApp#Recycle_Bin-Phanlock# ImageName "#SKINSPATH#Droptop Community Apps\Apps\[#CustomAppID[#Recycle_Bin-Phanlock]]\Button\#TopIconSize#\Button1[#TopIconShadows[#TopBarFontShadow][#ChamLum1][#ReverseDarkLight]]].png" "Droptop\DropdownBar"]
IfCondition3=PhanlockRecycleSize > 429496729
IfTrueAction3=[!SetOption CustomApp#Recycle_Bin-Phanlock# ImageName "#SKINSPATH#Droptop Community Apps\Apps\[#CustomAppID[#Recycle_Bin-Phanlock]]\Button\#TopIconSize#\Button2[#TopIconShadows[#TopBarFontShadow][#ChamLum1][#ReverseDarkLight]]].png" "Droptop\DropdownBar"]
IfCondition4=PhanlockRecycleSize > 644245094
IfTrueAction4=[!SetOption CustomApp#Recycle_Bin-Phanlock# ImageName "#SKINSPATH#Droptop Community Apps\Apps\[#CustomAppID[#Recycle_Bin-Phanlock]]\Button\#TopIconSize#\Button3[#TopIconShadows[#TopBarFontShadow][#ChamLum1][#ReverseDarkLight]]].png" "Droptop\DropdownBar"]
IfCondition5=PhanlockRecycleSize > 858993459
IfTrueAction5=[!SetOption CustomApp#Recycle_Bin-Phanlock# ImageName "#SKINSPATH#Droptop Community Apps\Apps\[#CustomAppID[#Recycle_Bin-Phanlock]]\Button\#TopIconSize#\Button4[#TopIconShadows[#TopBarFontShadow][#ChamLum1][#ReverseDarkLight]]].png" "Droptop\DropdownBar"]
IfCondition6=PhanlockRecycleSize > 1073741824
IfTrueAction6=[!SetOption CustomApp#Recycle_Bin-Phanlock# ImageName "#SKINSPATH#Droptop Community Apps\Apps\[#CustomAppID[#Recycle_Bin-Phanlock]]\Button\#TopIconSize#\Button5[#TopIconShadows[#TopBarFontShadow][#ChamLum1][#ReverseDarkLight]]].png" "Droptop\DropdownBar"]
IfCondition7=1=1
IfTrueAction7=[!UpdateMeter CustomApp#Recycle_Bin-Phanlock# "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
DynamicVariables=1
UpdateDivider=30