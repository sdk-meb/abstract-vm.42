;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; sub instruction , it need push and assert for testing ;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;

; empty stack
sub

push int8(16)
; stack length error
sub 

push int8(4)
sub
assert int8(12)
; stack length error
sub


push int8(2)
push int8(3)
sub
assert int8(-1)




;; END
exit