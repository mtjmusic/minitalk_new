CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) server client

$(LIBFT):
	@cd libft && $(MAKE)

server: $(LIBFT) server.c
	$(CC) $(FLAGS) -o server server.c $(LIBFT) -g

client: $(LIBFT) client.c
	$(CC) $(FLAGS) -o client client.c $(LIBFT) -g

clean:
	rm -f server client

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(LIBFT)

re: fclean all