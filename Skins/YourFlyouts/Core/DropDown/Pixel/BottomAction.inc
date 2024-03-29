[Variables]
SaveLocation="#SKINSPATH##sec.name#\Main\Vars\Pixel.inc"

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[String:S]
W=(#Sec.W#-#Sec.P#*2)
CLipString=2
Tooltiptitle=#CURRENTSECTION#

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[YourMixer]
Meter=String
Y=(#Sec.P#) 
ToolTipText=Launches JaxCore's YourMixer. Recommended.
MeterStyle=String:S
LeftMouseUpAction=[!WriteKeyValue Variables BottomActionBang """[!UpdateMeasure mToggle "YourMixer\Main"]""" "#SaveLocation#"][!WriteKeyValue Variables BottomActionName "#CURRENTSECTION#" "#SaveLocation#"][!Refresh "YourFlyouts\Main"][!Refresh "#JaxCore\Main"][!DeactivateConfig]
[Div:0]
Meter=Shape
MeterStyle=Div:S
[Windows Mixer]
Meter=String
ToolTipText=Launches the default windows application mixer
MeterStyle=String:S
LeftMouseUpAction=[!WriteKeyValue Variables BottomActionBang """[SndVol.exe]""" "#SaveLocation#"][!WriteKeyValue Variables BottomActionName "#CURRENTSECTION#" "#SaveLocation#"][!Refresh "YourFlyouts\Main"][!Refresh "#JaxCore\Main"][!DeactivateConfig]