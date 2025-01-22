;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; add instruction , it need push and assert for testing ;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;

; empty stack
add

push int8(16)
; stack length error
add 

push int8(4)
add
assert int8(20)
; stack length error
add


push int8(2)
push int8(2)
add
assert int8(4)




;; END
exit