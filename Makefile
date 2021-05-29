SERVER = server
CLIENT = client

SERVER_SRCS	= server_src/server.c
CLIENT_SRCS	= client_src/client.c
SERVER_OBJS	= $(SERVER_SRCS:%.c=%.o)
CLIENT_OBJS	= $(CLIENT_SRCS:%.c=%.o)
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

.PHONY:	all re clean fclean

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) $(CLIENT_OBJS)
	gcc ${FLAGS} ${CLIENT_OBJS} $(LIBFT) -o ${CLIENT}

$(SERVER): $(LIBFT) $(SERVER_OBJS)
	gcc ${FLAGS} ${SERVER_OBJS} $(LIBFT) -o ${SERVER}

$(LIBFT):
	$(MAKE) -C ./libft

%.o: %.c
	gcc ${FLAGS} -o $@ -c $<

clean:
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)
	$(MAKE) -C ./libft clean

fclean:
	rm -f $(SERVER_OBJS) $(SERVER)
	rm -f $(CLIENT_OBJS) $(CLIENT)
	$(MAKE) -C ./libft fclean

re: fclean all
