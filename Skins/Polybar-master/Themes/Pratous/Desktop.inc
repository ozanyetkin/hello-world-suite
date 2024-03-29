[Variables]
Desktop_x=1877

[Metadata]
Name=Pratous\\Desktop
Author=reddit.com/u/khanhas
Description=Click to show Desktop.

[DesktopShape]
Meter=Shape
X=(#Bar_OffsetX#+#Desktop_X#)
Y=#Bar_OffsetY#
Shape=Rectangle 0,0,([DesktopButton:W]+#Bar_Height#/2),#Bar_Height# | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color 00000001
MouseOverAction=[!SetOption DesktopShape FillColor "Fill Color #Color_Scheme3#"][!UpdateMeter DesktopShape][!Redraw]
MouseLeaveAction=[!SetOption DesktopShape FillColor "Fill Color 00000001"][!UpdateMeter DesktopShape][!Redraw]
DynamicVariables=1

[DesktopButton]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=CenterCenter
X=(#Bar_Height#/4+[DesktopButton:W]/2)r
Y=(#Bar_OffsetY#+#Bar_Height#/2)
SolidColor=0,0,0,1
LeftMouseDownAction=["#@#nircmd.exe" sendkeypress lwin+d]
DynamicVariables=1
