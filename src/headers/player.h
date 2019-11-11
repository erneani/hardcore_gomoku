#pragma once

typedef struct {
	char name[50];
	char color;
	int winCount;
	int captures;
} Player;

Player createNewPlayer(char[]);
Player registerPlayer(int);
