;; a long test must no crash

; Using max values for each type and respecting the hierarchy


push int8(127)         ; Maximum value for int8
push int8(1)
add
assert int16(128)      ; Result fits within int16

push int16(32767)      ; Maximum value for int16
push int16(1)
add
assert int32(32768)    ; Result fits within int32

push int32(2147483647) ; Maximum value for int32
push int32(1)
add
assert float(2147483648.0) ; Result fits within float

push float(3.4028235e+38)  ; Maximum value for float
push float(1.0e+30)
add

push double(1.7976931348623157e+308) ; Maximum value for double
push double(1.0e+300)
add

; out double(inf)
dump




exit; END