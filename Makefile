# Makefile
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = my_mastermind.c utils.c
OBJS = $(SRCS:.c=.o)
NAME = my_mastermind

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
