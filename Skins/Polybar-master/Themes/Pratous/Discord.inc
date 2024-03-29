[Variables]
Discord_X=1490

[Metadata]
Name=Pratous\\Discord
Author=reddit.com/u/khanhas
Description=Click to show Discord status and control

[DiscordIcon]
Meter=Image
ImageName=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\Discord.png
W=(#Font_Size#*14/12)
X=(#Bar_OffsetX#+#Discord_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2-[DiscordIcon:H]/2)
SolidColor=0,0,0,1
DynamicVariables=1
AntiAlias=1
MouseOverAction=[!CommandMeasure AdditionalSkinActionTimer "Stop 1"][!WriteKeyValue Variables "Curr_X" "(#CURRENTCONFIGX#+[DiscordIcon:X]+[DiscordIcon:W]/2)" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!WriteKeyValue Variables "Curr_Y" "[SubSkinYPositionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!WriteKeyValue Variables "Dir" "[SubSkinDirectionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "DiscordStatus.ini"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
LeftMouseUpAction=["%localappdata%\Discord\Update.exe" --processStart Discord.exe]

[DiscordShape]
Meter=Shape
Y=(#Bar_OffsetY#+#Bar_Height#/2)
Shape=Rectangle ([Discord_UnreadCountBadge:X]-3),(-[DiscordIcon:H]/4),([Discord_UnreadCountBadge:W]+6*sgn([Discord_UnreadCountBadge:W])),([Discord_UnreadCountBadge:H]+2*sgn([Discord_UnreadCountBadge:W])),2 | StrokeWidth 0 | Fill Color #Color_Scheme5#
DynamicVariables=1

[Discord_UnreadCountBadge]
Meter=String
MeasureName=DiscordNotice
FontFace=#Font_Face#
FontSize=(#Font_Size#*10/12)
FontColor=#Color_Scheme4#
X=(#Bar_OffsetX#+#Discord_X#+[DiscordIcon:W])
StringAlign=Center
Y=(-[DiscordIcon:H]/4)r
AntiAlias=1
DynamicVariables=1

[DiscordScript]
Measure=Script
ScriptFile=#@#Scripts\Discord_Common_Script.lua
JSONFile = %appdata%\BetterDiscord\plugins\DiscordForRainmeter.config.json

[DiscordNotice]
Measure=Calc
Formula=[DiscordScript:GetNotification(true,true,true)]
IfCondition=DiscordNotice > 0 
IfTrueAction=[!SetOption DiscordIcon ImageTint "#Color_Scheme4#"][!ShowMeter Discord_UnreadCountBadge]
IfFalseAction=[!SetOption DiscordIcon ImageTint "#Color_Scheme2#"][!HideMeter Discord_UnreadCountBadge]
DynamicVariables=1
