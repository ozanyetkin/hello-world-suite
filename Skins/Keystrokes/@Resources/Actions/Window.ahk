﻿SD = %A_ScriptDir%
UpOne = % RegExReplace(SD,"[^\\]+\\?$")
UpTwo = % RegExReplace(UpOne,"[^\\]+\\?$")
Path = %UpTwo%Main\Main.ini
WinSet, Disable ,, %Path%,,,
WinSet, ExStyle, +0x20, %Path%,,,
ExitApp