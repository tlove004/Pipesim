#!/usr/bin/env bash

cd "${0%/*}"

./pipesim
./pipesim -f 1
./pipesim -f 2
./pipesim -i instruction2.txt
./pipesim -i instruction2.txt -f 1
./pipesim -i instruction2.txt -f 2
./pipesim -i instruction3.txt
./pipesim -i instruction3.txt -f 1
./pipesim -i instruction3.txt -f 2
