[Variables]
Page.Items.P=(25*[Set.S])
Page.Items.H=(([BC:H]-90*[Set.S]-#Page.Items.P#*3)/2)
Page.Items.Content.P=(25*[Set.S])
Page.R=(16*[Set.S])
Sec.Container=
PostWelcome.Guide=0
PostWelcome.GameMode=0

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[p.SysInfo.USER_NAME]
Measure=Plugin
Plugin=SysInfo
SysInfoType=USER_NAME
UpdateDivider=-1

[0.Container]
Meter=String
; To avoid errors

[m.CheckGuide]
Measure=String
STring=#PostWelcome.Guide##PostWelcome.GameMode#
DynamicVariables=1
IfMatch=^1.$
IfMatchAction=[!WriteKeyValue Variables Set.W (#SCREENAREAWIDTH#*0.65) "#@#Vars.inc"][!WriteKeyValue Variables Set.H (0.65*#SCREENAREAWIDTH#*3/4) "#@#Vars.inc"][!WriteKeyValue Set.S Formula "((#SCREENAREAWIDTH#/1920) < (#SCREENAREAHEIGHT#/1080) ? (#SCREENAREAWIDTH#/1920) : (#SCREENAREAHEIGHT#/1080))" "#@#Vars.inc"][!SetOption Set.S Formula "((#SCREENAREAWIDTH#/1920) < (#SCREENAREAHEIGHT#/1080) ? (#SCREENAREAWIDTH#/1920) : (#SCREENAREAHEIGHT#/1080))"][!UpdateMeasure Set.S][!SetVariable Set.W (#SCREENAREAWIDTH#*0.65)][!SetVariable Set.H (0.65*#SCREENAREAWIDTH#*3/4)][!UpdateMeter *][!Redraw][!Move (#SCREENAREAWIDTH#*(0.5-0.65/2)) (#SCREENAREAHEIGHT#/2-#SCREENAREAWIDTH#*0.65*0.75/2)]
IfMatch2=^.1$
IfMatchAction2=[!Manage GameMode]
OnUpdateAction=[!WriteKeyValue Variables PostWelcome.Guide 0 "#ROOTCONFIGPATH#CoreShell\Home\Page1.inc"][!WriteKeyValue Variables PostWelcome.GameMode 0 "#ROOTCONFIGPATH#CoreShell\Home\Page1.inc"]


; ---------------------------------------------------------------------------- ;
;                                  MeterStyles                                 ;
; ---------------------------------------------------------------------------- ;

[Item.Shape:S]
Common=StrokeWidth 0
This=Fill Color #Set.Sec_Color#
Container=#Sec.Container#
DynamicVariables=1
MouseOverAction=[!SetOption "[&Func:trim('#CURRENTSECTION#', 'Shape', '')]Image" "H" "(#*Page.Items.H*#+20)"][!SetOption "[&Func:trim('#CURRENTSECTION#', 'Shape', '')]Content.Description.String" "Y" "(#*Page.Items.H*#-#*Page.Items.Content.P*#-15)r"][!UpdateMeter *][!Redraw]
MouseLeaveAction=[!SetOption "[&Func:trim('#CURRENTSECTION#', 'Shape', '')]Image" "H" "(#*Page.Items.H*#)"][!SetOption "[&Func:trim('#CURRENTSECTION#', 'Shape', '')]Content.Description.String" "Y" "(#*Page.Items.H*#-#*Page.Items.Content.P*#)r"][!UpdateMeter *][!Redraw]
; MouseOverAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Ter_color# | Scale 1.01,1.01"][!UpdateMeter #CURRENTSECTION#][!Redraw]
; MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Item.Container:S]
X=r
Y=r
90Fade=90 | 0,0,0,0 ; 0 | 0,0,0 ; 0.5
120Fade=120 | 0,0,0,0 ; 0 | 0,0,0 ; 0.5
145p1Fade=130 | 0,0,0,0 ; 0.1 | 0,0,0 ; 0.5
Common=StrokeWidth 0
DynamicVariables=1

[Item.Shape:Dim_0]
Shape=Rectangle 0,0,(#Set.W#*0.6-#HomePage.P#-#Page.Items.P#/2),#Page.Items.H#,#Page.R# | Extend Common | Extend This
[Item.Container:Dim_0]
Shape=Rectangle 0,0,(#Set.W#*0.6-#HomePage.P#-#Page.Items.P#/2),#Page.Items.H#,#Page.R# | Extend Common | Fill LinearGradient 145p1Fade
[Item.Shape:Dim_1]
Shape=Rectangle 0,0,(#Set.W#*0.4-#HomePage.P#-#Page.Items.P#/2),#Page.Items.H#,#Page.R# | Extend Common | Extend This
[Item.Container:Dim_1]
Shape=Rectangle 0,0,(#Set.W#*0.4-#HomePage.P#-#Page.Items.P#/2),#Page.Items.H#,#Page.R# | Extend Common | Fill LinearGradient 120Fade
[Item.Shape:Dim_2]
Shape=Rectangle 0,0,((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3),#Page.Items.H#,#Page.R# | Extend Common | Extend This
[Item.Container:Dim_2]
Shape=Rectangle 0,0,((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3),#Page.Items.H#,#Page.R# | Extend Common | Fill LinearGradient 90Fade

[Item.Image:S]
X=r
Y=r
PreserveAspectRatio=2
Container=[&Func:trim('#CURRENTSECTION#', '%.Image', '')].Container
DynamicVariables=1

[Item.Image:Dim_0]
W=(#Set.W#*0.6-#HomePage.P#-#Page.Items.P#/2)
H=#Page.Items.H#
[Item.Image:Dim_1]
W=(#Set.W#*0.4-#HomePage.P#-#Page.Items.P#/2)
H=#Page.Items.H#
[Item.Image:Dim_2]
W=((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3)
H=#Page.Items.H#

[Item.Content.Image:S]
W=(64*[Set.S])
H=(64*[Set.S])
X=r
Y=(-#Page.Items.Content.P#-(64+40)*[Set.S])r
DynamicVariables=1
Container=#Sec.Container#
[Item.Content.Header.String:S]
X=r
Y=(-#Page.Items.Content.P#/2)r
FontWeight=600
FontSize=(32*[Set.S])
StringAlign=LeftBottom
ClipString=1
[Item.Content.Header.String:Mid]
FontSize=(28*[Set.S])
[Item.Content.Description.String:S]
FontSize=(10*[Set.S])
StringAlign=LeftBottom
X=#Page.Items.Content.P#r
Y=(#Page.Items.H#-#Page.Items.Content.P#)r
ClipString=1
[Item.Content.Button.Shape:S]
X=(#Set.W#*0.6-#HomePage.P#-#Page.Items.P#/2-#Page.Items.Content.P#*2-(100*[Set.S]))r
Y=(#Page.Items.Content.P#*1.5+(60+40)*[Set.S])r
Shape=Rectangle 0,0,(100*[Set.S]),(-40*[Set.S]),(#Page.R#/2) | StrokeWidth 0 | Fill Color #Set.Positive_Color# | Extend Scale
Scale=Scale 1,1
MouseOverAction=[!SetOption "#CURRENTSECTION#" Scale "Scale 1.1,1.1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" Scale "Scale 1,1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
Container=#Sec.Container#
DynamicVariables=1
[Item.Content.Button.String:S]
FontColor=#Set.Pri_Color#
FontWeight=600
X=(50*[Set.S])r
Y=(-20*[Set.S])r
StringAlign=CenterCenter

[Header.Link.Shape:S]
X=(-30*[Set.S])r
Y=(16*[Set.S])r
Shape=Ellipse 0,0,(24*[Set.S]) | StrokeWidth 0 | Extend This | OffSet (-24*[Set.S]),0
This=Fill Color #Set.Subtext_Color#,75 | Scale 1,1
CoreGrad=45 | #SEt.Accent_Color_2# ; 1 | #Set.Accent_color# ;0
MouseOverAction=[!SetOption "#CURRENTSECTION#" This "Fill LinearGradient CoreGrad | Scale 1.2,1.2"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" This "Fill Color #Set.Subtext_Color#,75 | Scale 1,1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
DynamicVariables=1
Container=#Sec.Container#
[Header.Link.Image:S]
X=(-40*[Set.S])r
Y=(-16*[Set.S])r
W=(32*[Set.S])
H=(32*[Set.S])
DynamicVariables=1
Container=#Sec.Container#

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Header.Shape]
Meter=Shape
X=0
Y=(#SCroll#+#Set.TitleBarH#)
Shape=Rectangle 0,0,(#Set.W#),(90*[Set.S]) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
Shape2=Rectangle 0,(90*[Set.S]),(#Set.W#),(2*[Set.S]) | StrokeWidth 0 | Fill Color #Set.Sec_Color#
DynamicVariables=1
Container=#Sec.Container#

[Header.JaxCore.String]
Meter=String
X=(#HomePage.P#)
Y=(90*[Set.S]/2+2*[Set.S]+#Scroll#+#Set.TitleBarH#)
Stringalign=LeftCenter
Text=JaxCore
FontSize=(32*[Set.S])
FontWeight=650
FontFace=Righteous
InlineSetting=GradientColor | 45 | #SEt.Accent_Color_2# ; 1 | #Set.Accent_color# ;0
MeterStyle=Set.String:S
LeftMouseUpAction=[!WriteKeyValue Variables Sec.Page "00000"][!Refresh]

; ----------------------------------- Links ---------------------------------- ;
[Header.Link1.Shape]
Meter=Shape
X=(#Set.W#-#HomePage.P#)
Y=r
LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
MeterStyle=Header.Link.Shape:S
[Header.Link1.Image]
Meter=Image
ImageName=#@#Icons\HomePage_DiscordIcon.png
MeterStyle=Header.Link.Image:S
ToolTipTitle=Join CoreCommunity
ToolTipText=Join JaxCore's community, get update notification and more!

[Header.Link2.Shape]
Meter=Shape
LeftMouseUpAction=["https://www.deviantart.com/jaxoriginals"]
MeterStyle=Header.Link.Shape:S
[Header.Link2.Image]
Meter=Image
ImageName=#@#Icons\HomePage_DAIcon.png
MeterStyle=Header.Link.Image:S
ToolTipTitle=My DeviantArt
ToolTipText=Watch my DA account to be notified for new releases!

[Header.Link3.Shape]
Meter=Shape
LeftMouseUpAction=["https://jaxcore.app"]
MeterStyle=Header.Link.Shape:S
[Header.Link3.Image]
Meter=Image
ImageName=#@#Icons\HomePage_WebsiteIcon.png
MeterStyle=Header.Link.Image:S
ToolTipTitle=JaxCore's website
ToolTipText=Check it out if you like!

[Header.Link4.Shape]
Meter=Shape
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals"]
MeterStyle=Header.Link.Shape:S
[Header.Link4.Image]
Meter=Image
ImageName=#@#Icons\Donate.png
MeterStyle=Header.Link.Image:S
ToolTipTitle=Support JaxCore's development
ToolTipText=You can donate to my Ko-Fi page to directly support me, or simply purchase any DLC to support me!

; ------------------------------------- 1 ------------------------------------ ;
[Item1.Shape]
Meter=Shape
X=#HomePage.P#
Y=(90*[Set.S]+#Set.TitleBarH#+#Page.Items.P#)
LeftMouseUpAction=[!CommandMeasure Func "corepage('YourFlyouts')"]
MeterStyle=Item.Shape:S | Item.Shape:Dim_0
[Item1.Container]
Meter=Shape
MeterStyle=Item.Container:S | Item.Container:Dim_0

[Item1.Image]
Meter=Image
ImageName="#@#Images\Cards\YourFlyouts.png"
MeterStyle=Item.Image:S | Item.Image:Dim_0

[Item1.Content.Description.String]
Meter=String
Text=Your new audio & volume flyouts, now with full support
MeterStyle=Set.String:S | Item.Content.Description.String:S
[Item1.Content.Header.String]
Meter=String
Text=YourFlyouts v2
InlinePattern=Flyouts v2
InlineSetting=GradientColor | 45 | #Set.Accent_Color_2# ; 1.0 | #Set.Accent_Color# ; 0.0
InlinePattern2=Flyouts v2
InlineSetting2=Shadow | 0 | 0 | 5 | #Set.Accent_Color#,150
MeterStyle=Set.String:S | Item.Content.Header.String:S
[Item1.Content.Image]
Meter=Image
ImageName="#@#Images\Unified\YourFlyouts.png"
MeterStyle=Item.Content.Image:S

; ------------------------------------- 2 ------------------------------------ ;
[Item2.Shape]
Meter=Shape
X=(#Set.W#*0.6+#Page.Items.P#/2)
Y=(90*[Set.S]+#Set.TitleBarH#+#Page.Items.P#)
LeftMouseUpAction=[!CommandMeasure Func "corepage('YourMixer')"]
MeterStyle=Item.Shape:S | Item.Shape:Dim_1
[Item2.Container]
Meter=Shape
MeterStyle=Item.Container:S | Item.Container:Dim_1

[Item2.Image]
Meter=Image
ImageName="#ROOTCONFIGPATH#CoreShell\Home\Assets\Page1\YourMixer3.png"
MeterStyle=Item.Image:S | Item.Image:Dim_1

[Item2.Content.Description.String]
Meter=String
Text=Your new app volume mixer
MeterStyle=Set.String:S | Item.Content.Description.String:S
[Item2.Content.Header.String]
Meter=String
Text=YourMixer
InlinePattern=Mixer
InlineSetting=GradientColor | 45 | #Set.Accent_Color_2# ; 1.0 | #Set.Accent_Color# ; 0.0
InlinePattern2=Mixer
InlineSetting2=Shadow | 0 | 0 | 5 | #Set.Accent_Color#,150
MeterStyle=Set.String:S | Item.Content.Header.String:S
[Item2.Content.Image]
Meter=Image
ImageName="#@#Icons\LibraryIcons\YourMixer.png"
MeterStyle=Item.Content.Image:S

; ------------------------------------- 3 ------------------------------------ ;
[Item3.Shape]
Meter=Shape
X=#HomePage.P#
Y=(90*[Set.S]+#Set.TitleBarH#+#Page.Items.P#*2+#Page.Items.H#)
LeftMouseUpAction=[!CommandMeasure Func "corepage('ModularClocks')"]
MeterStyle=Item.Shape:S | Item.Shape:Dim_2
[Item3.Container]
Meter=Shape
MeterStyle=Item.Container:S | Item.Container:Dim_2

[Item3.Image]
Meter=Image
ImageName="#ROOTCONFIGPATH#CoreShell\Home\Assets\Page1\Clock.png"
MeterStyle=Item.Image:S | Item.Image:Dim_2
[Item3.Content.Description.String]
Meter=String
Text=ModularClocks's center variant brings cleanness to your desktop
W=((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3-#Page.Items.Content.P#*2)
MeterStyle=Set.String:S | Item.Content.Description.String:S
[Item3.Content.Header.String]
Meter=String
Text=mClocks 
MeterStyle=Set.String:S | Item.Content.Header.String:S | Item.Content.Header.String:Mid
W=((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3-#Page.Items.Content.P#*2)

; ------------------------------------- 4 ------------------------------------ ;
[Item4.Shape]
Meter=Shape
X=(#HomePage.P#+((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3)+#Page.Items.P#)
Y=(90*[Set.S]+#Set.TitleBarH#+#Page.Items.P#*2+#Page.Items.H#)
LeftMouseUpAction=[!CommandMeasure Func "corepage('ValliStart')"]
MeterStyle=Item.Shape:S | Item.Shape:Dim_2
[Item4.Container]
Meter=Shape
MeterStyle=Item.Container:S | Item.Container:Dim_2

[Item4.Image]
Meter=Image
ImageName="#ROOTCONFIGPATH#CoreShell\Home\Assets\Page1\ValliStart.png"
MeterStyle=Item.Image:S | Item.Image:Dim_2
[Item4.Content.Description.String]
Meter=String
Text=Bring tools and widgets to your new start menu
W=((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3-#Page.Items.Content.P#*2)
MeterStyle=Set.String:S | Item.Content.Description.String:S
[Item4.Content.Header.String]
Meter=String
Text=ValliStart 
MeterStyle=Set.String:S | Item.Content.Header.String:S | Item.Content.Header.String:Mid
W=((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3-#Page.Items.Content.P#*2)

; ------------------------------------- 5 ------------------------------------ ;
[Item5.Shape]
Meter=Shape
X=(#HomePage.P#+((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3)*2+#Page.Items.P#*2)
Y=(90*[Set.S]+#Set.TitleBarH#+#Page.Items.P#*2+#Page.Items.H#)
LeftMouseUpAction=[!CommandMeasure Func "corepage('IdleStyle')"]
MeterStyle=Item.Shape:S | Item.Shape:Dim_2
[Item5.Container]
Meter=Shape
MeterStyle=Item.Container:S | Item.Container:Dim_2

[Item5.Image]
Meter=Image
ImageName="#ROOTCONFIGPATH#CoreShell\Home\Assets\Page1\IdleStyle.png"
MeterStyle=Item.Image:S | Item.Image:Dim_2
[Item5.Content.Description.String]
Meter=String
Text=Get a fancy screensaver with IdleStyle!
W=((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3-#Page.Items.Content.P#*2)
MeterStyle=Set.String:S | Item.Content.Description.String:S
[Item5.Content.Header.String]
Meter=String
Text=IdleStyle
MeterStyle=Set.String:S | Item.Content.Header.String:S | Item.Content.Header.String:Mid
W=((#Set.W#-#HomePage.P#*2-#Page.Items.P#*2)/3-#Page.Items.Content.P#*2)
[GameMode]
Formula=1
