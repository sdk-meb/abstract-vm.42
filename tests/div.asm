;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; div instruction , it need push and assert for testing ;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;

; empty stack
div

push int8(16)
; stack length error
div 

push int8(2)
div
assert int8(8)
; stack length error
div


push int8(2)
push int8(-3)
div
assert int8(0)



;; END
exit