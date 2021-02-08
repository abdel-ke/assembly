#!/bin/bash
test -f $1 && rm $1
test -f $2 && rm $2
nasm -f macho64 hello.s
gcc main.c $1 -o $2
./$2
