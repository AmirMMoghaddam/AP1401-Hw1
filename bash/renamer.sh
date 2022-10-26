#!/bin/bash

DESDIR=$1
COM="mv"
if [ $2 == "-c" ]; then
    COM="cp"
fi
DATEFILE=$(date +%Y-%m-%d_)
ListFile=$(ls $DESDIR)
if [ -d $DESDIR ]; then
    for file in $ListFile; do
        echo
        $COM "$DESDIR/$file" "$DESDIR/$DATEFILE$file"
    done
else
    echo "the directory does not exist!"
fi
