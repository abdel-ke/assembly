#!/bin/bash
test -f ft_strcpy.o && rm ft_strcpy.o
test -f ft_strcpy && rm ft_strcpy
# nasm -f macho64 ft_strcpy.s
nasm -f macho64 ft_strcpy.s
gcc main.c ft_strcpy.o -o ft_strcpy
./ft_strcpy
rm *.o && rm ft_strcpy

# red=`tput setaf 1`
# green=`tput setaf 2`
# reset=`tput sgr0`
# if [ $? -eq 0 ]; then
#     echo ${green}SUCCESS
# else
#     echo ${red}FAIL
# fi