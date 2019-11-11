#pragma once
#include "./player.h"

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
int checkRounds(Goban, int, int, int, int, int);
int checkEnd(Goban, int, int, int);
int insertPiece(Goban, int, int, int);
int checkCaptureMiddle(Goban, int , int , int , int, int);
int checkCaptureRound(Goban, int, int, int, int, int, int, int);
int checkCapture(Goban, int, int, int);
int capturePieces(Goban, int, int, int, int, int, int, int);