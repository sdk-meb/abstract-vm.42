;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Opearands limits , it need push and assert for testing ;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;

;; __LIMITS__

; __INT8_MAX = 127
; __INT8_MIN = -128

; __INT16_MAX = 32767
; __INT16_MIN = -32768

; __INT32_MAX = 2147483647
; __INT32_MIN = -2147483648

; __FLT_MAX__ = 3.402823466e+38 ; Maximum finite float value
; __FLT_MIN__ = 1.175494351e-38 ; Minimum positive normalized float value

; __DBL_MAX__ = 1.7976931348623158e+308 ; Maximum finite double value
; __DBL_MIN__ = 2.2250738585072014e-308 ; Minimum positive normalized double value


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; __INT8_MAX
push int8(             127               )
assert int8(             127             )

; __INT8_MIN
push int8(                 -128           )
assert int8(                -128          )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; __INT16_MAX
push int16(             32767               )
assert int16(             32767             )

; __INT16_MIN
push int16(                 -32768           )
assert int16(                -32768          )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; __INT32_MAX
push int32(             2147483647               )
assert int32(             2147483647             )

; __INT32_MIN
push int32(                 -2147483648          )
assert int32(                -2147483648         )



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; __FLT_MAX__
push float(          3.402823466e+38      )
assert float(           3.402823466e+38   )

; __FLT_MIN__
push float(                  1.175494351e-38        )
assert float(             1.175494351e-38           )


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; __DBL_MAX__
push double(    1.7976931348623158e+308         )
assert double(      1.7976931348623158e+308     )

; __DBL_MIN__
push double(                  2.2250738585072014e-308       )
assert double(             2.2250738585072014e-308          )



exit