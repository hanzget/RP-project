#ifndef ENEMY_H
#define ENEMY_H

#pragma once
class enemy
{
public:
	enemy();
	~enemy();
	void Move(int ver, int hor);
	int Init(int ver, int hor);

	int Ex = 0;
	int Ey = 0;
	char enemy_symbol = 'O';

	bool location_set = false;
	bool sighted_player = false;
};

extern int Ex;
extern int Ey;

#endif
