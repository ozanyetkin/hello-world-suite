[Variables]
Sec.shup_setting.discord=1
Sec.shup_setting.spotify=1
Sec.shup_setting.firefox=1
Sec.shup_info.name=SHUPNAME
Sec.shup_info.author=SHUPAUTH
Sec.shup_setting.absolute_coordinates=0
Process.Logs=#CRLF#Click on the logo to initialize packaging process

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

; DO NOT WORRY ABOUT UNCERTAINTIES, FOCUS ON YOUR BELIEFS AND ACT ON IT

[p.PSRM.Shup-Packager]
Measure=Plugin
Plugin=PowershellRm
scriptfile="#@#Powershell\SHUP-Packager.ps1"
DynamicVariables=1
ExecutionPolicy=Unrestricted

[WallpaperPath]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Control Panel\Desktop
RegValue=Wallpaper
UpdateDivider=-1

[p.InputText.Input]
Measure=Plugin
Plugin=InputText
SolidColor=#Set.Ter_Color#
FontColor=#Set.Text_Color#
FontFace=Consolas
FontSize=(10*[Set.S])
StringAlign=Left
X=[Input.String:X]
Y=[Input.String:Y]
W=(400*[Set.S]-#Set.P#)
DynamicVariables=1
DefaultValue="Enter setup name..."
Command1=[!CommandMeasure p.PSRM.Shup-Packager """Change-Setting name "$UserInput$""""][!Delay 200][!SetOption #CURRENTSECTION# DefaultValue "Enter author (your) name..."][!CommandMeasure #CURRENTSECTION# "ExecuteBatch 2"]
Command2=[!CommandMeasure p.PSRM.Shup-Packager """Change-Setting author "$UserInput$""""][!Delay 200][!CommandMeasure p.PSRM.Shup-packager "Start-Packager"]

; ---------------------------------------------------------------------------- ;
;                                  MeterStyle                                  ;
; ---------------------------------------------------------------------------- ;

[TButton.Shape:S]
X=r
Y=(#Set.P#+64*[Set.S])r
Shape=Rectangle 0,0,(64*[Set.S]),(64*[Set.S]),(64/2*[Set.S]) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.sec_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #set.ter_color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #set.sec_color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=#Sec.Container#
DynamicVariables=1
[TButton.Image:S]
X=r
Y=r
W=(64*[Set.S]-30*[Set.S])
H=(64*[Set.S]-30*[Set.S])
Padding=(15*[Set.S]),(15*[Set.S]),(15*[Set.S]),(15*[Set.S])
Container=#Sec.Container#
DynamicVariables=1

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[S-Hub.Image]
Meter=Image
X=(#HomePage.P#)
Y=((#Set.H#-#Sec.selector_height#-#Set.TitleBarH#)/2-(256)*[Set.S]/2)
W=(256*[Set.S])
H=(256*[Set.S])
ImageName=#@#Images\CoreAssets\S-HubLogo256.png
Container=#Sec.Container#
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure p.InputText.Input "ExecuteBatch 1"]

[Logs.Shape]
Meter=Shape
X=(#SEt.W#-#HomePage.P#-400*[Set.S])
Y=(#Set.P#)
Shape=Rectangle 0,0,(400*[Set.S]),(#Set.H#-#Set.P#*2-#Sec.selector_height#-#Set.TitleBarH#),(#Set.R#) | StrokeWidth 0 | Fill Color #Set.Sec_color#
Shape2=Rectangle 0,(#Set.H#-#Set.P#*2-#Sec.selector_height#-#Set.TitleBarH#),(400*[Set.S]),(-50*[Set.S]),(#Set.R#) | StrokeWidth 0 | Fill Color #Set.Ter_Color#
Container=#Sec.Container#
DynamicVariables=1

[Logs.String]
Meter=String
X=(#Set.P#/2)r
Y=(#Set.P#/2)r
W=(400*[Set.S]-#Set.P#)
Text=#Process.Logs#
CLipString=2
FontFace=Consolas
Fontsize=(8*[Set.S])
InlinePattern=#CRLF#>\s.*
InlineSetting=Color | 0,255,0
InlinePattern2=#CRLF#INFO\s.*
InlineSetting2=Color | 0,155,255
InlinePattern3=#CRLF#!!\s.*
InlineSetting3=Color | 255,50,0
MeterStyle=Set.String:S

[Input.String]
Meter=String
X=r
Y=((#Set.H#-#Set.P#*2-#Sec.selector_height#-#Set.TitleBarH#)-#Set.P#-10*[Set.S])r
W=(400*[Set.S]-#Set.P#)
Text=...
CLipString=1
StringAlign=Left
FontFace=Consolas
FontColor=#Set.Subtext_Color#
Fontsize=(10*[Set.S])
MeterStyle=Set.String:S

[TButton1.Shape]
Meter=Shape
X=(#SEt.W#-#HomePage.P#-(400+64)*[Set.S]-#Set.P#)
Y=((#Set.H#-#Sec.selector_height#-#Set.TitleBarH#)/2-(64*4*[Set.S]+#SEt.P#*3)/2)
MeterStyle=TButton.Shape:S
[TButton1.Image]
Meter=Image
Greyscale=(1-#Sec.shup_setting.discord#)
ImageName=#@#Icons\S-Hub\Discord.png
MeterStyle=TButton.Image:S
tooltiptitle=BetterDiscord
tooltiptext=Include BetterDiscord theme?
Leftmouseupaction=[!SetVariable "Sec.shup_setting.discord" "(#Sec.shup_setting.discord# = 1 ? 0 : 1)"][!UpdateMeter *][!Redraw]

[TButton2.Shape]
Meter=Shape
MeterStyle=TButton.Shape:S
[TButton2.Image]
Meter=Image
Greyscale=(1-#Sec.shup_setting.Spotify#)
ImageName=#@#Icons\S-Hub\Spotify.png
MeterStyle=TButton.Image:S
tooltiptitle=Spicetify
tooltiptext=Include Spicetify theme?
Leftmouseupaction=[!SetVariable "Sec.shup_setting.Spotify" "(#Sec.shup_setting.Spotify# = 1 ? 0 : 1)"][!UpdateMeter *][!Redraw]

[TButton3.Shape]
Meter=Shape
MeterStyle=TButton.Shape:S
[TButton3.Image]
Meter=Image
Greyscale=(1-#Sec.shup_setting.Firefox#)
ImageName=#@#Icons\S-Hub\Firefox.png
MeterStyle=TButton.Image:S
tooltiptitle=Firefox
tooltiptext=Include Firefox theme?
Leftmouseupaction=[!SetVariable "Sec.shup_setting.Firefox" "(#Sec.shup_setting.Firefox# = 1 ? 0 : 1)"][!UpdateMeter *][!Redraw]

[TButton4.Shape]
Meter=Shape
MeterStyle=TButton.Shape:S
[TButton4.Image]
Meter=Image
ImageName=#@#Icons\S-Hub\How.png
MeterStyle=TButton.Image:S
ImageAlpha=50
ImageTint=#Set.Text_Color#
tooltiptitle=Not know what you're doing?
tooltiptext=Read the step-by-step guide on S-Hub's website!
Leftmouseupaction=[""]