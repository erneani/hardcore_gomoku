#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./headers/player.h"
#include "./headers/goban.h"
#include "./headers/game.h"

short int loadGame() {
	FILE *file;
	file = fopen("./files/save", "r");

	if (file == NULL) {
		return 0;
	} else {
		printf("Deseja carregar o jogo anterior?\n");
		printf("1 - SIM\nQualquer outra tecla - NÃO\n");
		printf("Resposta: ");

		int option;
		scanf("%d", &option);
		if (option == 1) {
			return 1;
		} else {
			return 0;
		}
	}
}

short int recoverGameFromSave() {

}

int main() {
	int result;
	Goban goban;

	Player p1, p2;

	srand(time(NULL));

	if (loadGame()) {
		Player p[2];
		int dimension;

		FILE *file;
		file = fopen("./files/save", "r");

		for (int i = 0; i < 2; i++) {
			fscanf(file, "%s", &p[i].name);
			fscanf(file, "%d", &p[i].winCount);
			fscanf(file, "\n");
		}

		fscanf(file, "%d", &dimension);
		fclose(file);

		p1 = loadPlayerFromFile(p[0].name, p[0].winCount);
		p2 = loadPlayerFromFile(p[1].name, p[1].winCount);
		goban = loadGobanFromFile(dimension);
	} else {
		p1 = registerPlayer(1);
		p2 = registerPlayer(2);

		goban = createGoban();
	}

	do {
		if (rand() % 2 == 0) {
			result = preGame(p1, p2, goban);
		}
		else {
			result = preGame(p2, p1, goban);
		}
	} while (result != 0);
	
	if (result == 0) {
		printf("O jogo foi concluído!\n");
		return 0;
	} else {
		printf("O jogo não foi concluído!\n");
		return 1;
	}
}