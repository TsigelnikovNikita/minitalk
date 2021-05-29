NAME	= server

SRCS	= server.c
OBJS	= $(SRCS:%.c=%.o)
LIBFT	= ../libft/libft.a
#HEADERS =
#FLAGS   =	-Wall -Wextra -Werror

.PHONY:	all re clean fclean

all: $(NAME)

run:
	./server

$(NAME): $(OBJS) $(LIBFT)
	gcc -g ${FLAGS} ${OBJS} $(LIBFT) -o ${NAME}

$(LIBFT):
	$(MAKE) -C ../libft

%.o: %.c
	gcc -g ${FLAGS} -o $@ -c $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C ../libft clean

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	$(MAKE) -C ../libft fclean

re: fclean all
