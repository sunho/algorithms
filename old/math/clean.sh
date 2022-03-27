#!/bin/bash

EXTS=( .fls .fdb_latexmk .log .aux .synctex.gz )
for i in "${EXTS[@]}"
do
    find . -name "*$i" -type f -delete
done