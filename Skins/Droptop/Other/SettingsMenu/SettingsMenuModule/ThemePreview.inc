[Rainmeter]

[Variables]
SettingsMenuNumber=1.2.1

[MeasureSupporter]
Measure=Calc
IfCondition=(#Supporter#=0) && (#SettingsMenuIndex#>4) && (#SettingsMenuIndex#<23)
IfTrueAction=[!SetOption 1 Text "#SettingsUpdateText4#"][!SetOption 1 LeftMouseDownAction """["https://gumroad.com/l/droptop"]#*CloseSettingsMenu*#"""]
UpdateDivider=-1

[ThemeImageContainer]
Meter=Shape
Shape=Rectangle 0,0,(#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2)),84,#DropdownBGCorner# | Fill Color 0,0,0 | StrokeWidth 0
X=#DropdownMenuCutout#r
Y=([Background:YH]+(#DropdownMenuCutout#+(2*#DroptopSize#))+1)
DynamicVariables=1
UpdateDivider=-1

[ThemeImage]
Meter=Image
ImagePath="#@#Images\ThemePreviews\"
ImageName=#SettingsMenuIndex#
Container=ThemeImageContainer
UpdateDivider=-1
