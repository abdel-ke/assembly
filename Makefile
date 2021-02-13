NAME = libasm

NAME_LIB = libasm.a

SRCS =	ft_strcpy.s\
		ft_strlen.s\
		ft_strcmp.s\
		ft_write.s\
		ft_read.s

NASM = nasm
NASMFLAGS = -f macho64

OBJ = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME_LIB) $(OBJ)
	@echo "\n\033[32m--------- successfully ---------\033[0m"

ccproject :
	$(CC) $(CFLAGS) main.c $(NAME_LIB)

clean :
	@rm -f $(OBJ) main $(NAME_LIB)
re : clean all