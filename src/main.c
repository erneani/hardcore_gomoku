#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
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
		printf("1 - SIM\n2 - NÃO\n");
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

int main() {
	int result;
	Goban goban;

	Player p1, p2;

	srand(time(NULL));

	if (loadGame()) {
		Player p[2];
		int dimension;
		int slot;
		char strSlot[10];

		char* line = NULL;
		size_t len = 0;
		ssize_t read;

		int found = 0;

		printf("Você deseja carregar qual jogo salvo? ");
		scanf("%d", &slot);

		sprintf(strSlot, "%d", slot);

		FILE *file;
		file = fopen("./files/save", "r");

		while((read = getline(&line, &len, file)) != -1) {
			if (read <= 2) {
				line[1] = '\0';
				if (strcmp(line, strSlot) == 0) {
					for (int i = 0; i < 2; i++) {
						fscanf(file, "%s", &p[i].name);
						fscanf(file, "%d", &p[i].winCount);
						fscanf(file, "\n");
					}

					fscanf(file, "%d", &dimension);

					found = 1;
				}
			}
		}

		if (!found) {
			printf("\n\n\n\n--------- O jogo não foi encontrado. Tente novamente.---------\n\n\n\n");
			return main();
		}
		
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