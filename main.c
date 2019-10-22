#include <stdio.h>
#include "./headers/player.h"

int main()
{
	Player p1, p2;
	p1 = getPlayer(1);
	p2 = getPlayer(2);

	printf("Olá %s & %s.\n", p1.name, p2.name);

	return 0;
}