[Space]
Measure=Plugin
Plugin=HotKey
HotKey=Space
KeyDownAction=[!SetOption SpaceShape Fill "Fill Color #PressedColor#,#PressedOpacity#"][!SetOption SpaceLabel MeterStyle "Key#RGBOverride#Over:S"][!UpdateMeter SpaceLabel][!UpdateMeter SpaceShape][!Redraw]
KeyUpAction=[!SetOption SpaceShape Fill "Fill Color #DefaultColor#,#DefaultOpacity#"][!SetOption SpaceLabel MeterStyle "Key#RGB#:S"][!UpdateMeter SpaceLabel][!UpdateMeter SpaceShape][!Redraw]
