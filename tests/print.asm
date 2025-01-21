;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; print instruction , it cant't tested solo, so we seek push ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; empty stack
print

; ASCII value for 'H'
push int8(72) 
print

; ASCII value for 'e'
push int8(101) 
print

; ASCII value for 'l'
push int8(108) 
print

; ASCII value for 'l'
push int8(108) 
print

; ASCII value for 'o'
push int8(111) 
print

; ASCII value for ' '
push int8(32) 
print

; ASCII value for 'W'
push int8(87) 
print

; ASCII value for 'o'
push int8(111) 
print

; ASCII value for 'r'
push int8(114) 
print

; ASCII value for 'l'
push int8(108) 
print

; ASCII value for 'd'
push int8(100) 
print

; ASCII value for '!'
push int8(33) 
print

; Non-printable ASCII value (e.g., 7 for bell)
push int8(7)
print

; Overrange value (e.g., 128)
push int8(128)
print

; Float value
push float(3.14)
print

; Double value
push double(2.71828)
print

; Int32 value
push int32(123456)
print

exit

