#!/bin/bash

rm -rf submission
mkdir -p submission
cp ../handout/test_*.cpp ../handout/doctest.h ../handout/dynamic_array_gdb.h ../handout/dynamic_array_gbo.h ../handout/dynamic_array_gbf.h ./submission/
zip -r autograder.zip .
rm -rf submission
