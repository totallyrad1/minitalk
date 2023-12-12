NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = extfn.c ft_printf.c print_c.c print_id.c print_p.c print_s.c print_u.c print_Xx.c
OBJ = $(SRC:.c=.o)
AR = ar -rc
DIR = .

all : ${NAME}

%.o : %.c ft_printf.h
	${CC} ${FLAGS} -c $< -o $@ -I ${DIR}

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re :	fclean all

.PHONY : all clean fclean re