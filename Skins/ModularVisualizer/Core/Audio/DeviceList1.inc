
[DeviceBox0]
Meter=Shape
MeterStyle=Device:S
LeftMouseUpAction=[!WriteKeyValue Variables DeviceName "Speakers (Realtek(R) Audio)" "#Sec.SaveLocation2#"][!WriteKeyValue Variables DeviceID "{0.0.0.00000000}.{c7f25a2d-5f7e-457d-b423-5caaf714719b}" "#Sec.SaveLocation2#"][!UpdateMeasure "Auto_Refresh:M"]
[DeviceName0]
Meter=String
Text=Speakers (Realtek(R) Audio)
MeterStyle=Set.String:S | DeviceName:S

[DeviceBox1]
Meter=Shape
MeterStyle=Device:S
LeftMouseUpAction=[!WriteKeyValue Variables DeviceName "DELL U2414H (Intel(R) Display Audio)" "#Sec.SaveLocation2#"][!WriteKeyValue Variables DeviceID "{0.0.0.00000000}.{ee8c0818-68e4-4069-b68e-38ec90441bf2}" "#Sec.SaveLocation2#"][!UpdateMeasure "Auto_Refresh:M"]
[DeviceName1]
Meter=String
Text=DELL U2414H (Intel(R) Display Audio)
MeterStyle=Set.String:S | DeviceName:S

[DeviceBox2]
Meter=Shape
MeterStyle=Device:S
LeftMouseUpAction=[!WriteKeyValue Variables DeviceName "Microphone (Realtek(R) Audio)" "#Sec.SaveLocation2#"][!WriteKeyValue Variables DeviceID "{0.0.1.00000000}.{0f1ec5e3-cb4d-40cf-8d50-174bd52f6335}" "#Sec.SaveLocation2#"][!UpdateMeasure "Auto_Refresh:M"]
[DeviceName2]
Meter=String
Text=Microphone (Realtek(R) Audio)
MeterStyle=Set.String:S | DeviceName:S

