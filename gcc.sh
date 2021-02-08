#!/bin/bash
test -f $1 && rm $1
test -f $2 && rm $2
nasm -f macho64 hello.s
gcc main.c $1 -o $2
./$2
test -f $1 && rm $1
test -f $2 && rm $2


red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`
if [ $? -eq 0 ]; then
    echo ${green}SUCCESS
else
    echo ${red}FAIL
fi