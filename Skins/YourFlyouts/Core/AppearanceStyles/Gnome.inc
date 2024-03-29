


[Option01]
Meter=String
Text="Width"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:01]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text="Font face"
MeterStyle=Set.String:S | Set.OptionName:S

[ColorTitle]
Meter=String
Text="Color settings"
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text="Background color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:11]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text="Font color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:13]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text="Behind-bar color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:14]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text="Accent color"
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;


[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0.5|2
Y=([Option00:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value00]
Meter=String
Text="#Scale#x"
MeterStyle=Set.String:S | Set.Value:S
[Width]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|200|600
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text="#Width#"
MeterStyle=Set.String:S | Set.Value:S
[Fontface]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value03]
Meter=String
Text="#Fontface#"
MeterStyle=Set.String:S | Set.Value:S

[Primary]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Num|1|255
[Value11]
Meter=String
Text=#PrimaryOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[FontColor2]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[AccentColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R