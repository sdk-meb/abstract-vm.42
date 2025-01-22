;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; mod instruction , it need push and assert for testing ;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;

; empty stack
mod

push int8(16)
; stack length error
mod 

push int8(2)

mod
; stack length error
mod
assert int8(0)

push int8(2)
mod
assert int8(0)

push int8(2)
push int8(0)
; div by 0
mod

push int32(999)
push double(900.9823)
mod
assert double(99)


;; END
exit