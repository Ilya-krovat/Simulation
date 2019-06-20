#pragma once

#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <string>

const int HEIGHT_MAP = 40;	//высота карты 
const int WIDTN_MAP = 80;	//ширина карты

sf::String Tilemap[HEIGHT_MAP] =
{
	"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"0                                                                              0",
	"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
};

void updateNature()
{
	int nh = 0;
	int np = 0;
	for (int i = 1; i < HEIGHT_MAP - 1; ++i)
		for (int j = 1; j < WIDTN_MAP - 1; ++j)
			if (Tilemap[i][j] == 'h')
				nh++;
			else 
				if (Tilemap[i][j] == 'p')
				{
					for (int n_x = -1; n_x < 2; n_x++)
						for (int n_y = -1; n_y < 2; n_y++)
							if (Tilemap[n_x + i][n_y + j] == ' ')
								Tilemap[n_x + i][n_y + j] = 'l';
					np++;
				}
	int n_x;
	int n_y;
	while (np < 0)
	{
		while (true)
		{
			int f = 0;
			n_x = rand() % 38 + 1;
			n_y = rand() % 78 + 1;
			if (Tilemap[n_x][n_y] == ' ')
			{
				for (int i = -1; i < 2; i++)
					for (int j = -1; j < 2; j++)
						if (Tilemap[n_x + i][n_y + j] != 'b')
							f++;
				if (f == 9)
				{
					Tilemap[n_x][n_y] = 'p';
					np++;
					break;
				}
			}
		}
	}
	while (nh < 250)
	{
		while (true)
		{
			n_x = rand() % 38 + 1;
			n_y = rand() % 78 + 1;
			if (Tilemap[n_x][n_y] == ' ')
			{
				bool a = true;
				for (int i = -1; i < 2; i++)
					for (int j = -1; j < 2; j++)
						if (Tilemap[n_x + i][n_y + j] == 'h')
							a = false;
				if (a)
				{
					Tilemap[n_x][n_y] = 'h';
					nh++;
					break;
				}
			}
		}
	}
}