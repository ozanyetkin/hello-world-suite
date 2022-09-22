[ResourceGraphDrivesC]
Meter=String
Autoscale=1
MeasureName=DriveCFree
MeasureNAme2=DriveCTotal
MeasureName3=CalcDriveCRead
MeasureNAme4=CalcDriveCWrite
Text=C: //////////////////// [DriveCPercent:1]%#CRLF#F: %1B T: %2B | R: %3 W: %4
InlineSetting=Color | #BarColor#
InlinePattern=\/
InlineSetting2=Color | #Accent#
InlinePattern2=C: (/{[DriveCActual:0]}).*
DynamicVariables=1
MEterStyle=Text

[DriveCTotal]
Measure=FreeDiskSpace
Total=1
Drive=C:
UpdateDivider=120
Substitute=^0$":"0.000001"

[DriveCFree]
Measure=FreeDiskSpace
Drive=C:
UpdateDivider=120
Substitute="^0$":"0.000001"

[DriveCPercent]
Measure=Calc
Formula=(DriveCTotal-DriveCFree)/DriveCTotal*100
UpdateDivider=120

[DriveCActual]
Measure=Calc
Formula=DriveCPercent/5
UpdateDivider=120

[MeasureDriveCRead]
Measure=Plugin
Plugin=UsageMonitor
Category=LogicalDisk
Counter=Disk Read Bytes/sec
Name=C:

[MeasureDriveCWrite]
Measure=Plugin
Plugin=UsageMonitor
Category=LogicalDisk
Counter=Disk Write Bytes/sec
Name=C:

[CalcDriveCRead]
Measure=calc
Formula=MeasureDriveCRead

[CalcDriveCWrite]
Measure=Calc
Formula=MeasureDriveCWrite
[Dot5]
Meter=String
MeterStyle=Dots | FirstAlign:#Align#