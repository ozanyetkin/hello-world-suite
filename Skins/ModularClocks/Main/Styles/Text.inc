[Rainmeter]
; SolidColor=255,255,255,25
; BackgroundMode=2
DynamicWindowSize=1
; SkinWidth=#SW#
; SkinHeight=#SW#

; [Variables]
; SW=(500*#Scale#)

[mDay]
Measure=Time
Format=%A
FormatLocale=Local
[String:S]
FontColor=#TintColor#

[mHour]
Measure=Time
Format=%I
; RegexpSubstitute=1
Substitute="01":"one","02":"two","03":"three","04":"four","05":"five","06":"six","07":"seven","08":"eight","09":"nine","10":"ten","11":"eleven","12":"twelve"

[mMinHead]
Measure=time
Format=%M
RegexpSubstitute=1
Substitute="^0":"zero","^2":"twenty","^3":"thirty","^4":"forty","^5":"fifty","10":"ten","11":"eleven","12":"twelve","13":"thirteen","14":"fourteen","15":"fifteen","16":"sixteen","17":"seventeen","18":"eighteen","19":"nineteen","[1234567890]":""

[mMinTail]
Measure=time
Format=%M
RegexpSubstitute=1
; Substitute=".*":"yo"
Substitute="0$":"","[02345]1$":"one","[02345]2$":"two","[02345]3$":"three","[02345]4$":"four","[02345]5$":"five","[02345]6$":"six","[02345]7$":"seven","[02345]8$":"eight","[02345]9$":"nine","[1234567890]":""

[mFormatDate]
Measure=time
Format=%A
RegexpSubstitute=1
Substitute="Monday":"monday", "Tuesday":"tuesday", "Wednesday":"wednesday", "Thursday":"thursday", "Friday":"friday", "Satrday":"saturday", "Sunday":"sunday"

[Prefix]
X=0
Meter=String
MeterStyle=String:S
FontSize=(50*#scale#)
FontColor=255,255,255,100
FontFace=Consolas
DynamicVariables=1
Text=it

[PrefixDay]
X=R
Meter=String
MeterStyle=String:S
FontSize=(50*#scale#)
FontColor=255,255,255
FontFace=Consolas
DynamicVariables=1
Text=is

[DateText]
Meter=String
MeterStyle=String:S | Time#Align# | Shadow#Shadow#
X=R
FontColor=255,255,255,100
FontSize=(50*#scale#)
Text="%1"
MeasureName=mFormatDate
DynamicVariables=1

[PrefixTime]
X=R
Meter=String
MeterStyle=String:S
FontSize=(50*#scale#)
FontColor=233,0,139
FontFace=Consolas
DynamicVariables=1
Text=and

[Hour]
Meter=String
MeasureName=mHour
X=R
Text="%1"
FontSize=(50*#scale#)
MeterStyle=String:S

[Highlight]
Meter=String
X=R
MeasureName=mMinHead
Text="%1"
FontSize=(50*#scale#)
MeterStyle=String:S

[Tail]
Meter=String
X=R
MeasureName=mMinTail
Text="%1"
FontSize=(50*#scale#)
MeterStyle=String:S



@includeRender=Render\Text\#Render#.inc