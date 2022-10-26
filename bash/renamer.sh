#!/bin/bash

DESDIR=$1
COM="mv"
TexT="changing name to: "
case $2 in
"-c")
    COM="cp"
    TexT="making copy: "
    ;;
"--copy")
    COM="cp"
    TexT="making copy: "
    ;;
esac
DATEFILE=$(date +%Y-%m-%d_)
ListFile=$(ls $DESDIR)
if [ -d $DESDIR ]; then
    echo "directory submitted successfully!"
    for file in $ListFile; do

        $COM "$DESDIR/$file" "$DESDIR/$DATEFILE$file"
        filename=$(basename -- "$file")
        extension="${filename##*.}"
        echo "name: $file    type: .$extension       ->   $TexT $DATEFILE$file"

    done
else
    echo "the directory does not exist!"
fi
