#!/bin/sh

make
test_files=$(ls tests/*)

for file in $test_files; do
    echo starting test with $file ':'
    ./build/Abstractvm $file 
    sleep 2
    echo TEST END ';'
done


echo starting test with standard input':' 
./build/Abstractvm