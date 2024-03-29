[Variables]
date_x=1796
;Left, Right or Center
Date_Anchor=right

[Metadata]
Name=Pratous\\Date
Author=reddit.com/u/falconwingz
Description=Display date. Click to activate Calendar View with Google Calendar and Microsoft Outlook support.

[DateAnchor]
Measure=String
String = #Date_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption DateIcon X "(#Bar_OffsetX#+#*Date_X*#-([*DateIcon:W*]+[*Date:W*]+10)/2)"][!SetOption Date X 10R]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption DateIcon StringAlign RightCenter][!SetOption Date StringAlign RightCenter][!SetOption DateIcon X "([*Date:X*]-10)"][!SetOption Date X "(#Bar_OffsetX#+#*Date_X*#)"]

[DateParseSchedule]
Measure=Script
ScriptFile=#@#Scripts\Calendar_Common_Script.lua

[DateScheduleFetch]
Measure=Plugin
Plugin=WebParser
URL=
Download=1
DownloadFile=calendarSchedule.txt
Debug=1
FinishAction=[!CommandMeasure DateParseSchedule "moduleNotification = true; notificationMeter = 'DateNotification'; parseSchedule()"]
UpdateRate=1000

[MeasureDate]
Measure=Time
Format=%a, %b %#d, %Y

[DateIcon]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Date_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1

[Date]
Meter=String
MeasureName=MeasureDate
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=10R
Y=r
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables Curr_X ([DateIcon:X]+([DateIcon:W]+[Date:W]+10)/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\CalendarView.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "CalendarView.ini"]

[DateNotification]
Meter=Shape
X=([DateIcon:X]+[DateIcon:W])
Y=(#Bar_OffsetY#+#Bar_Height#/2+#Font_Size#*8/14)
Shape=Ellipse 0,0,4 | StrokeWidth 0 | Fill Color #Color_Scheme5#
DynamicVariables=1
Hidden=1
