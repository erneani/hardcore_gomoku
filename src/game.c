#include <stdio.h>
#include "./headers/player.h"
#include "./headers/goban.h"
#include "./headers/game.h"

int preGame(Player white, Player black, Goban goban) {
	int maxP;

	black.color = 'P';
	white.color = 'B';
	goban.checks = (int*)malloc(goban.lines * goban.columns * sizeof(int));

	initializeGoban(goban);
	
	printf("Insira a quantidade máxima de partidas: ");
	scanf("%d", &maxP);

	return playGame(1, maxP, white, black, goban);
}

int playGame(int n, int maxP, Player white, Player black, Goban goban) {
	if (n == maxP+1) {
		endGame(goban);

		return 1;
	}

	int lin, col, valid = 0, result;

	puts("");

	if (n%2 == 0) {
		printf("É a vez de %s (%c)\n", white.name, white.color);
	} else {
		printf("É a vez de %s (%c)\n", black.name, black.color);
	}

	printGoban(goban);

	printf("Escolha onde quer inserir a peça (lin col): ");
	scanf("%d %d", &lin, &col);

	lin = lin-1;
	col = col-1;

	if ((lin <= goban.lines && lin >= 0) && (col <= goban.columns && col >= 0)) {
		valid = 1;
	} else {
		printf("* -------- Por favor, selecione uma intersecção válida. --------- *\n");
		return playGame(n, maxP, white, black, goban);
	}

	if (n%2 == 0)
		result = insertPiece(goban, lin, col, 2);
	else
		result = insertPiece(goban, lin, col, 1);
	
	if (!result) {
		return playGame(n, maxP, white, black, goban);
	}

	return playGame(n+1, maxP, white, black, goban);
}

void endGame(Goban goban) {
	printf("\n\n\nStatus final do tabuleiro: \n");
	printGoban(goban);
}