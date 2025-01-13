# EBNF: Extended Buckus-Naur Form 

## Staring rule
S := INSTR [SEP INSTR]* #

## Instructions
INSTR :=
    push VALUE
    | pop
    | dump
    | assert VALUE
    | add
    | sub
    | mul
    | div
    | mod
    | print
    | exit

## Type definitions
VALUE :=
    int8(N)
    | int16(N)
    | int32(N)
    | float(Z)
    | double(Z)

## Numbers
N := [-]?[0..9]+
Z := [-]?[0..9]+.[0..9]+

## Separator
SEP := '\n'+