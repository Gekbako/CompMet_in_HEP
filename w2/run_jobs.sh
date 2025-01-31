#!/bin/bash

make

for i in  $(seq 1 10)
do
    # run on linux, for windows .\e1.exe ...
    ./e1.exe $i > bash_output_$i.txt &
done 

wait

echo "all bash jobs finished"