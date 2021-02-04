nasm -f macho64 hello.s -o hello.o
clang main.c hello.o -o test 
./test
rm *.o test