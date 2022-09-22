;===========================================================================================================================================================

[Background]
Meter=Shape
Shape=Rectangle 0,0,(#Scale#*170),(#Scale#*170),(#Corner#*15),(#Corner#*15) | StrokeWidth 0 | Fill Color #BackgroundColor#,#BackgroundOpacity#

[SpaceShape]
Meter=Shape
MeterStyle=KeyB:S
X=((50+#KeyPadding#)*#Scale#)r
Y=r

[SpaceLabel]
Meter=String
MeterStyle=Key#RGB#:S
Text=-