SOURCES = server.c client.c helperfn.c
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: server client

server: server.o helperfn.o
	$(CC) $(FLAGS) -o $@ $^

client: client.o helperfn.o
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c minitalk.h
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re