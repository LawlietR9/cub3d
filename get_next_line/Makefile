NAME = gnl
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = ../libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@ $(LIBFT)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all