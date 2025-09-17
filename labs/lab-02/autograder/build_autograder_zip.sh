#!/bin/bash

rm -rf link
mkdir -p link
cp ../handout/test_*.cpp ../handout/*.h ../handout/*_fast.cpp ./link/
zip -r autograder.zip .
rm -rf link
