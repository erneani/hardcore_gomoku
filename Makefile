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
BINS=./bin/player.ghc

# ------------------------------------
# 			  COMPILATION
# ------------------------------------

run: clean compile
	./bin/main.o

clean:
	rm -rf bin/*

compile: player.o
	$(CC) main.c $(BINS) -o $(BIN_PATH)/main.o $(CC_FLAGS)

player.o:
	$(CC) player.c -c -o $(BIN_PATH)/player.ghc $(CC_FLAGS)