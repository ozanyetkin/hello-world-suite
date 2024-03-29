[Variables]
Wifi_X=1426
;Left, Right or Center
Wifi_Anchor =left

[Metadata]
Name=Paper\\Wifi
Author=reddit.com/u/khanhas
Description=Display Wifi SSID.

[WifiAnchor]
Measure=String
String = #Wifi_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption WifiIcon X "(#Bar_OffsetX#+#*Wifi_X*#-([*WifiIcon:W*]+[*Wifi:W*]+10)/2)"][!SetOption Wifi X 10R]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption WifiIcon StringAlign RightCenter][!SetOption Wifi StringAlign RightCenter][!SetOption WifiIcon X "([*Wifi:X*]-10)"][!SetOption Wifi X "(#Bar_OffsetX#+#*Wifi_X*#)"]

[WifiSSID]
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=SSID

[WifiQuality]
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=Quality

[WifiIcon]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*15/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Wifi_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1

[Wifi]
Meter=String
MeasureName=WifiSSID
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
ClipString=2
ClipStringW=70
ClipStringH=#Font_Size#
StringAlign=LeftCenter
X=10R
Y=r
DynamicVariables=1
ToolTipText=SSID: [WifiSSID]#CRLF#Quality: [WifiQuality]%
