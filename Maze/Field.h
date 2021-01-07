#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
class Field
{
	const char bound = '#';
	const int full_size_ = 12; //with bounds
	const int actual_size_ = 10; //without bounds

private:
	void set_size()
	{
		field.resize(full_size_);
		for (int i = 0; i < field.size(); i++)
		{
			field[i].resize(full_size_);
		}
	}
	void set_walls()
	{
		srand(time(NULL));
		for (int i = 1; i < full_size_; i++)
		{
			for (int j = 1; j < full_size_; j++)
			{
				int k = rand() % 100;
				if (k > 60)
				{
					field[i][j] = bound;
				}
				else {
					field[i][j] = '.';
				}
			}
		}
		for (int i = 0; i < full_size_; i++)
		{
			field[i][0] = bound;
		}
		for (int i = 0; i < full_size_; i++)
		{
			field[i][11] = bound;
		}
		fill(field[0].begin(), field[0].end(), bound);
		fill(field[11].begin(), field[11].end(), bound);
	}
	void set_start_and_finish()
	{
		srand(time(nullptr));
		posFinishX = (rand() % actual_size_) + 1;
		posFinishY = (rand() % actual_size_) + 1;

		field[posFinishX][posFinishY] = 'F';

		posStartX = (rand() % actual_size_) + 1;
		posStartY = (rand() % actual_size_) + 1;

		field[posStartX][posStartY] = '@';
	}
public:
	vector<vector<char>> field;
	int posStartX;
	int posStartY;
	int posFinishX;
	int posFinishY;
	void init_vars()
	{
		set_size();
		set_walls();
		set_start_and_finish();
	}
	void print_field()
	{
		for (int i = 0; i < full_size_; i++)
		{
			for (int j = 0; j < full_size_; j++)
			{
				cout << field[i][j] << " ";
			}
			cout << endl;
		}
	}
};

