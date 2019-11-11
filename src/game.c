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

	return playGame(1, goban.lines * goban.lines, white, black, goban);
}

int checkDraw(Goban goban, int n, int maxP) {
	if (n == maxP+1) {
		printf("O jogo empatou!");
		endGame(goban);

		return 1;
	}

	return 0;
}

short int playAgain(Player p1, Player p2) {
	int choice;
	printf("-------------- Jogo finalizado ----------------\n");

	showScore(p1, p2);

	printf("Deseja jogar novamente?\n");
	printf("1 - SIM\n2 - NÃO\n");
	
	printf(": ");
	scanf("%d", &choice);

	if (choice == 1) {
		return 1;
	} else {
		return 0;
	}
}

int playGame(int n, int maxP, Player white, Player black, Goban goban) {
	if (checkDraw(goban, n, maxP)) {
		short int result = playAgain(black, white);
		return result;
	}

	int lin, col, valid = 0, result;

	breakline();

	showTurn(n, black, white);

	printGoban(goban);

	printf("Escolha onde quer inserir a peça (lin col): ");
	scanf("%d %d", &lin, &col);

	lin = lin-1;
	col = col-1;

	if ((lin <= goban.lines && lin >= 0) && (col <= goban.columns && col >= 0)) {
		valid = 1;
	} else {
		showInvalidPlay(n, maxP, white, black, goban);
	}

	if (n%2 == 0)
		result = insertPiece(goban, lin, col, 2);
	else
		result = insertPiece(goban, lin, col, 1);
	
	if (!result) {
		return playGame(n, maxP, white, black, goban);
	} else if (result == 2) {
		if (n%2 == 0) {
			white.winCount++;
		} else {
			black.winCount++;
		}
		
		endGame(goban);
		short int result = playAgain(black, white);
		return result;
	} else if (result == 3) {
		if (n%2 == 0) {
			white.captures += 1;
		} else {
			black.captures += 1;
		}

		printf("b - %d, p - %d", white.captures, black.captures);

		if (white.captures == 5) {
			white.winCount++;

			endGame(goban);
			short int result = playAgain(black, white);

			return result;
		} else if(black.captures == 5) {
			black.winCount++;

			endGame(goban);
			short int result = playAgain(black, white);
			
			return result;
		}
	}

	return playGame(n+1, maxP, white, black, goban);
}

void endGame(Goban goban) {
	printf("\n\n\nStatus final do tabuleiro: \n");
	printGoban(goban);
}

void showScore(Player p1, Player p2) {
	printf("Pontuação:\n");
	printf("%s - %d X %d - %s\n", p1.name, p1.winCount, p2.winCount, p2.name);
}

void showTurn(int n, Player p1, Player p2) {
	if (n%2 == 0) {
		printf("É a vez de %s (%c) - %d capturas\n", p2.name, p2.color, p2.captures);
	} else {
		printf("É a vez de %s (%c) - %d capturas\n", p1.name, p1.color, p1.captures);
	}
}

void breakline() {
	puts("");
}

void showInvalidPlay(int n, int maxP, Player p1, Player p2, Goban goban) {
	printf("* -------- Por favor, selecione uma intersecção válida. --------- *\n");
	return playGame(n, maxP, p2, p1, goban);
}