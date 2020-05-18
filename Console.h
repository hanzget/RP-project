#ifndef CONSOLE_H
#define CONSOLE_H


#include <string>
using namespace std;

class Console
{
public:
	Console();
	~Console();
	void Move(int ver, int hor);//ver-> vertikalis,hor-> horizontalis
	

};

extern char map[22][100];
extern int x;
extern int y;
extern int count_coins;
extern int health;
extern string dialog;
extern bool dialog_dis;
extern bool gameover;
extern bool ifKey2;

#endif

