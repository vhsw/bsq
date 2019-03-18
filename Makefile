CC := gcc
CFLAGS := -Wall -Wextra
NAME := bsq
SOURCES := $(wildcard srcs/*.c)

all: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	echo "bip bop all clean"

fclean:
	rm -f $(NAME)
