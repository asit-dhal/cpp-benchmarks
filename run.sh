#!/bin/bash

mkdir -p build/reports

for file in build/bin/*; do
	report_name=$(basename ${file})
	report_path="build/reports/${report_name}.csv"
	echo "running benchmark ${report_name}..."
    [ -f "$file" ] && [ -x "$file" ] && "$file" --benchmark_out="${report_path}" --benchmark_out_format=csv
done

for file in build/reports/*.csv; do
    sed -i '/WARNING/d' ${file}
    sed -i -e '1,2d' ${file}
done

for file in build/reports/*.csv; do
	echo "post processing ${file}..."
    python tools/postprocess.py ${file}
done
