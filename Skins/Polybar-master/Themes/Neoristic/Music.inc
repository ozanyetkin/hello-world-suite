[Variables]
Music_X =338
;Left, Right or Center
Music_Anchor=left
Music_Width = 250
Music_Current_Player=WebNowPlaying
Music_NowPlaying_Player=MediaMonkey

[Metadata]
Name=Neoristic\\Music
Author=reddit.com/u/khanhas
Description=Display song name and artist. Click at music note icon to next. Click at text to play/pause. Right click at text to activate Music Control to show track progress, player changer.

[MusicAnchor]
Measure=String
String = #Music_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption MusicShape X "(#Bar_OffsetX#+#*Music_X*#-([*MusicIcon:W*]+[*MusicTrackTitle:W*]+#Section_Padding#*2)/2)"][!SetOption MusicIcon X "(#Bar_OffsetX#+#*Music_X*#-([*MusicIcon:W*]+[*MusicTrackTitle:W*]+#Section_Padding#*2)/2)"]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption MusicIcon StringAlign RightCenter][!SetOption MusicTrackTitle StringAlign RightCenter][!SetOption MusicTrackTitle X "(#Bar_OffsetX#+#*Music_X*#)"][!SetOption MusicIcon X "([*MusicTrackTitle:X*]-#Section_Padding#*2)"][!SetOption MusicShape X "([*MusicIcon:X*])"]

[MusicShape]
Meter=Shape
X=(#Bar_OffsetX#+#Music_X#)
Y=(#Bar_OffsetY#)
Shape =Rectangle -#Section_Padding#,0,([MusicTrackTitle:W]+[MusicIcon:W]+#Section_Padding#*4),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme1#
Shape2=Rectangle -#Section_Padding#,0,([MusicIcon:W]+#Section_Padding#*2),#Bar_Height# | StrokeWidth 0 | Fill Color #Color_Scheme3#
DynamicVariables=1

[MusicChooseMeasure]
Measure=String
String=#music_Current_Player#
DynamicVariables=1
IfMatch=(?i)webnowplaying
IfMatchAction=[!EnableMeasureGroup WebNowPlaying]
IfMatch2=(?i)spotify
IfMatchAction2=[!EnableMeasureGroup Spotify]
IfMatch3=(?i)(?<!(web))nowplaying
IfMatchAction3=[!EnableMeasureGroup NowPlaying]
IfMatch4=(?i)gpmdp
IfMatchAction4=[!EnableMeasureGroup GPMDP]

;-------WEBNOWPLAYING-------
[WebNowPlayingTrack]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Title
Substitute="":"N/A"
OnChangeAction=[!UpdateMeter MusicTrackTitle][!UpdateMeter MusicShape][!Redraw]
Disabled=1
Group=WebNowPlaying

[WebNowPlayingArtist]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=Artist
Substitute="":"N/A"
Disabled=1
Group=WebNowPlaying

[WebNowPlayingControl]
Measure=Plugin
Plugin=WebNowPlaying
PlayerType=State
Disabled=1
Group=WebNowPlaying

;-------SPOTIFY-------
[SpotifyTrack]
Measure=Plugin
Plugin=SpotifyPlugin.dll
Type=TrackName
Substitute="":"N/A"
OnChangeAction=[!UpdateMeter MusicTrackTitle][!UpdateMeter MusicShape][!Redraw]
Disabled=1
Group=Spotify

[SpotifyArtist]
Measure=Plugin
Plugin=SpotifyPlugin.dll
Type=ArtistName
Substitute="":"N/A"
Disabled=1
Group=Spotify

[SpotifyControl]
Measure=Plugin
Plugin=NowPlaying
PlayerName=Spotify
PlayerType=Artist
Disabled=1
Group=Spotify

;-------GPMDP-------------
[GPMDPTrack]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=Title
Substitute="":"N/A"
OnChangeAction=[!UpdateMeter MusicTrackTitle][!UpdateMeter MusicShape][!Redraw]
Disabled=1
Group=GPMDP

[GPMDPArtist]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=Artist
Substitute="":"N/A"
Disabled=1
Group=GPMDP

[GPMDPControl]
Measure=Plugin
Plugin=GPMDPPlugin
PlayerInfo=State
Disabled=1
Group=GPMDP
;-------NOWPLAYING-------
[NowPlayingTrack]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#music_NowPlaying_Player#
PlayerType=Title
Substitute="":"N/A"
OnChangeAction=[!UpdateMeter MusicTrackTitle][!UpdateMeter MusicShape][!Redraw]
Disabled=1
Group=NowPlaying

[NowPlayingArtist]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#music_NowPlaying_Player#
PlayerType=Artist
Substitute="":"N/A"
Disabled=1
Group=NowPlaying

[NowPlayingControl]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#music_NowPlaying_Player#
PlayerType=State
Disabled=1
Group=NowPlaying

[MusicIcon]
Meter=String
Text=
FontFace=Siji
FontSize=(#Font_Size#*15/9)
FontColor=#Color_Scheme4#
SolidColor=0,0,0,1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#music_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
H=#Bar_Height#
StringAlign=LeftCenter
MouseOverAction=[!SetOption #CURRENTSECTION# Text ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Text ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!CommandMeasure #music_Current_Player#Control "Next"]
DynamicVariables=1

[MusicTrackTitle]
Meter=String
MeasureName=#music_Current_Player#Track
MeasureName2=#music_Current_Player#Artist
Text=%1 - %2
FontFace=#Font_Face1#
FontSize=#Font_Size#
SolidColor=0,0,0,1
AntiAlias=1
StringAlign=LeftCenter
FontColor=#Color_Scheme2#
ClipString=2
ClipStringW=#music_Width#
ClipStringH=#Bar_Height#
H=#Bar_Height#
X=(#Section_Padding#*2)R
Y=r
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure #music_Current_Player#Control "PlayPause"]
RightMouseUpAction=[!WriteKeyValue Variables MusicControl_Current_Player #music_Current_Player# "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MusicControl.ini"][!WriteKeyValue Variables MusicControl_NowPlaying_Player #music_NowPlaying_Player# "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MusicControl.ini"][!WriteKeyValue Variables Curr_X ([MusicShape:X]+[MusicShape:W]/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MusicControl.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\MusicControl.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\MusicControl.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "MusicControl.ini"][!SetVariable Arrow_Anchor -1 "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts"][!SetVariable Arrow_Offset ([MusicShape:W]/2) "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts"]
