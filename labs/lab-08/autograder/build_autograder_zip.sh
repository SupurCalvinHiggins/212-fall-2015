#!/bin/bash

rm -rf ./submission/ ./autograder.zip
mkdir -p ./submission/
cp ../handout/test_set.cpp ./submission/
cp ../handout/test_map.cpp ./submission/
cp ../handout/test_sequence.cpp ./submission/
zip -r autograder.zip .
rm -rf ./submission/