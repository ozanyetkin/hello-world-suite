[Rainmeter]
; SolidColor=255,255,255,25
; BackgroundMode=2
SkinWidth=#SW#
SkinHeight=#SH#

[Variables]
@includeWeather=#@#Includes\GlobalWeather.inc
SW=(500*#Scale#)
SH=(500*#Scale#)

[mTime]
Measure=Time
Format=%##gVar.2412##Seperator#%M
RegexpSubstitute=1
[mDate]
Measure=Time
Format=%A, %B %d
FormatLocale=Local
[String:S]
FontColor=#TintColor#

[Time]
Meter=String
MeasureName=mTime
FontSize=(70*#scale#)
Hidden=(1-#Time#)
MeterStyle=String:S | Time#Align# | Shadow#Shadow#

[WeatherIcon]
Meter=Image
Y=R
W=(40*#Scale#)
H=(40*#Scale#)
Hidden=(1-#Weather#)
ImageName=#@#Icons\JD Weather Icons\Shadow#Shadow#\[mCurrentIcon].png
DynamicVariables=1
MeterStyle=Wea#Align# | WeaTint#TintIcon#
[WeaTint0]
[WeaTint1]
Greyscale=1
ImageTint=#TintColor#

[WeatherText]
Meter=String
MeterStyle=String:S | WeaText#Align# | Shadow#Shadow#
Y=(40/2*#Scale#)r
FontSize=(20*#Scale#*#Weather#)
Text="%1%2"
MeasureName=mCurrentTemperature
Measurename2=mUnitsTemperature

[DateText]
Meter=String
MeterStyle=String:S | Time#Align# | Shadow#Shadow#
Y=R
FontSize=(#DateTimeRatio#*100*#Scale#*#date#)
Text="%1"
MeasureName=mDate
DynamicVariables=1

;====================================================================================

[TimeLeft]
X=0
StringAlign=Left
[Timecenter]
X=(#SW#/2)
StringAlign=Center
[TimeRight]
X=#SW#
StringAlign=Right

[WeaLeft]
X=0
[WeaCenter]
X=(-([WeatherText:W]+50*#Scale#)/2+#CURRENTCONFIGWIDTH#/2)
[WeaRight]
X=(#SW#-[#CURRENTSECTION#:W])

[WeaTextLeft]
X=5R
StringAlign=LeftCenter
[WeaTextcenter]
X=5R
StringAlign=LeftCenter
[WeaTextRight]
X=-5r
StringAlign=RightCenter

[Shadow1]
InlineSetting=Shadow | 1 | 1 | 3 | #ShadowColor#,75