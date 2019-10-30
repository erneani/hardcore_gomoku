#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./headers/player.h"
#include "./headers/goban.h"
#include "./headers/game.h"

int main()
{
	int result;
	Goban goban;

	srand(time(NULL));

	Player p1, p2;
	p1 = registerPlayer(1);
	p2 = registerPlayer(2);

	do {
		goban = createGoban();

		if (rand() % 2 == 0)
			result = preGame(p1, p2, goban);
		else
			result = preGame(p2, p1, goban);
	} while (result != 0);
	
	if (result == 0) {
		printf("O jogo foi concluído!\n");
		return 0;
	} else {
		printf("O jogo não foi concluído!\n");
		return 1;
	}

}