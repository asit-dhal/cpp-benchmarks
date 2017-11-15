#!/bin/bash

mkdir -p build/reports
mkdir -p build/mds

#for file in build/bin/*; do
#	report_name=$(basename ${file})
#	report_path="build/reports/${report_name}.csv"
#	echo "running benchmark ${report_name}..."
#    [ -f "$file" ] && [ -x "$file" ] && "$file" --benchmark_out="${report_path}" --benchmark_out_format=csv
#done

#for file in build/reports/*.csv; do
#    sed -i '/WARNING/d' ${file}
#    sed -i -e '1,2d' ${file}
#done

for file in build/reports/*.csv; do
	echo "post processing ${file}..."
	md_name=$(basename ${file})
	md_path="build/mds/${md_name}.md"
    build/bin/postprocess -ip=${file} -op=${md_path}
done

echo > README.md

for file in build/mds/*.md; do
	cat "$file" >> README.md
	echo $'\n' >> README.md
done