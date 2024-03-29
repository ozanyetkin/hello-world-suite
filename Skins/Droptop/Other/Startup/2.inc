[Rainmeter]

[Variables]
LanguageSelect=[!UpdateMeter ButtonText][!ShowMeterGroup Button][!SetOptionGroup Section0Buttons FillColor "Fill Color 255,255,255,15 | Stroke Color 63,63,63"][!SetOption [#*CURRENTSECTION*] FillColor "Fill Color 53,53,53 | Stroke Color 56,250,138"][!EnableMouseActionGroup "MouseOverAction|MouseLeaveAction" Section0Buttons][!DisableMouseAction [#*CURRENTSECTION*] "MouseOverAction|MouseLeaveAction"][!UpdateMeterGroup Section0Buttons][!Redraw]

ExecuteAnimation0=[!CommandMeasure LoadActions "Execute 2"]
ExecuteAnimation1=[!WriteKeyvalue Variables Page (#Page#+1)][!Refresh]

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[LoadActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 50 | ExportVars | Start0 | Wait 250 | Start1 | Wait 800 | ClickOn | Custom1
Custom1=[!UnpauseMeasure loop][!Delay 1000][!SetOption Loop StartValue 0][!ClickThrough 0]

[Tween:M]
Measure=Script
ScriptFile=#@#Scripts\Lua\Tween\Main.lua
Tween0=Single | Variable | TweenNode1 | 0 | 1 | 500
Tween1=Single | Variable | TweenNode2 | 0 | 1 | 1000
Optional1=Easing OutExpo
TweenGroup=Tweenable
UpdateDivider=1

[Loop]
Measure=Loop
Paused=1
StartValue=75
EndValue=600
LoopCount=0
UpdateDivider=1

[Morph:S]
StringAlign=Center
FontColor=255,255,255,((Clamp([Loop]-150*#CURRENTSECTION#,0,75*2))-75 < 0 ? (([Loop]-150*#CURRENTSECTION#)/75*255) : (255-([Loop]-150*#CURRENTSECTION#-75)/75*255))
UpdateDivider=1
DynamicVariables=1
X=r
Y=r

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Shape]
Meter=Shape
X=((#SCREENAREAWIDTH#/2-#Sec.W#/2))
Y=((#SCREENAREAHEIGHT#/2-#Sec.H#/2))
Shape=Rectangle 0,0,(+#Sec.W#),(28+(#Sec.H#-28)),(10*#Scale#) | StrokeWidth 2 | Stroke Color 34,34,34 | Fill Color 31,31,31

[Container]
Meter=Shape
X=((#SCREENAREAWIDTH#/2-#Sec.W#/2))
Y=((#SCREENAREAHEIGHT#/2-#Sec.H#/2))
Shape=Rectangle 0,0,(+#Sec.W#),(28+(#Sec.H#-28)),(10*#Scale#) | StrokeWidth 2 | Stroke Color 34,34,34 | Fill Color 31,31,31,(#TweenNode1#*255)
Group=Tweenable
DynamicVariables=1

[BackgroundImage]
Meter=String
MeterStyle=Image:BG
Text=[\xe902]

[Title]
Meter=String
Text=droptop four
X=(#SCREENAREAWIDTH#/2)
Y=(#SCREENAREAHEIGHT#/2-#SEc.H#/2+#Sec.p#)
FontSize=(22*#Scale#)
StringAlign=Center
Container=
InlineSetting=CharacterSpacing | 1 | 0
FontColor=43B553
MeterStyle=String:S

; --------------------------------- Section 1 -------------------------------- ;

[000]
Meter=String
X=(#Sec.W#/2)
Y=(80*#Scale#)
Text=Choose a Language
FontSize=(22*#Scale#)
MeterStyle=String:S | Header:S | Morph:S

[001]
Meter=String
Text=Choisissez une langue
FontSize=(22*#Scale#)
MeterStyle=String:S | Header:S | Morph:S

[002]
Meter=String
Text=Wähle eine Sprache
FontSize=(22*#Scale#)
MeterStyle=String:S | Header:S | Morph:S

[003]
Meter=String
Text=選擇語言
FontSize=(22*#Scale#)
MeterStyle=String:S | Header:S | Morph:S


;------------------------------------------------------------------------
; ############################## SECTION 0 ##############################
;------------------------------------------------------------------------

[Section0ButtonStyle]
Shape=Rectangle 0,0,((#Sec.W#-#Sec.P#*6-30*#Scale#)/4),(70*#Scale#),(10*#Scale#) | StrokeWidth (2*#Scale#) | Extend FillColor
FillColor=Fill Color 255,255,255,15 | Stroke Color 63,63,63
LeftMouseDownAction=
MouseOverAction=[!SetOption #CURRENTSECTION# FillColor "Fill Color 63,63,63 | Stroke Color 63,63,63"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FillColor "Fill Color 255,255,255,15 | Stroke Color 63,63,63"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=r
Y=(10*#Scale#)R
Container=Container
Group=Content | Section0Buttons | Section0

[Section0ButtonStyleB]
FillColor=Fill Color 255,255,255,5 | Stroke Color 43,43,43,0
MouseOverAction=[]
MouseLeaveAction=[]
Group=Content | Section0

; -------------------------------------

[1]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Continue"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 0][!WriteKeyValue Variables UnitsMetric 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 1 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "New York, New York" "#@#GlobalVar\UserSettings.inc"]
X=(#SEc.P#*3)
Y=(135*#Scale#)

[2]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Continue"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 1 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "CAD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Toronto, Ontario" "#@#GlobalVar\UserSettings.inc"]
 

[3]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Continue"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 1 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "GBP" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "London, England" "#@#GlobalVar\UserSettings.inc"]

[4]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Devam et"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "TRY" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Ankara Turkey" "#@#GlobalVar\UserSettings.inc"]

[5]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Weiter"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Berlin Germany" "#@#GlobalVar\UserSettings.inc"]

[6]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Doorgaan"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Amsterdam Netherlands" "#@#GlobalVar\UserSettings.inc"]

[7]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "계속"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "KRW" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Seoul Korea" "#@#GlobalVar\UserSettings.inc"]
X=(10*#Scale#)R
Y=(135*#Scale#)

[8]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Продолжить"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "RUB" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Moscow Russia" "#@#GlobalVar\UserSettings.inc"]

[9]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Continuer"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Paris France" "#@#GlobalVar\UserSettings.inc"]

[10]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Continuar"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "BRL" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Lisbon Portugal" "#@#GlobalVar\UserSettings.inc"]

[11]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Continuar"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Madrid Spain" "#@#GlobalVar\UserSettings.inc"]

[12]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Continua"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Rome Italy" "#@#GlobalVar\UserSettings.inc"]

[13]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Pokračovať"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Bratislava Slovakia" "#@#GlobalVar\UserSettings.inc"]
X=(10*#Scale#)R
Y=(135*#Scale#)

[14]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "استمر"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "SAR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Riyadh Saudi Arabia" "#@#GlobalVar\UserSettings.inc"]

[15]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "継続"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "JPY" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Tokyo Japan" "#@#GlobalVar\UserSettings.inc"]

[16]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Kontyntynuj"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "PLN" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Warsaw" "#@#GlobalVar\UserSettings.inc"]

[17]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Lanjut"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "IDR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Jakarta" "#@#GlobalVar\UserSettings.inc"]

[18]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Turpināt"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Riga" "#@#GlobalVar\UserSettings.inc"]

[19]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Tiếp tục"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "VND" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Ho Chi Minh City" "#@#GlobalVar\UserSettings.inc"]
X=(10*#Scale#)R
Y=(135*#Scale#)

[20]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "ادامه"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "IRR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Tehran" "#@#GlobalVar\UserSettings.inc"]

[21]
Meter=Shape
MeterStyle=Section0ButtonStyle
LeftMouseDownAction=[!SetOption ButtonText Text "Blive ved"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "DKK" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "EUR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Copenhagen" "#@#GlobalVar\UserSettings.inc"]

[22]
Meter=Shape
MeterStyle=Section0ButtonStyle | Section0ButtonStyleB
; LeftMouseDownAction=[!SetOption ButtonText Text "ادامه"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "IRR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Tehran" "#@#GlobalVar\UserSettings.inc"]

[23]
Meter=Shape
MeterStyle=Section0ButtonStyle | Section0ButtonStyleB
; LeftMouseDownAction=[!SetOption ButtonText Text "ادامه"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "IRR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Tehran" "#@#GlobalVar\UserSettings.inc"]

[24]
Meter=Shape
MeterStyle=Section0ButtonStyle | Section0ButtonStyleB
; LeftMouseDownAction=[!SetOption ButtonText Text "ادامه"]#LanguageSelect#[!WriteKeyValue Variables LanguageNum #CURRENTSECTION#][!WriteKeyValue Variables LanguageNum #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables RTLText 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables UnitsMetric 1][!WriteKeyValue Variables UnitsMetric 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables HideAppLanguage 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables Time24HourNum 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables StartMonday 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency1 "IRR" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables ExchangeCurrency2 "USD" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables WeatherLocation "Tehran" "#@#GlobalVar\UserSettings.inc"]

; ; -------------------------------------


[Section0StringStyle]
StringAlign=CenterCenter
FontFace=#UniversalFont#
FontColor=255,255,255,200
FontSize=(15*#Scale#)
ClipString=2
AntiAlias=1
InlinePattern=\(.*\)
InlineSetting=Color | 255,255,255,85
W=[[##CURRENTSECTION#]:W]
H=[[##CURRENTSECTION#]:H]
X=([[##CURRENTSECTION#]:X]+([[##CURRENTSECTION#]:W]/2)-((#SCREENAREAWIDTH#/2-#Sec.W#/2)))
Y=([[##CURRENTSECTION#]:Y]+([[##CURRENTSECTION#]:H]/2)-((#SCREENAREAHEIGHT#/2-#Sec.H#/2))-(2*#Scale#))
Container=Container
Group=Content | Section0

[Section0StringStyleB]
StringEffect=None
FontColor=255,255,255,85

[1String]
Meter=String
MeterStyle=Section0StringStyle
Text="English US#CRLF#(USA)"

[2String]
Meter=String
MeterStyle=Section0StringStyle
Text="English CA#CRLF#(Canada)"

[3String]
Meter=String
MeterStyle=Section0StringStyle
Text="English UK#CRLF#(Britain)"

[4String]
Meter=String
MeterStyle=Section0StringStyle
Text="Türkçe#CRLF#(Turkish)"

[5String]
Meter=String
MeterStyle=Section0StringStyle
Text="Deutsch#CRLF#(German)"

[6String]
Meter=String
MeterStyle=Section0StringStyle
Text="Nederlands#CRLF#(Dutch)"

[7String]
Meter=String
MeterStyle=Section0StringStyle
Text="한국어#CRLF#(Korean)"

[8String]
Meter=String
MeterStyle=Section0StringStyle
Text="Pусский#CRLF#(Russian)"

[9String]
Meter=String
MeterStyle=Section0StringStyle
Text="Français#CRLF#(French)"

[10String]
Meter=String
MeterStyle=Section0StringStyle
Text="Português#CRLF#(Portuguese)"

[11String]
Meter=String
MeterStyle=Section0StringStyle
Text="Español#CRLF#(Spanish)"

[12String]
Meter=String
MeterStyle=Section0StringStyle
Text="Italiano#CRLF#(Italian)"

[13String]
Meter=String
MeterStyle=Section0StringStyle
Text="Slovenčina#CRLF#(Slovak)"

[14String]
Meter=String
MeterStyle=Section0StringStyle
Text="اَلْعَرَبِيَّةُ#CRLF#(Arabic)"

[15String]
Meter=String
MeterStyle=Section0StringStyle
Text="日本語#CRLF#(Japanese)"

[16String]
Meter=String
MeterStyle=Section0StringStyle
Text="Polski#CRLF#(Polish)"

[17String]
Meter=String
MeterStyle=Section0StringStyle
Text="Bahasa Indonesia#CRLF#(Indonesian)"

[18String]
Meter=String
MeterStyle=Section0StringStyle
Text="Latviešu#CRLF#(Latvian)"

[19String]
Meter=String
MeterStyle=Section0StringStyle
Text="Tiếng Việt#CRLF#(Vietnamese)"

[20String]
Meter=String
MeterStyle=Section0StringStyle
Text="فارسی#CRLF#(Fārsi)"

[21String]
Meter=String
MeterStyle=Section0StringStyle
Text="Dansk#CRLF#(Danish)"

[22String]
Meter=String
MeterStyle=Section0StringStyle | Section0StringStyleB
Text="汉语#CRLF#(Simp. Chinese)"

[23String]
Meter=String
MeterStyle=Section0StringStyle | Section0StringStyleB
Text="漢語#CRLF#(Trad. Chinese)"

[24String]
Meter=String
MeterStyle=Section0StringStyle | Section0StringStyleB
Text="Shqip#CRLF#(Albanian)"

; ---------------------------------- Button ---------------------------------- ;

[Button]
Meter=Shape
X=(#Sec.W#/2-90*#Scale#)
Y=(#SEc.H#-#Sec.P#-25*#Scale#)
Shape=Rectangle 0,0,(180*#Scale#),(40*#Scale#),(20*#Scale#) | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color 39,174,96
MouseOverAction=[!SetOption #CURRENTSECTION# FillColor "Fill Color 56,250,138"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FillColor "Fill Color 39,174,96"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[#ExecuteAnimation[#NoAnimationNum]]
Group=Button
Hidden=1
Container=Container

[ButtonText]
Meter=String
Text=123
X=(180/2*#Scale#)r
Y=(21*#Scale#)r
FontSize=(15*#Scale#)
StringAlign=CenterCenter
FontColor=255,255,255
InlineSetting=Shadow | 0 | 1 | 2 | 0,0,0,175
Group=Button
Hidden=1
MeterStyle=String:S