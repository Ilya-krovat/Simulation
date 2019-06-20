#pragma once
class Neuron
{
public:
	Neuron();
	int weight;

	void LoadExp(int number_of_neuron, int number_of_bug, int number_of_save);
	void SaveExp(int number_of_neuron, int number_of_bug, int number_of_save);
	void mutate();
	void findWeight(int foodmap[9][9],int poisonmap[9][9],int wallmap[9][9]);
	~Neuron();
private:
	int foodExpirience[9][9];
	int poisonExpirience[9][9];
	int wallExpirience[9][9];

	int foodWeight(int foodmap[9][9]);
	int poisonWeight(int poisonmap[9][9]);
	int wallWeight(int wallmap[9][9]);
};