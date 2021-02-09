NAME = libasm

NAME_LIB = libasm.a

SRCS = ft_strcpy.s
	# hello.s\

NASM = nasm

NASMFLAGS = -f macho64

OBJ = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME_LIB) $(OBJ)
	gcc main.c hello.o -o strlen
ccproject :
	$(CC) $(CFLAGS) main.c $(NAME_LIB)
	
clean :
	rm -f $(OBJ)
	rm -f strlen
	rm -f $(NAME_LIB)
re : clean all