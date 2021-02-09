NAME = libasm

NAME_LIB = libasm.a

SRCS =	ft_strcpy.s\
		ft_strlen.s\
		ft_strcmp.s

NASM = nasm
NASMFLAGS = -f macho64

OBJ = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME_LIB) $(OBJ)
	@echo "\n\x1b[32mResult"
ccproject :
	$(CC) $(CFLAGS) main.c $(NAME_LIB)

clean :
	@rm -f $(OBJ) main $(NAME_LIB)
re : clean all