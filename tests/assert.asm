;; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;;
; Assert instruction , it need push for test ;;;;;;;;;;;;;;;;;;;;;;;;;;;  ;;
;; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; ;;
;;

; empty stack
assert int8(42)

push int8(42)
assert int8(42)

push int16(12345)
assert int16(12345)

push int32(123456789)
assert int32(123456789)

push float(42.42)
assert float(42.42)

push double(123456.789)
assert double(123456.789)

push int8(-42)
assert int8(-42)

push int16(-12345)
assert int16(-12345)

push int32(-123456789)
assert int32(-123456789)

push float(-42.42)
assert float(-42.42)

push double(-123456.789)
assert double(-123456.789)

push int8(0)
assert int8(0)

push int16(0)
assert int16(0)

push int32(0)
assert int32(0)

push float(0.0)
assert float(0.0)

push double(0.0)
assert double(0.0)

push int8(127)
assert int8(127)

push int16(32767)
assert int16(32767)

push int32(2147483647)
assert int32(2147483647)


push int8(-128)
assert int8(-128)

push int16(-32768)
assert int16(-32768)

push int32(-2147483648)
assert int32(-2147483648)


push int8(1)
assert int8(1)

push int16(1)
assert int16(1)

push int32(1)
assert int32(1)

push float(1.0)
assert float(1.0)

push double(1.0)
assert double(1.0)

push int8(-1)
assert int8(-1)

push int16(-1)
assert int16(-1)

push int32(-1)
assert int32(-1)

push float(-1.0)
assert float(-1.0)

push double(-1.0)
assert double(-1.0)

push int8(100)
assert int8(100)

push int16(10000)
assert int16(10000)

push int32(1000000000)
assert int32(1000000000)

push float(100.100)
assert float(100.100)

push double(100000.100)
assert double(100000.100)

push int8(-100)
assert int8(-100)

push int16(-10000)
assert int16(-10000)

push int32(-1000000000)
assert int32(-1000000000)

push float(-100.100)
assert float(-100.100)

push double(-100000.100)
assert double(-100000.100)

; commnets
exit