##
## Makefile for PSU_2016_malloc in /Users/pichar_v/Documents/tek2/PSU_2016_mal
##
## Made by Valentin Pichard
## Login   <valentin.pichard@epitech.eu>
##
## Started on  Fri Jan 27 15:07:09 2017 Linus Torvalds
## Last update Fri Jan 27 15:07:09 2017 Linus Torvalds
##

CC = gcc

RM = rm -rf

TARGET_LIB = libmy_malloc.so

CFLAGS	= -Wall -Wextra -Werror -fPIC -O3
LDFLAGS = -shared


# CC = clang
# CFLAGS = -Weverything -fPIC -g

SRC	= free.c \
			malloc.c \
			realloc.c \
			show_alloc.c \


OBJS = $(SRC:.c=.o)

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(TARGET_LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET_LIB)

re: clean fclean all

.PHONY: all clean fclean re
