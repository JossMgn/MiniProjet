#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Cellule.h"
#include <fstream>
using namespace std;

class Grille
{
	Cellule tabCellule_[10][10];


public:

	Grille();

	void setCellule(int i, int j, string couleur);
	Cellule getCellule(int i, int j) { return tabCellule_[i][j]; }
	void actualiserCellule(int i, int j);
	void sauver(fstream& os);
	void charger(fstream& is);
};