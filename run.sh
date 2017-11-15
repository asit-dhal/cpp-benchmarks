#!/bin/bash

for file in build/bin/*; do
	report_name=$(basename ${file})
	echo "running benchmark ${report_name}..."
    [ -f "$file" ] && [ -x "$file" ] && "$file"
done

