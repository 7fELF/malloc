##
## Makefile for PSU_2016_malloc in /Users/pichar_v/Documents/tek2/PSU_2016_mal
##
## Made by Valentin Pichard
## Login   <valentin.pichard@epitech.eu>
##
## Started on  Fri Jan 27 15:07:09 2017 Linus Torvalds
## Last update Fri Jan 27 15:07:09 2017 Linus Torvalds
##

CC		= gcc

RM		= rm -rf

NAME	= my_malloc

FLAGS	= -Wall -Wextra -Werror

SRC		= 	common.c \
			free.c \
			malloc.c \
			realloc.c \
			show_alloc.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
