;; Source code for testing parsing
;;Run this ;;in vm.cpp after uncommenting parser instructions
; Execute;; the program with this file as input

push int8(42)
push int16(-12345)
push int32(2147483647)
push float(3.14)
push double(-42.424242)
dump
; empty line
;; 


pop
assert int8(42) fe
add
sub fr de
mul
div
mod
print
exit
