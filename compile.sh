#!/usr/bin/env zsh

if [[ -z "$1" ]] then 
    echo "missing filename."
    exit
fi 

FILENAME=$(basename $1 .cpp)

clang++ -g -Wall -Wextra -std=c++20 $1 -o bin/$FILENAME

shift 1
./bin/$FILENAME $@
