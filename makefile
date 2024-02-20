SERVER = server
CLIENT = client


LIBFT = ./libs/Libft/libft.a



CC = gcc
CCFLAGS = -Wall -Werror -Wextra 
RM = rm
RMFLAGS= -f 

SRC_SERVER = src/server.c \
	
	SRC_CLIENT = src/client.c 

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
all: $(SERVER) $(CLIENT)


$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)
	@echo "Server and Client ready to roll!"




# $(NAME): $(OBJ) $(LIBFT) 
# 	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libs/Libft/


# bonus: $(NAME_BONUS)

# $(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) 
# 	$(CC) $(CCFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BONUS)

# %.o: %.c
# 	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	$(RM) $(RMFLAGS) $(OBJ_SERVER) $(OBJ_CLIENT) $(SERVER) $(CLIENT)
	$(MAKE) fclean -C ./libs/Libft/

# re: fclean all bonus
