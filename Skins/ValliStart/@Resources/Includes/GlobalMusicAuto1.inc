; ; ---------------------------------------------------------------------------- ;
; ;                                      Gru                                     ;
; ; ---------------------------------------------------------------------------- ;

[stateAIMP]
Measure=NowPlaying
PlayerName=AIMP
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateCAD]
Measure=NowPlaying
PlayerName=CAD
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWMP]
Measure=NowPlaying
PlayerName=WMP
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateiTunes]
Measure=NowPlaying
PlayerName=iTunes
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWinamp]
Measure=NowPlaying
PlayerName=Winamp
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

[stateWebNowPlaying]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
OnChangeAction=[!CommandMeasure Func "checkMediaAuto()"]
DynamicVariables=1
UpdateDivider=1
Group=MusicGru

; ; ---------------------------------------------------------------------------- ;
; ;                                    Minions                                   ;
; ; ---------------------------------------------------------------------------- ;

; ; ------------------------------------ NP ------------------------------------ ;

[npPlayer]
Measure=String
String=#NowPlayingMedia#
UpdateDivider=-1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npCover]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Cover
Substitute="":"#@#Images\Default.png"
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npArtist]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Artist
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npTrack]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Title
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
UpdateDivider=1
Group=Music | NP
DynamicVariables=1
Disabled=1

[npProgress]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music | NP | Prog
DynamicVariables=1
Disabled=1

[npCurrentPosition]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Position
UpdateDivider=1
Group=Music | NP | Prog
DynamicVariables=1
Disabled=1

[npLength]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Duration
UpdateDivider=1
Group=Music | NP | Prog
DynamicVariables=1
Disabled=1

[npRepeat]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Repeat
IfCondition=npRepeat = 1
IfTrueAction=[!SetOptionGroup CtrlRepeat MeterStyle "Repeat1"][!UpdateMeterGroup CtrlRepeat][!Redraw]
IfCondition2=npRepeat = 2
IfTrueAction2=[!SetOptionGroup CtrlRepeat MeterStyle "Repeat2"][!UpdateMeterGroup CtrlRepeat][!Redraw]
IfCondition3=npRepeat = 0
IfTrueAction3=[!SetOptionGroup CtrlRepeat MeterStyle "Repeat0"][!UpdateMeterGroup CtrlRepeat][!Redraw]
UpdateDivider=1
Group=Music | NP | Repeat
Disabled=1

[npShuffle]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Shuffle
IfCondition=npShuffle = 0
IfTrueAction=[!SetOptionGroup CtrlShuffle MeterStyle "Shuffle0"][!UpdateMeterGroup CtrlShuffle][!Redraw]
IfFalseAction=[!SetOptionGroup CtrlShuffle MeterStyle "Shuffle1"][!UpdateMeterGroup CtrlShuffle][!Redraw]
UpdateDivider=1
Group=Music | NP | Shuffle
DynamicVariables=1
Disabled=1

[npHeart]
Measure=NowPlaying
PlayerName=#NowPlayingMedia#
PlayerType=Rating
IfCondition=npHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"][!UpdateMeter Heart][!Redraw]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"][!UpdateMeter Heart][!Redraw]
UpdateDivider=1
Group=Music | NP | Heart
DynamicVariables=1
Disabled=1

; ------------------------------------ WNP ----------------------------------- ;

[wnpPlayer]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Player
Substitute="":"Media"
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpCover]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Cover
DefaultPath=#@#Images\Default.png
CoverPath=#@#Images\Cover.png
; OnChangeAction=[!SetOption MainC Path "[#CURRENTSECTION#]"][!UpdateMeter MusicImg][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpArtist]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Artist
Substitute="":"-"
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
Substitute="":"Not playing"
OnChangeAction=[!UpdateMeterGroup Music][!Redraw]
UpdateDivider=1
Group=Music | WNP
Disabled=1

[wnpProgress]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Progress
Substitute="NaN":"1"
UpdateDivider=1
Group=Music | WNP | Prog
Disabled=1

[wnpCurrentPosition]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Position
UpdateDivider=1
Group=Music | WNP | Prog
Disabled=1

[wnpLength]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Duration
UpdateDivider=1
Group=Music | WNP | Prog
Disabled=1

[wnpRepeat]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Repeat
IfCondition=npRepeat = 1
IfTrueAction=[!SetOptionGroup CtrlRepeat MeterStyle "Repeat1"][!UpdateMeterGroup CtrlRepeat][!Redraw]
IfCondition2=npRepeat = 2
IfTrueAction2=[!SetOptionGroup CtrlRepeat MeterStyle "Repeat2"][!UpdateMeterGroup CtrlRepeat][!Redraw]
IfCondition3=npRepeat = 0
IfTrueAction3=[!SetOptionGroup CtrlRepeat MeterStyle "Repeat0"][!UpdateMeterGroup CtrlRepeat][!Redraw]
UpdateDivider=1
Group=Music | WNP | Repeat
Disabled=1

[wnpShuffle]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Shuffle
IfCondition=wnpShuffle = 0
IfTrueAction=[!SetOption Shuffle MeterStyle "Shuffle0"][!UpdateMeter Shuffle][!Redraw]
IfFalseAction=[!SetOption Shuffle MeterStyle "Shuffle1"][!UpdateMeter Shuffle][!Redraw]
UpdateDivider=1
Group=Music | WNP | Shuffle
Disabled=1

[wnpHeart]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Rating
IfCondition=wnpHeart = 0
IfTrueAction=[!SetOptionGroup CtrlHeart MeterStyle "EmptyHeart"][!UpdateMeterGroup CtrlHeart][!Redraw]
IfFalseAction=[!SetOptionGroup CtrlHeart MeterStyle "FullHeart"][!UpdateMeterGroup CtrlHeart][!Redraw]
UpdateDivider=1
Group=Music | WNP | Heart
Disabled=1