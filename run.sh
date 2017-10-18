#!/bin/bash

for file in build/bin/*; do
    [ -f "$file" ] && [ -x "$file" ] && "$file" --benchmark_out=${file}.csv --benchmark_out_format=csv
done
