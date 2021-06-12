#!/usr/bin/env bash

echo "Compiling object file..."
mkdir build
g++ -c -Iinclude/ src/sum.cpp -o build/sum.o
g++ -c -Iinclude/ src/subtract.cpp -o build/subtract.o

echo "Creating static library..."
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

echo "Compiling main with created static library..."
g++ -Iinclude/ src/main.cpp build/libipb_arithmetic.a -o build/main

echo "Running compiled applicaton..."
./build/main