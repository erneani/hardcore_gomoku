#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/player.h"

Player createNewPlayer(char name[]) {
	Player newPlayer;
	strcpy(newPlayer.name, name);
	newPlayer.winCount = 0;
	newPlayer.captures = 0;

	return newPlayer;
}

Player registerPlayer(int n) {
	char name[50];
	Player p;

	printf("Por favor, insira o nome do jogador %d (somente um nome): ", n);
	scanf("%s", name);

	p = createNewPlayer(name);
	return p;
}
