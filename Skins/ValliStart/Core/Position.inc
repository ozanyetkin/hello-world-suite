[HotkeysTitle]
Meter=String
Text=Alignment
MeterStyle=Set.String:S | Set.OptionCat:S

; ---------------------------------------------------------------------------- ;
;                                     Style                                    ;
; ---------------------------------------------------------------------------- ;

[Export:M]
Measure=String
OnUpdateAction=[!SetOption #Position# MeterStyle "CurrentAlign:S"][!UpdateMeter #Position#][!Redraw]

[Align:S]
X=(((200-40)/3+10)*[Set.S])r
Y=r
OverColor=100,100,100,200
LeaveColor=100,100,100,100
DynamicVariables=1
Shape=Rectangle 0,0,((200-40)/3),((200-40)/3),3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')],#Set.Alpha#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')],#Set.Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')],#Set.Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=ContentContainer
Triangle=(26.5*[Set.S]),(20*[Set.S]) | LineTo (16.5*[Set.S]),(40*[Set.S]) | LineTo (36.5*[Set.S]),(40*[Set.S]) | ClosePath 1
LeftMouseUpAction=[!WriteKeyvalue Variables Position #CURRENTSECTION# "#Sec.SaveLocation#"][!Refresh][!UpdateMEasure Auto_Refresh:M]
DirFill=Fill Color 100,100,100,200 | StrokeWidth 0
[CurrentAlign:S]
X=(((200-40)/3+10)*[Set.S])r
Y=r
DynamicVariables=1
Shape=Rectangle 0,0,((200-40)/3),((200-40)/3),3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Fill=Fill Color 100,100,100,200
Container=ContentContainer
Triangle=(26.5*[Set.S]),(20*[Set.S]) | LineTo (16.5*[Set.S]),(40*[Set.S]) | LineTo (36.5*[Set.S]),(40*[Set.S]) | ClosePath 1
DirFill=Fill Color 12,12,12 | StrokeWidth 2 | Stroke Color #set.Accent_Color# | StrokeStartCap Round | StrokeEndCap Round

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[AlignBox]
Meter=Shape
X=r
Y=(#Set.P#/2)R
Container=ContentContainer
DynamicVariables=1
Shape=Rectangle 0,0,200,200,3,3 | StrokeWidth 2 | Fill Color 0,0,0,1 | Extend Fill | Scale [Set.S],[Set.S],0,0
Fill=Stroke Color #Set.Text_Color#,50
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Text_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[TL]
Meter=Shape
X=(10*[Set.S])r
Y=(10*[Set.S])r
Shape2=Path Triangle | Extend DirFill | OffSet 0,(-2.5*[Set.S]) | Rotate 315
MeterStyle=Align:S
[TC]
Meter=Shape
Shape2=Path Triangle | Extend DirFill | OffSet 0,(-2.5*[Set.S]) | Rotate 0
MeterStyle=Align:S
[TR]
Meter=Shape
Shape2=Path Triangle | Extend DirFill | OffSet 0,(-2.5*[Set.S]) | Rotate 45
MeterStyle=Align:S
[CL]
Meter=Shape
X=((-(200-40)/3*2-20)*[Set.S])r
Y=(((200-40)/3+10)*[Set.S])r
Shape2=Path Triangle | Extend DirFill | OffSet 0,(-2.5*[Set.S]) | Rotate 270
MeterStyle=Align:S
[CC]
Meter=Shape
Shape2=Ellipse ((200-40)/3/2*[Set.S]),((200-40)/3/2*[Set.S]),(10*[Set.S]) | Extend DirFill
MeterStyle=Align:S
[CR]
Meter=Shape
Shape2=Path Triangle | Extend DirFill  | OffSet 0,(-2.5*[Set.S]) | Rotate 90
MeterStyle=Align:S
[BL]
Meter=Shape
X=((-(200-40)/3*2-20)*[Set.S])r
Y=(((200-40)/3+10)*[Set.S])r
Shape2=Path Triangle | Extend DirFill | OffSet 0,(-2.5*[Set.S]) | Rotate 225
MeterStyle=Align:S
[BC]
Meter=Shape
Shape2=Path Triangle | Extend DirFill | OffSet 0,(-2.5*[Set.S]) | Rotate 180
MeterStyle=Align:S
[BR]
Meter=Shape
Shape2=Path Triangle | Extend DirFill | OffSet 0,(-2.5*[Set.S]) | Rotate 135
MeterStyle=Align:S

; ---------------------------------------------------------------------------- ;
;                                    Config                                    ;
; ---------------------------------------------------------------------------- ;

[titleagain]
Meter=String
X=(((200-40)/3+10)*[Set.S]+#Set.P#/2)r
Y=(140*[Set.S])
Text=Additional settings
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=X-padding size
MeterStyle=Set.String:S | Set.OptionName:S

[Option02]
Meter=String
Text=Y-padding size
Y=(50*[Set.S])r
MeterStyle=Set.String:S | Set.OptionName:S

[Option03]
Meter=String
Text=Preserve taskbar space
Y=(50*[Set.S])r
MeterStyle=Set.String:S | Set.OptionName:S

[XPad]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|300
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#XPad#
MeterStyle=Set.String:S | Set.Value:S

[YPad]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|300
Y=([Option02:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value02]
Meter=String
Text=#YPad#
MeterStyle=Set.String:S | Set.Value:S

[PreserveTaskbarSpace]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option03:Y]-#Set.P#+(-20/2+8)*[Set.S])

; [USeCustomInstead]
; Meter=Shape
; MeterStyle=Set.Button:S
; X=(250*[Set.S])
; Y=(50*[Set.S])r
; Shape=Rectangle 0,0,(([ContentContainer:W]-260*[Set.S])/2),30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
; OverColor=#Set.Ter_Color#
; LeaveColor=[&Func:returnBool('Position', 'Custom', '#Set.Ter_color#', '#set.Sec_Color#,150')]
; Act=[!WriteKeyvalue Variables Position "Custom" "#Sec.SaveLocation#"][!Refresh][!UpdateMEasure Auto_Refresh:M]
; [Value05]
; Meter=String
; Text=Use custom position instead
; X=([USeCustomInstead:W]/2)r
; Y=([USeCustomInstead:H]/2)r
; StringAlign=CenterCenter
; MeterStyle=Set.String:S | Set.Value:S
[USeMousePos]
Meter=Shape
MeterStyle=Set.Button:S
X=(250*[Set.S])
Y=(50*[Set.S])r
Shape=Rectangle 0,0,(([ContentContainer:W]-250*[Set.S])/2),30,3,3 | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
OverColor=#Set.Ter_Color#
LeaveColor=[&Func:returnBool('Position', 'MousePosition', '#Set.Ter_color#', '#set.Sec_Color#,150')]
Act=[!WriteKeyvalue Variables Position "MousePosition" "#Sec.SaveLocation#"][!Refresh][!UpdateMEasure Auto_Refresh:M]
[Value06]
Meter=String
Text=Start at mouse position
X=([USeMousePos:W]/2)r
Y=([USeMousePos:H]/2)r
StringAlign=CenterCenter
MeterStyle=Set.String:S | Set.Value:S

; ---------------------------------------------------------------------------- ;
;                            Monitor and animations                            ;
; ---------------------------------------------------------------------------- ;

[HotkeysTitle2]
Meter=String
Text=Monitor
Y=(370*[Set.S])
MeterStyle=Set.String:S | Set.OptionCat:S
[Option11]
Meter=String
Text=Monitor index
MeterStyle=Set.String:S | Set.OptionName:S

; ----------------------------------- Input ---------------------------------- ;

[MonitorIndex]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Int
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#MonitorIndex#
MeterStyle=Set.String:S | Set.Value:S