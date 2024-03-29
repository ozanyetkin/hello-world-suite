[Variables]
Mail_X=1483
Mail_Storage=F6A716E6E2975647B696E6E253739352430376D61696C6E236F6D6:93231383975647B696E6
Mail_LoggedIn=false

[Metadata]
Name=Pratous\\Mail
Author=reddit.com/u/khanhas
Description=Gmail only. Show number of unread mails. Click to show most recent mails.

[Mail_Script]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\script_Mail.lua

[Mail_Webparser]
Measure=Plugin
Plugin=WebParser
DynamicVariables=1
DecodeCharacterReference=1
Download=1
DownloadFile=gmailFeed.txt
UpdateRate=2
FinishAction=[!SetVariable Mail_LoggedIn true][!CommandMeasure Mail_Script GetMailFeed('module')]
OnDownloadErrorAction=
Disabled=1

[Mail_Avatar]
Measure=Plugin
PLugin=WebParser
URL=https://picasaweb.google.com/data/feed/api/user/#Mail_Form1#
RegExp=(?siU)<gphoto:thumbnail>(.*)</gphoto:thumbnail>
StringIndex=1
Download=1
DownloadFile=gmailAvatar.png
DynamicVariables=1

[MailIcon]
Meter=Image
ImageName=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\Mail.png
ImageTint=#Color_Scheme2#
W=(#Font_Size#*14/12)
X=(#Bar_OffsetX#+#Mail_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2-[MailIcon:H]/2)
SolidColor=0,0,0,1
DynamicVariables=1
AntiAlias=1
MouseOverAction=[!WriteKeyValue Variables "Curr_X" "(#CURRENTCONFIGX#+[MailIcon:X]+[MailIcon:W]/2)" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MailList.ini"][!WriteKeyValue Variables "Curr_Y" "[SubSkinYPositionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MailList.ini"][!WriteKeyValue Variables "Dir" "[SubSkinDirectionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MailList.ini"][!WriteKeyValue Variables "Mail_LoggedIn" "#Mail_LoggedIn#" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MailList.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "MailList.ini"][!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
LeftMouseUpAction=["https://mail.google.com/mail/u/#Mail_Form1#/#inbox/"]

[Mail_UnreadBadgeShape]
Meter=Shape
Y=(#Bar_OffsetY#+#Bar_Height#/2)
Shape=Rectangle ([Mail_UnreadCountBadge:X]-3),(-[MailIcon:H]/4),([Mail_UnreadCountBadge:W]+6*sgn([Mail_UnreadCountBadge:W])),([Mail_UnreadCountBadge:H]+2*sgn([Mail_UnreadCountBadge:W])),2 | StrokeWidth 0 | Fill Color #Color_Scheme5#
DynamicVariables=1

[Mail_UnreadCountBadge]
Meter=String
MeasureName=MailNotice
FontFace=#Font_Face#
FontSize=(#Font_Size#*10/12)
FontColor=#Color_Scheme4#
X=(#Bar_OffsetX#+#Mail_X#+[MailIcon:W])
StringAlign=Center
Y=(-[MailIcon:H]/4)r
AntiAlias=1
DynamicVariables=1

[MailNotice]
Measure=Calc
Formula=0
IfCondition=MailNotice > 0 
IfTrueAction=[!ShowMeter Mail_UnreadCountBadge][!SetOption MailIcon ImageTint "#Color_Scheme4#"]
IfFalseAction=[!HideMeter Mail_UnreadCountBadge][!SetOption MailIcon ImageTint "#Color_Scheme2#"]
