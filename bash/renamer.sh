#!/bin/bash
for file in *.*; do
    mv "$file" "${file/_half_half./_Hi.}"
done
