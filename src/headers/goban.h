#pragma once

typedef struct {
	int lines;
	int columns;
	int* checks;
} Goban;

Goban createGoban();
void printGoban();
void printGobanHeaders(Goban);
void printGobanMiddleLines(Goban);
void showIntersection(Goban, int, int);
void initializeGoban();
int insertPiece(Goban, int, int, int);