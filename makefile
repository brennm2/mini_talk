SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus


LIBFT = ./libs/Libft/libft.a


CC = gcc -g
CCFLAGS = -Wall -Werror -Wextra 
RM = rm
RMFLAGS= -f 

SRC_SERVER = src/server.c
	
SRC_CLIENT = src/client.c

SRC_SERVER_BONUS = src/server_bonus.c

SRC_CLIENT_BONUS = src/client_bonus.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

#BONUS ------------------------------------------------------

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) -o $(CLIENT_BONUS)


#BONUS ------------------------------------------------------
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
