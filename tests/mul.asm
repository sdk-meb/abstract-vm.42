;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; mul instruction , it need push and assert for testing ;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;

; empty stack
mul

push int8(16)
; stack length error
mul 

push int8(4)
mul
assert int8(64)
; stack length error
mul


push int8(2)
push int8(-3)
mul
assert int8(-6)
assert int8(-5)



;; END
exit