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
		src/main.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) $(LIB)
	$(CC) $(CFLAGS) $(OFILES) $(LIB) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo COMPILED: $<

$(LIB):
	@make -C libft/

re: fclean all

fclean: clean
	@rm -f $(NAME)
	@echo "DEEP CLEANING"

clean:
	@rm -f $(OFILES)
	@echo "CLEANED UP"

.PHONY: clean re fclean all

# end
