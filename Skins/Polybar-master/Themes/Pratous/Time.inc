[Variables]
Time_X=1870
;Left, Right or Center
Time_Anchor=Right

[Metadata]
Name=Pratous\\Clock
Author=reddit.com/u/khanhas
Description=Clock with material icon. Click to activate Windows 10 Alarm & Clock app.

[TimeAnchor]
Measure=String
String = #Time_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption TimeIcon X "(#Bar_OffsetX#+#*Time_X*#-([*TimeIcon:W*]+[*Time:W*]+10)/2)"][!SetOption Time X 10R]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption TimeIcon StringAlign RightCenter][!SetOption Time StringAlign RightCenter][!SetOption TimeIcon X "([*Time:X*]-10)"][!SetOption Time X "(#Bar_OffsetX#+#*Time_X*#)"]

[MeasureTime]
Measure=Time
Format=%H:%M

[TimeIcon]
Meter=String
Text=
FontFace=FontAwesome
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Time_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1

[Time]
Meter=String
MeasureName=MeasureTime
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=10R
Y=r
DynamicVariables=1
LeftMouseUpAction=[explorer.exe shell:appsFolder\Microsoft.WindowsAlarms_8wekyb3d8bbwe!App]
