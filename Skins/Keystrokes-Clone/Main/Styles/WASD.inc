;===========================================================================================================================================================

[Background]
Meter=Shape
Shape=Rectangle 0,0,(#Scale#*170),(#Scale#*170),(#Corner#*15),(#Corner#*15) | StrokeWidth 0 | Fill Color #BackgroundColor#,#BackgroundOpacity#

[SpaceShape]
Meter=Shape
MeterStyle=KeyB:S | Key3Style
X=(170/2*#Scale#)
Y=((50/2+50/4+#KeyPadding#)*#Scale#)r

[SpaceLabel]
Meter=String
MeterStyle=Key#RGB#:S
Text=space