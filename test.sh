nasm -f macho64 $1 -o test.o
clang main.c test.o -o test 
./test
rm *.o test
