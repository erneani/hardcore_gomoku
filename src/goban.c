#include <stdio.h>
#include "./headers/goban.h"

Goban createGoban()
{
	int n, valid = 0;

	printf("Tamanho do Goban (4 < n < 20): ");
	do {
		scanf("%d", &n);

		if (n < 4 || n > 19) {
			printf("Tamanho inválido!\n");
			printf("Insira novamente o tamanho (4 < n < 20): ");
		} else {
			valid = 1;
		}
	} while(!valid);
	
	Goban newGoban;
	newGoban.lines   = n;
	newGoban.columns = n;
	
	return newGoban;
}

void printGoban(Goban goban)
{
	printGobanHeaders(goban);

	for (int i = 0; i < goban.lines; ++i) {
		for (int j = 0; j < goban.columns; ++j) {
			showIntersection(goban, i, j);
		}
		
		printf(" %d\n", i+1);

		if (i != goban.lines - 1)
			printGobanMiddleLines(goban);
	}
}

void printGobanHeaders(Goban goban) {
	for (int i = 0; i < goban.lines; i++) {
		if (i + 1 < 9) {
			printf("%d   ", i + 1);
		} else {
			printf("%d  ", i + 1);
		}
	}
	puts("");
}

void printGobanMiddleLines(Goban goban) {
	for (int i = 0; i < goban.lines; i++) {
		printf("|   ");
	}
	puts("");
}

void showIntersection(Goban goban, int lin, int col) {
	int offset = lin * goban.columns + col;

	if (col == goban.columns - 1) {
		if (goban.checks[offset] == 1) {
			printf("P");
		} else if (goban.checks[offset] == 2) {
			printf("B");
		} else {
			printf("-");
		}
	} else {
		if (goban.checks[offset] == 1) {
			printf("P---");
		} else if (goban.checks[offset] == 2) {
			printf("B---");
		} else {
			printf("----");
		}
	}
}

void initializeGoban(Goban goban) {
	int offset;
	
	for (int i = 0; i < goban.lines; i++) {
		for (int j = 0; j < goban.columns; j++) {
			offset = (i * goban.columns) + j;
			goban.checks[offset] = 0;
		}
	}
}

int checkRounds(Goban goban, int lin, int col, int itX, int itY, int piece) {
	int offset = (lin * goban.columns) + col; 
	
	if (goban.checks[offset] == piece)
		return 1 + checkRounds(goban, lin+itX, col+itY, itX, itY, piece);
	else
		return 0;
}

int checkEnd(Goban goban, int lin, int col, int piece) {
	int sumX1 = checkRounds(goban, lin+1, col, 1, 0, 2);
	int sumX2 = checkRounds(goban, lin-1, col, -1, 0, 2);
		
	if (sumX1 + sumX2 >= 4)
		return 1;

	int sumY1 = checkRounds(goban, lin, col-1, 0, -1, 2);
	int sumY2 = checkRounds(goban, lin, col+1, 0, 1, 2);
	
	if (sumY1 + sumY2 >= 4)
		return 1;

	int sumD11 = checkRounds(goban, lin-1, col-1, -1, -1, 2);
	int sumD12 = checkRounds(goban, lin+1, col+1, 1, 1, 2);

	if (sumD11 + sumD12 >= 4)
		return 1;

	int sumD21 = checkRounds(goban, lin+1, col-1, 1, -1, 2);
	int sumD22 = checkRounds(goban, lin-1, col+1, -1, 1, 2);

	if (sumD21 + sumD22 >= 4)
		return 1;

	return 0;
}

int insertPiece(Goban goban, int lin, int col, int piece) {
	int offset = (lin * goban.columns) + col;

	if (goban.checks[offset] == 0) {
		goban.checks[offset] = piece;

		if (checkEnd(goban, lin, col, piece)) {
			printf("O jogador %d ganhou!", piece);
			return 2;
		}
		else
			return 1;
	} else {
		printf("Esta interseção já possui uma peça.\n");
		return 0;
	}
}