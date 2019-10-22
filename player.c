#include <stdio.h>
#include <string.h>
#include "./headers/player.h"

Player createNewPlayer(char name[]) {
	Player newPlayer;
	strcpy(newPlayer.name, name);

	return newPlayer;
}

Player getPlayer(int n) {
	char name[50];
	Player p;

	printf("Por favor, insira o nome do jogador %d (somente um nome): ", n);
	scanf("%s", name);

	p = createNewPlayer(name);
	return p;
}