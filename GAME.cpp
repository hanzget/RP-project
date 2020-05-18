#include <cstdlib>
#include <iostream>
#include "Console.h"
#include "windows.h"
#include "enemy.h"
#include <sstream>
#include <MMSystem.h>




using namespace std;
bool ifRun = true;

enemy enemy1;
enemy enemy2;
enemy enemy3;
enemy enemy4;
enemy enemy5;

Console console;


int main()
{
	bool played = PlaySound(TEXT("song.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	
	while(ifRun)
	{
		
		//lila
		system("Color 0D");
		//sarga
		system("Color 0E");
		//kiiratasok
		stringstream ss;
		ss << count_coins;
		string items = "Coins: ";
		items += ss.str();

		stringstream ss1;
		ss1 << health;
		string health = "Health: ";
		health += ss1.str();

		system("cls");
		
		for (int i = 0;i < 22;i++)
		{
			cout << map[i] << endl;
		}

		for (int i = 0; i < 1; i++)
		{
			cout << items <<"   " << health << endl;
		}
		for (int i = 0; i < 1; i++)
		{
			cout << dialog << endl;
		}
		
		//enemy-k
		enemy1.Init(2, 4);
		enemy2.Init(5, 31);
		enemy3.Init(7, 8);
		enemy4.Init(14,23);
		enemy5.Init(19,36);
		
		
		//mozgas
		if (GetAsyncKeyState(VK_UP))
		{
			console.Move(-1, 0);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			console.Move(1, 0);
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			console.Move(0, 1);
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			console.Move(0, -1);
		}
		if (GetAsyncKeyState(VK_RETURN) && dialog_dis)
			dialog = "";
		


		if (gameover)
		{
			cout << ("GAME OVER YOU HAVE COLLECTED:") << count_coins << ("COINS");
			Sleep(3000);
			exit(1);
		}
		
		
		
	}
	
	cin.get();
    return 0;
}


