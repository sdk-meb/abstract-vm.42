;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; pop instruction , it need push for more testes solo ;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; empty stack
pop
pop


push int8(42)
pop

; fail
pop

push int16(1337)
push int32(1455)
push float(2.553)
push double(1234.4321)
push int8(-42)

pop
pop
pop
pop
pop

; fail
pop

exit