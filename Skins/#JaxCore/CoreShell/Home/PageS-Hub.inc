[Variables]
Page.Subpage=0
Sec.drag_bar_text=S-Hub by JaxCore
Set.IconStyle=S-Hub

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[m.ShowInToolbar]
WindowTitle=S-Hub by JaxCore

[Header.Shape]
Meter=

[Header.String]
Meter=

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

; ------------------------------ Include subpage ----------------------------- ;

@includeSubpage=Assets\PageS-Hub\Subpage#Page.subpage#.inc


[AnchorSuppli]
Meter=String
Container=BC
x=r
Y=(50*[Set.S])r
DynamicVariables=1
