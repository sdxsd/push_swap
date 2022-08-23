##
# push_swap
#
# @file
# @version 0.1

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIB = libft/libft.a
CFILES = \
		src/main.c \
		src/push.c \
		src/rotate.c \
		src/reverse_rotate.c \
		src/sort_small.c \
		src/flatten.c \
		src/list.c \
		src/sort.c \
		src/input.c \
		src/util.c \
		src/swap.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) $(LIB)
	$(CC) $(CFLAGS) $(OFILES) $(LIB) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo COMPILED: $<

$(LIB):
	git submodule update --init libft/
	@make bonus -C libft/

re: fclean all

fclean: clean
	@rm -f $(NAME)
	@make clean -C libft/
	@echo "DEEP CLEANING"

clean:
	@rm -f $(OFILES)
	@echo "CLEANED UP"

.PHONY: clean re fclean all libft

# end
