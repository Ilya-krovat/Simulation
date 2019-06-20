#include "Object.h"
#include "MyFunctions.h"


Object::Object()
{
};

Object::~Object()
{
};

Object::Object(int _x, int _y,sf::String Tilemap[40])
{
	health = 99;
	x = _x;
	y = _y;
	Tilemap[y][x] = 'b';
	sprite.setPosition(x * 32, y * 32);
}

void Object::search(sf::String Tilemap[40])
{
	for(int i=0;i<=8;i++)
		for (int j = 0; j <= 8; j++)
		{
			wallmap[i][j] = 0;
			poisonmap[i][j] = 0;
			healmap[i][j] = 0;
		}
	int left, right, up, down;
	left = haveSdvig0(x - 4);
	up = haveSdvig0(y - 4);
	right = haveSdvig79(x + 4);
	down = haveSdvig39(y + 4);
// i - y   j - x    a[i][j]
	for (int i = up; i < 8+down;i++)
		for (int j = left; j <8+ right; j++)
		{
			if (Tilemap[y - 4 + i][x - 4 + j] == '0' || Tilemap[y - 4 + i][x - 4 + j] == 'b')
				wallmap[i][j] = 1;
			if (Tilemap[y - 4 + i][x - 4 + j] == 'h')
				healmap[i][j] = 1;
			if (Tilemap[y - 4 + i][x - 4 + j] == 'p')
				poisonmap[i][j] = 1;
		}
}

void Object::move(int course,sf::String Tilemap[40])
{
	switch (course)
	{
		case 0:
		{
			if (Tilemap[y-1][x-1] == ' ')
			{
				Tilemap[y-1][x-1] = 'b';
				Tilemap[y][x]=' ';
				x--;
				y--;
				health -= 1;
			}
			else
				if (Tilemap[y - 1][x - 1] == '0' || Tilemap[y - 1][x - 1] == 'b')
					health = Max(health - 2, 0);
			else
			if (Tilemap[y-1][x-1] == 'h')
			{
				Tilemap[y-1][x-1] = 'b';
				Tilemap[y][x] = ' ';
				x--;
				y--;
				health += 20;
			}else
			if (Tilemap[y-1][x-1] == 'p'|| Tilemap[y-1][x-1] == 'l')
			{
				Tilemap[y-1][x-1] = 'b';
				Tilemap[y][x]=' ';
				x--;
				y--;
				health = 0;
			}
			break;
		}
		case 1:
		{
			if (Tilemap[y-1][x] == ' ')
			{
				Tilemap[y-1][x]='b';
				Tilemap[y][x] = ' ';
				y--;
				health -= 1;
			}else 
			if (Tilemap[y-1][x] == '0'|| Tilemap[y-1][x] == 'b')
				health = Max(health - 2, 0);
			else
			if (Tilemap[y-1][x] == 'h')
			{
				Tilemap[y-1][x] = 'b';
				Tilemap[y][x] = ' ';
				y--;
				health += 20;
			}else
			if (Tilemap[y-1][x] == 'p'|| Tilemap[y-1][x] == 'l')
			{
				Tilemap[y-1][x] = 'b';
				Tilemap[y][x] = ' ';
				y--;
				health = 0;
			}
			break;
		}
		case 2:
		{
			if (Tilemap[y-1][x+1] == ' ')
			{
				Tilemap[y-1][x+1]='b';
				Tilemap[y][x] = ' ';
				y--;
				x++;
				health--;
			}else
			if (Tilemap[y-1][x+1] == '0'|| Tilemap[y-1][x+1] == 'b')
				health = Max(health - 2, 0);
			else
			if (Tilemap[y-1][x+1] == 'h')
			{
				Tilemap[y-1][x+1] = 'b';
				Tilemap[y][x] = ' ';
				y--;
				x++;
				health +=20;
			}else
			if (Tilemap[y-1][x+1] == 'p'|| Tilemap[y-1][x+1] == 'l')
			{
				Tilemap[y-1][x+1] = 'b';
				Tilemap[y][x] = ' ';
				y--;
				x++;
				health = 0;
			}
			break;
		}
		case 3:
		{
			if (Tilemap[y][x+1] == ' ')
			{
				Tilemap[y][x+1] = 'b';
				Tilemap[y][x] = ' ';
				x++;
				health --;
			}else
			if (Tilemap[y][x+1] == '0'|| Tilemap[y][x+1] == 'b')
				health = Max(health - 2, 0);
			else
			if (Tilemap[y][x+1] == 'h')
			{
				Tilemap[y][x+1] = 'b';
				Tilemap[y][x] = ' ';
				x++;
				health +=20;
			}
			if (Tilemap[y][x+1] == 'p'|| Tilemap[y][x+1] == 'l')
			{
				Tilemap[y][x+1] = 'b';
				Tilemap[y][x] = ' ';
				x++;
				health = 0;
			}
			break;
		}
		case 4:
		{
			if (Tilemap[y+1][x+1] == ' ')
			{
				Tilemap[y+1][x+1] = 'b';
				Tilemap[y][x] = ' ';
				y++;
				x++;
				health -= 1;
			}else
			if (Tilemap[y+1][x+1] == '0'|| Tilemap[y+1][x+1] == 'b')
				health = Max(health - 2, 0);
			else
			if (Tilemap[y+1][x+1] == 'h')
			{
				Tilemap[y+1][x+1] = 'b';
				Tilemap[y][x] = ' ';
				y++;
				x++;
				health += 20;
			}
			if (Tilemap[y+1][x+1] == 'p'|| Tilemap[y+1][x+1] == 'l')
			{
				Tilemap[y+1][x+1] = 'b';
				Tilemap[y][x] = ' ';
				y++;
				x++;
				health = 0;
			}
			break;
		}
		case 5:
		{
			if (Tilemap[y+1][x] == ' ')
			{
				Tilemap[y+1][x] = 'b';
				Tilemap[y][x] = ' ';
				y++;
				health --;
			}else
			if (Tilemap[y+1][x] == '0'|| Tilemap[y+1][x] == 'b')
				health = Max(health - 2, 0);
			else
			if (Tilemap[y+1][x] == 'h')
			{
				Tilemap[y+1][x] = 'b';
				Tilemap[y][x] = ' ';
				y++;
				health += 20;
			}else
			if (Tilemap[y+1][x] == 'p'|| Tilemap[y+1][x] == 'l')
			{
				Tilemap[y+1][x] = 'b';
				Tilemap[y][x] = ' ';
				y++;
				health = 0;
			}
			break;
		}
		case 6:
		{
			if (Tilemap[y+1][x-1] == ' ')
			{
				Tilemap[y+1][x-1] = 'b';
				Tilemap[y][x] = ' ';
				y++;
				x--;
				health -= 1;
			}else
			if (Tilemap[y+1][x-1] == '0'|| Tilemap[y+1][x-1] == 'b')
				health = Max(health - 2, 0);
			else
			if (Tilemap[y+1][x-1] == 'h')
			{
				Tilemap[y+1][x-1] = 'b';
				Tilemap[y][x] = ' ';
				y++;
				x--;
				health += 20;
			}
			if (Tilemap[y+1][x-1] == 'p'|| Tilemap[y+1][x-1] == 'l')
			{
				Tilemap[y+1][x-1] = 'b';
				Tilemap[y][x] = ' ';
				y++;
				x--;
				health = 0;
			}
			break;
		}
		case 7:
		{
			if (Tilemap[y][x-1] == ' ')
			{
				Tilemap[y][x-1] = 'b';
				Tilemap[y][x] = ' ';
				x--;
				health--;
			}else
			if (Tilemap[y][x-1] == '0'|| Tilemap[y][x-1] == 'b')
				health = Max(health - 2, 0);
			else
			if (Tilemap[y][x-1] == 'h')
			{
				Tilemap[y][x-1] = 'b';
				Tilemap[y][x] = ' ';
				x--;
				health += 20;
			}
			if (Tilemap[y][x-1] == 'p'|| Tilemap[y][x-1] == 'l')
			{
				Tilemap[y][x-1] = 'b';
				Tilemap[y][x] = ' ';
				x--;
				health = 0;
			}
			break;
		}
	}
}

int Object::getSoution()
{
	int solution = 0;
	int maxWeight = -1000000000;
	for (int i = 0; i < 8; i++)
	{
		neuron[i].findWeight(healmap, poisonmap, wallmap);
		if (neuron[i].weight > maxWeight)
		{
			maxWeight = neuron[i].weight;
			solution = i;
		}
	}
	return solution;
}

void Object::act(sf::String Tilemap[40])
{
	search(Tilemap);

	int course = getSoution();

	move(course, Tilemap);

	sprite.setPosition(x * 32,y * 32);
}

bool Object::isAlave()
{
	return health > 0;
}

void Object::mutation()
{
	for (int i = 0; i < 8; i++)
		neuron[i].mutate();
}

void Object::saveData(int number_of_bug, int number_of_save)
{
	for (int i = 0; i < 8; i++)
	{
		neuron[i].SaveExp(i, number_of_bug, number_of_save);
	}
}

void Object::loadData(int number_of_bug, int number_of_save)
{
	for (int i = 0; i < 8; i++)
	{
		neuron[i].LoadExp(i, number_of_bug, number_of_save);
	}
}