#!/bin/bash

files="$(ls)"

for file in ${files[@]}
do
   [[ -d "$file" ]] && echo "$file" && cd "$file" && rm -rf .git && cd ..
done
