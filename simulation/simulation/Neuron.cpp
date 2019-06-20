#include "Neuron.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

Neuron::Neuron()
{
}

Neuron::~Neuron()
{
}

void Neuron::findWeight(int foodmap[9][9],int poisonmap[9][9],int wallmap[9][9])
{
	int food = foodWeight(foodmap);
	int poison = poisonWeight(poisonmap);
	int wall = wallWeight(wallmap);
	weight = food + poison + wall;
}

int Neuron::foodWeight(int foodmap[9][9])
{
	int value = 0;
	for (int i = 0; i <= 8; i++)
		for (int j = 0; j <= 8; j++)
		{
			value += foodmap[i][j] * foodExpirience[i][j];
		}
	return value;
}

int Neuron::poisonWeight(int poisonmap[9][9])
{
	int value = 0;
	for (int i = 0; i <= 8; i++)
		for (int j = 0; j <= 8; j++)
		{
			value += poisonmap[i][j] * poisonExpirience[i][j];
		}
	return value;
}

int Neuron::wallWeight(int wallmap[9][9])
{
	int value = 0;
	for (int i = 0; i <= 8; i++)
		for (int j = 0; j <= 8; j++)
		{
			value += wallmap[i][j] * wallExpirience[i][j];
		}
	return value;
}

void Neuron::SaveExp(int number_of_neuron, int number_of_bug, int number_of_save)
{
	std::string file = "Saves/Save" + std::to_string(number_of_save);
	file += "/Bug_" + std::to_string(number_of_bug);
	file += "/Neuron_" + std::to_string(number_of_neuron);
	file += ".txt";
	std::ofstream fileOut;
	fileOut.open(file,std::ios::out);
	// порядок записи: food, poison, wall
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			fileOut << foodExpirience[i][j];
			fileOut << std::endl;
		}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			fileOut << poisonExpirience[i][j];
			fileOut << std::endl;
		}
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			fileOut << wallExpirience[i][j];
			fileOut << std::endl;
		}
	fileOut.close();
}

void Neuron::LoadExp(int number_of_neuron, int number_of_bug, int number_of_save)
{
	std::string file = "Saves/Save" + std::to_string(number_of_save);
	file += "/Bug_" + std::to_string(number_of_bug);
	file += "/Neuron_" + std::to_string(number_of_neuron);
	file += ".txt";
	std::ifstream inf;
	inf.open(file);

	if (!inf)
	{
		for (int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
			{
				foodExpirience[i][j] = 0;
				poisonExpirience[i][j] = 0;
				wallExpirience[i][j] = 0;
			}
	}
	if(inf)
	{
		int counter = 0;
		int i = 0;
		int j = 0;
		std::string number;
		while (!inf.eof())
		{
			inf >> number;
			int value = std::stoi(number);
			if (counter < 81)
				foodExpirience[i][j] = value;
			else if (counter < 162)
				poisonExpirience[i][j] = value;
			else if (counter < 243)
				wallExpirience[i][j] = value;
			counter++;
			if (i == 8 && j == 8)
			{
				i = 0;
				j = 0;
			}
			else if (j == 8)
			{
				j = 0;
				i++;
			}
			else
				j++;
		}
	}
	inf.close();
}

void Neuron::mutate()
{
	int count = 0;
	while (count < 60)
	{
		int x = rand() % 9;
		int y = rand() % 9;/*
		foodExpirience[x][y] = (rand() % 200 - 100);

		x = rand() % 9;
		y = rand() % 9;*/
		poisonExpirience[x][y] = (rand() % 200 - 100);
/*
		x = rand() % 9;
		y = rand() % 9;
		wallExpirience[x][y] = (rand() % 200 - 100);*/
		count++;
	}
}