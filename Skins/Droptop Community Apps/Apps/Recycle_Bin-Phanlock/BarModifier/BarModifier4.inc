[PhanlockDropaction]
Measure=Plugin
Plugin=RunCommand
Parameter=del /q "#PhanlockRecycleFile#"
State=Hide
OutputType=ANSI
OutputFile=
DynamicVariables=1

[PhanlockDroparea]
Measure=Plugin
Plugin=Drag&Drop
Parent=MeasureDrop
Bounds=CustomApp4
Action=Path
OnOverAction=[!SetVariable PhanlockRecycleFile "$Directory$\$Name$.$Type$"][!UpdateMeasure PhanlockDropaction]
OnDropAction=[!CommandMeasure PhanlockDropaction "Run"]
Group=Droparea
DynamicVariables=1
