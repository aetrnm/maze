#include <iostream>
#include<conio.h>
#include<vector>
#include <cstdlib>
#include "Field.h"

using namespace std;

bool game_in_progress = true;

const int full_size = 12; //with bounds

const int size = 10;

vector<vector<char>> field;

int pos_x;
int pos_y;

int finish_x;
int finish_y;

bool inBounds(char ch)
{
	switch (ch)
	{
	case 119: //top
		return (pos_x > 1 && field[pos_x-1][pos_y] != '#') ? true : false;
	case 97: //left
		return (pos_y > 1 && field[pos_x][pos_y-1] != '#') ? true : false;
	case 115: //down
		return (pos_x < 10 && field[pos_x + 1][pos_y] != '#') ? true : false;
	case 100: //right
		return (pos_y < 10 && field[pos_x][pos_y + 1] != '#') ? true : false;
	}
}

void Move(char ch)
{
	field[pos_x][pos_y] = '.';
	switch (ch)
	{
	case 119: //top
		pos_x -= 1;
		break;
	case 97: //left
		pos_y -= 1;
		break;
	case 115: //down
		pos_x += 1;
		break;
	case 100: //right
		pos_y += 1;
		break;
	}
	field[pos_x][pos_y] = '@';
}

void init_vars()
{
	Field f;
	f.init_vars();
	
	field = f.field;	
	pos_x = f.posStartX;
	pos_y = f.posStartY;
	finish_x = f.posFinishX;
	finish_y = f.posFinishY;
	f.print_field();
}

void Draw()
{
	for (int i = 0; i < full_size; i++)
	{
		for (int j = 0; j < full_size; j++)
		{
			cout << field[i][j] << " ";
		}
		cout << endl;
	}
}

void checkStatus()
{
	if(pos_x == finish_x && pos_y == finish_y)
	{
		game_in_progress = false;
		cout << endl << "YOU HAVE WON!" << endl;
	}
}

void Game()
{
	init_vars();
	while(game_in_progress)
	{
		_kbhit();
		auto ch = _getch();
		if(inBounds(ch))
		{
			system("CLS");
			Move(ch);
			Draw();
			checkStatus();
		}
	}
}

int main()
{
    Game();
}
