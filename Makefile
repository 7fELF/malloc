CC = gcc

RM = rm -rf

TARGET_LIB = libmy_malloc.so

CFLAGS	= -Wall -Wextra -fPIC
LDFLAGS = -shared

SRC	= free.c \
		malloc.c \
		realloc.c \
		show_alloc.c \
		calloc.c


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
