# Nom de la bibliothèque
NAME_c= client
NAME_s = server

# Compilateur et drapeaux
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Ilibft 
# Fichiers sources et objets
SRC_c = client.c
SRC_s = server.c

OBJ_c= $(SRC_c:.c=.o)
OBJ_s = $(SRC_s:.c=.o)

# Règle all
all: $(NAME_c) $(NAME_s)

# Règles pour créer l'exécutable
$(NAME_c): $(OBJ_c)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_c) libft/libft.a -o $(NAME_c)

$(NAME_s): $(OBJ_s)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_s) libft/libft.a -o $(NAME_s)

# Règle clean
clean:
	$(RM) $(OBJ_c) $(OBJ_s)
	$(MAKE) -C libft clean

# Règle fclean
fclean: clean
	$(RM) $(NAME_c) $(NAME_s)
	$(MAKE) -C libft fclean

# Règle re
re: fclean all

.PHONY: all clean fclean re
