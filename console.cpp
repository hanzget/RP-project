
#include "Console.h"
#include "ctime"
using namespace std;


int x = 1;
int y = 1;

int count_coins = 0;
int health = 100;

bool ifKey = false;
bool ifKey2 = false;//ezt meg kell venni
bool ifKey3 = false;
bool dialog_dis = false;
bool treasure = false;
bool gameover = false;

string dialog = "";

char map[22][100] =
  //    0123456789012345678901234567890123456789012345
{ /*0*/ "##############################################                                ",
  /*1*/ "#&  ***         O   O   O  +O    O  ***      #        ~BIZARRE MAZE~          ",
  /*2*/ "#OOO OOOO OOOOO   O   O     O! O  O  OOOOOO  # -AVOID THE ENEMY STAND USERS   ",
  /*3*/ "#   *   O O    OOOO   OOOOOOOOOOO  O  O + O  # -GET ALL KEYS                  ",
  /*4*/ "#  ***  O O***    O O    *     X          O  # -GET TO THE GOLDEN ARROW       ",
  /*5*/ "#  ***  O O    O  O OOOOOOO OOOOOOOOOOOOOOO  # -CONTROLS:W,A,S,D,RETURN       ",
  /*6*/ "#   *   O OOO OO  OXO         ****           #################################",
  /*7*/ "#             XO  OOOOOOOOOOOOOOOOOOOOOOOOOOO#                +              #",
  /*8*/ "#OOO_OOOOOOOOOOO                       ***   #               +++             #",
  /*9*/ "#   **                                 ***   #              +++++            #",
  /*0*/ "######################_#######################              +++++            #",
  /*1*/ "###################### #######################             ++++++++          #",
  /*2*/ "#*                                       *   #            ++  +   ++         #",
  /*3*/ "#        *                                   #                +              #",
  /*4*/ "#                          *   #       *     #                +              #",
  /*5*/ "#         #    #    X          #             #                +              #",
  /*6*/ "#         #   #                #      X      #                +              #",
  /*7*/ "#         ####                               #                               #",
  /*8*/ "#OO-O                                      ###                               #",
  /*9*/ "#   O       *                       #####    #                               #",
  /*0*/ "#  $O               *                 *  #  @()                              #",
  /*1*/ "##############################################################################",
	//   0123456789012345678901234567890123456789012345
};
Console:: Console()
{

}

Console:: ~Console()
{
}

void Console::Move(int ver,int hor)
{
	
		int y2 = y + ver;
		int x2 = x + hor;

		if (map[y2][x2] == '+')
			treasure = true;

		if (map[y2][x2] == 'X')
			health += 10;

		if (health <= 0)
			gameover = true;

		if (map[y2][x2] == '!')
		{
			ifKey = true;
			dialog = "YOU GOT THE FIRST KEY!";
			dialog_dis = true;
		}
		if (map[y2][x2] == '@')
		{
			ifKey3 = true;
			dialog = "YOU GOT THE SECOND KEY!";
			dialog_dis = true;
		}
		if(map[y2][x2] == '$' && count_coins >= 40)
		{
			ifKey2 = true;
			count_coins -= 40;
			
			dialog = "YOU BOUGHT THE FINAL KEY";
			dialog_dis = true;
		}
		if (map[y2][x2] == '$' && count_coins <= 40)
		{
			
			dialog = "YOU DON'T HAVE ENOUGH MONEY";
			dialog_dis = true;
		}

		if (map[y2][x2] == '*')
			count_coins++;

		if (map[y][x2] == ' '
			|| map[y][x2] == '*'
			|| map[y][x2] == '+'
			|| map[y][x2] == '!'
			|| map[y][x2] == '@'
			|| map[y][x2] == '$'
			|| map[y][x2] == 'X'
			|| (map[y][x2] == '_'
				&& ifKey)
			|| (map[y][x2] == '('
				&& ifKey2)
			|| (map[y][x2] == ')'
				&& ifKey2)
			|| (map[y][x2] == '-'
				&& ifKey3))
		{
			map[y][x] = ' ';
			x += hor;
			map[y][x] = '&';
		}
		if (map[y2][x] == ' '
			|| map[y2][x] == '*'
			|| map[y2][x] == '+'
			|| map[y2][x] == '!'
			|| map[y2][x] == '@'
			//|| map[y2][x] == '$'
			|| map[y2][x] == 'X'
			|| (map[y2][x] == '_'
				&& ifKey)
			|| (map[y2][x] == '('
				&& ifKey2)
			|| (map[y2][x] == ')'
				&& ifKey2)
			|| (map[y2][x] == '-'
				&& ifKey3))
		{
			map[y][x] = ' ';
			y += ver;
			map[y][x] = '&';
		}

		//kincses lada
		
		if (treasure)
		{
			srand((int)time(0));
			int i = 1 + rand() % 5;
			/*map[y2 - 1][x2 - 1] = '*';
			map[y2 - 1][x2] = '*';
			map[y2 - 1][x2 + 1] = '*';
			map[y2][x2 - 1] = '*';
			map[y2][x2 + 1] = '*';
			map[y2 + 1][x2 - 1] = '*';
			map[y2 + 1][x2] = '*';
			map[y2 + 1][x2 + 1] = '*';*/

			count_coins += i;
			dialog = "YOU OPRNED A TREASURE CHEST!";
			dialog_dis = true;
			treasure = false;

		}
		
		
		
		
	}