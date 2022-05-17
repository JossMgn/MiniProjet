#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Cellule.h"
using namespace std;

class Grille
{
	vector<vector<Cellule>> tabCellule_[10][10];

public:

	Grille();

	void setCellule(int i, int j, string couleur);
	void actualiserCellule(int i, int j) const;
};