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
	void operator=(const Grille& g);

	void setCellule(int i, int j, string couleur);
	Cellule getCellule(int i, int j) { return tabCellule_[i][j]; }
	string actualiserCellule(int  x, int y);
	void sauverGrille(ofstream& os) const;
	void chargerGrille(ifstream& is);
};