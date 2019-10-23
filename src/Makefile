# ------------------------------------
# 			  VARIABLES
# ------------------------------------

# C compiler
CC=gcc

# C flags
CC_FLAGS=-Wall -w    

# Paths
H_PATH=./headers
BIN_PATH=./bin
BINS=./bin/player.ghc ./bin/goban.ghc ./bin/game.ghc

# ------------------------------------
# 			  COMPILATION
# ------------------------------------

run: clean compile
	@./bin/main.o

clean:
	@rm -rf bin/*

compile: player.o goban.o game.o
	@$(CC) main.c $(BINS) -o $(BIN_PATH)/main.o $(CC_FLAGS)

player.o:
	@$(CC) player.c -c -o $(BIN_PATH)/player.ghc $(CC_FLAGS)

goban.o:
	@$(CC) goban.c -c -o $(BIN_PATH)/goban.ghc $(CC_FLAGS)

game.o:
	@$(CC) game.c -c -o $(BIN_PATH)/game.ghc $(CC_FLAGS)