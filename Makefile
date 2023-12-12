SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
LIBFTPRINTF	=	ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	ft_printf

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(LIBFTPRINTF) server client

server: server.o $(LIBFTPRINTF) 
	$(CC) $(FLAGS) $(LIBFTPRINTF) -o $@ $< 

client: client.o $(LIBFTPRINTF)
	$(CC) $(FLAGS) $(LIBFTPRINTF) -o $@ $<

%.o: %.c
	$(CC) $(FLAGS) -c $?

$(LIBFTPRINTF):
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	rm -f $(OBJECTS)
	
fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	rm -f server client

re: fclean all

.PHONY: all clean fclean re