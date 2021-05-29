NAME	= client

SRCS	= client.c
OBJS	= $(SRCS:%.c=%.o)
LIBFT	= ../libft/libft.a
#HEADERS =
#FLAGS   =	-Wall -Wextra -Werror

.PHONY:	all re clean fclean

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc -g ${FLAGS} ${OBJS} $(LIBFT) -o ${NAME}

$(LIBFT):
	$(MAKE) -C ../libft

%.o: %.c
	gcc -g ${FLAGS} -o $@ -c $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C ../libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ../libft fclean

re: fclean all
