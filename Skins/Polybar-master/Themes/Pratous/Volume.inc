[Variables]
Volume_X =1568
;Left, Right or Center
Volume_Anchor=right

[Metadata]
Name=Pratous\\Volume
Author=reddit.com/u/khanhas
Description=Display volume, increase and decrease volume by mouse scroll, click at speaker icon to mute. Click at volume number to activate volume slider and audio device changer.

[VolumeAnchor]
Measure=String
String = #Volume_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption VolumeIcon X "(#Bar_OffsetX#+#*Volume_X*#-([*VolumeIcon:W*]+[*Volume:W*]+10)/2)"][!SetOption Volume X 10R]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption VolumeIcon StringAlign RightCenter][!SetOption Volume StringAlign RightCenter][!SetOption VolumeIcon X "([*Volume:X*]-10)"][!SetOption Volume X "(#Bar_OffsetX#+#*Volume_X*#)"]

[VolumeLevel]
Measure=Plugin
Plugin=Win7AudioPlugin
Group = Volume

[VolumeLevelCalc]
Measure=Calc
Formula=VolumeLevel <= 0 ? 0 : VolumeLevel
IfCondition=VolumeLevelCalc = 0
IfTrueAction=[!SetOption VolumeIcon Text ""][!UpdateMeterGroup Volume][!Redraw]
IfCondition2=(VolumeLevelCalc <= 50) && (VolumeLevelCalc > 0)
IfTrueAction2=[!SetOption VolumeIcon Text ""][!UpdateMeterGroup Volume][!Redraw]
IfCondition3=VolumeLevelCalc > 50 
IfTrueAction3=[!SetOption VolumeIcon Text ""][!UpdateMeterGroup Volume][!Redraw]
Group = Volume

[VolumeIcon]
Meter=String
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Volume_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
LeftMouseUpAction=[!CommandMeasure VolumeLevel "ToggleMute"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!Redraw]
Group=Volume
DynamicVariables=1

[Volume]
Meter=String
MeasureName=VolumeLevelCalc
Postfix=%
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=10R
Y=r
MouseScrollDownAction=[!CommandMeasure VolumeLevel "ChangeVolume -5"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!Redraw]
MouseScrollUpAction  =[!CommandMeasure VolumeLevel "ChangeVolume +5"][!UpdateMeasureGroup Volume][!UpdateMeterGroup Volume][!Redraw]
LeftMouseUpAction =[!WriteKeyValue Variables Curr_X ([VolumeIcon:X]+([VolumeIcon:W]+[Volume:W])/2+#CURRENTCONFIGX#) "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\VolumeControl.ini"][!WriteKeyValue Variables Curr_Y [SubSkinYPositionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\VolumeControl.ini"][!WriteKeyValue Variables Dir [SubSkinDirectionCalc] "#ROOTCONFIGPATH#\Themes\#Theme#\Additional_Comps_And_Scripts\VolumeControl.ini"][!ToggleConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "VolumeControl.ini"]
MouseOverAction=[!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
DynamicVariables=1
SolidColor=0,0,0,1
Group=Volume
RightMouseUpAction=["sndvol.exe"]
