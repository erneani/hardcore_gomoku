#pragma once

typedef struct {
	char name[50];
	char color;
	int winCount;
} Player;

Player createNewPlayer(char[]);
Player registerPlayer(int);
Player selectPlayerToStart();