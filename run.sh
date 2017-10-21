#!/bin/bash

mkdir -p build/reports

for file in build/bin/*; do
	report_name=$(basename ${file})
	report_path="build/reports/${report_name}.csv"
    [ -f "$file" ] && [ -x "$file" ] && "$file" --benchmark_out="${report_path}" --benchmark_out_format=csv
done

for file in build/reports/*.csv; do
    sed -i '/WARNING/d' ${file}
    sed -e '1,2d' ${file}
done
