[ActionTimer]
Measure=Plugin
Plugin=ActionTimer
DynamicVariables=1
ActionList1=Show | Custom0 | Repeat In,2,#AniSteps#
ActionList2=SaveLocation | Repeat Out,2,#AniSteps# | Hide
Show=[!FadeDuration 0][!CommandMeasure Func "initActions(1)"][!Show]
Hide=[!Hide]
In=[!CommandMeasure Func "tweenAnimation('in')"]
Out=[!CommandMeasure Func "tweenAnimation('out')"]
SaveLocation=[!CommandMeasure Func "initActions(-1)"][!CommandMeasure Func "saveLocation()"]


; ---------------------------------------------------------------------------- ;
;                                     Load                                     ;
; ---------------------------------------------------------------------------- ;

[ACTIONLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Stop 2"][!CommandMeasure ActionTimer "Execute 1"]
Disabled=1
Group=NUOL

[ACTIONUNLOAD]
Measure=String
OnUpdateAction=[!CommandMeasure ActionTimer "Stop 1"][!CommandMeasure ActionTimer "Execute 2"]
Disabled=1
Group=NUOL

[ImportAnimated]
Measure=String
OnUpdateAction=[!SetVariable ActualBlur #Blur#][!UpdateMeasure FrostedGlass]

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;
