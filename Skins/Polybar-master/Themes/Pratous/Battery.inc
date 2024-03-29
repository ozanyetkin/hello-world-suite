[Variables]
Battery_X =1607
;Left, Right or Center
Battery_Anchor=Center

[Metadata]
Name=Paper\\Battery
Author=reddit.com/u/khanhas
Description=Display battery level.

[BatteryAnchor]
Measure=String
String = #Battery_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption BatteryIcon X "(#Bar_OffsetX#+#*Battery_X*#-([*BatteryIcon:W*]+[*Battery:W*]+10)/2)"][!SetOption Battery X 10R]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption BatteryIcon StringAlign RightCenter][!SetOption Battery StringAlign RightCenter][!SetOption BatteryIcon X "([*Battery:X*]-10)"][!SetOption Battery X "(#Bar_OffsetX#+#*Battery_X*#)"]

[BatteryLevel]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Percent
IfCondition=(BatteryLevel <= 2)
IfTrueAction=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition2=(BatteryLevel <= 10) && (BatteryLevel > 2)
IfTrueAction2=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition3=(BatteryLevel <= 20) && (BatteryLevel > 10)
IfTrueAction3=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition4=(BatteryLevel <= 30) && (BatteryLevel > 20)
IfTrueAction4=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition5=(BatteryLevel <= 40) && (BatteryLevel > 30)
IfTrueAction5=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition6=(BatteryLevel <= 50) && (BatteryLevel > 40)
IfTrueAction6=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition7=(BatteryLevel <= 60) && (BatteryLevel > 50)
IfTrueAction7=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition8=(BatteryLevel <= 70) && (BatteryLevel > 60)
IfTrueAction8=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition9=(BatteryLevel <= 80) && (BatteryLevel > 70)
IfTrueAction9=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition10=(BatteryLevel <= 90) && (BatteryLevel > 80)
IfTrueAction10=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition11=(BatteryLevel < 100) && (BatteryLevel > 90)
IfTrueAction11=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]
IfCondition12=(BatteryLevel = 100)
IfTrueAction12=[!SetOption BatteryIcon Text ""][!UpdateMeterGroup Battery][!Redraw]

[BatteryIcon]
Meter=String
FontFace=Segoe MDL2 Assets
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Battery_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
Group=Battery
DynamicVariables=1

[Battery]
Meter=String
MeasureName=BatteryLevel
Postfix=%
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=10R
Y=r
Group=Battery
DynamicVariables=1
