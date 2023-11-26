AUX = lib/aux_functions.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SERVER = server
CLIENT = client

SERVER_SRC = src/server.c
CLIENT_SRC = src/client.c

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_BONUS_SRC = src/server_bonus.c
CLIENT_BONUS_SRC = src/client_bonus.c

SERVER_OUT = $(SERVER_SRC:.c=.o)
CLIENT_OUT = $(CLIENT_SRC:.c=.o)

CLIENT_BONUS_OUT = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OUT = $(SERVER_BONUS_SRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(AUX):
	@$(CC) $(CFLAGS) -c lib/aux_functions.c -o $(AUX)

# Mandatory part
$(SERVER): $(SERVER_OUT) $(AUX)
	@$(CC) $(CFLAGS) $(SERVER_OUT) $(AUX) -o $(SERVER)

$(CLIENT): $(CLIENT_OUT) $(AUX)
	@$(CC) $(CFLAGS) $(CLIENT_OUT) $(AUX) -o $(CLIENT)

# Bonus part
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_BONUS_OUT) $(AUX)
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OUT) $(AUX) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OUT) $(AUX)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OUT) $(AUX) -o $(CLIENT_BONUS)

clean:
	@$(RM) $(SERVER_OUT) $(CLIENT_OUT) $(SERVER_BONUS_OUT) $(CLIENT_BONUS_OUT)

fclean: clean
	@$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all
