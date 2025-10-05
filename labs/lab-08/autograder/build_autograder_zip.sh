#!/bin/bash

rm -rf submission
mkdir -p submission
cp ../handout/test_*.cpp ./submission/
zip -r autograder.zip .
rm -rf submission
