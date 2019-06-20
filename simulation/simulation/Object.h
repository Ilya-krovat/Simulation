#pragma once

#include <SFML\Graphics.HPP>
#include "Neuron.h"

using namespace sf;

class Object
{
public:
	bool isAlave();
	int x, y = 0;
	int health;
	Image image;
	Texture texture;
	Sprite sprite;

	void act(sf::String Tilemap[40]);
	void move(int course,sf::String Tilemap[40]);
	void mutation();
	void saveData(int number_of_bug, int number_of_save);
	void loadData(int number_of_bug, int number_of_save);

	Object();
	Object(int x, int y,sf::String Tilemap[40]);
	~Object();

private:
	int healmap[9][9];
	int wallmap[9][9];
	int poisonmap[9][9];

	Neuron neuron[8];
	void search(sf::String Tilemap[40]);
	int getSoution();
};