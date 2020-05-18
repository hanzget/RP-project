
#include "enemy.h"
#include "Console.h"
#include "Windows.h"
#include <ctime>


int Ex = 5;
int Ey = 5;

enemy::enemy()
{
}


enemy::~enemy()
{
}

void enemy::Move(int V, int H)
{
	int Ey2 = Ey + V;
	int Ex2 = Ex + H;

	if (map[Ey2][Ex2] == '&')
	{
		health -= 1;
	}

	if (map[Ey][Ex2] == ' '
		|| map[Ey][Ex2] == '&')
	{
		map[Ey][Ex] = ' ';
		Ex += H;
		map[Ey][Ex] = enemy_symbol;
	}
	if (map[Ey2][Ex] == ' '
		|| map[Ey][Ex2] == '&')
	{
		map[Ey][Ex] = ' ';
		Ey += V;
		map[Ey][Ex] = enemy_symbol;
	}
}

int enemy::Init(int V, int H)
{
	map[V][H] = enemy_symbol;
	if (!location_set)
	{
		Ex = H;
		Ey = V;
		map[Ey][Ex] = enemy_symbol;
		location_set = true;
	}
	//aggro range
	/*The radius around an aggro monster in a MMORPG game whereby if a player enters this radius, 
	  the monster will attack the player.Knowing the aggro range of the monsters in a game can be the key to staying alive in dangerous areas.
		- Player1: "Be careful those guys have a huge aggro range."

		- Player2 : "I know."

		- Player1 : "That's too close, get back!"

		- Player2 : "Oh no! Aggro!"

		- Player1 : "Jeeze, what a n00b."*/
	srand((int)time(0));
	int i = 1 + rand() % 5;

	if (Ey - y < i && Ey + y > i
		&& Ex + x > i && Ex - x < i)
	{
		sighted_player = true;
	}

	if (sighted_player)
	{
		if (y < Ey)
		{
			enemy::Move(-1, 0);
		}
		else if (y > Ey)
		{
			enemy::Move(1, 0);
		}
		else if (x > Ex)
		{
			enemy::Move(0, 1);
		}
		else if (x < Ex)
		{
			enemy::Move(0, -1);
		}
	}

	return 0;
}

	
