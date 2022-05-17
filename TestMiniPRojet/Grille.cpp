#include "Grille.h"

Grille::Grille()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			tabCellule_[i][j] = Cellule(i, j, "White");
		}
	}
}

void Grille::setCellule(int i, int j, string couleur)
{
	tabCellule_[i][j].setCouleur(couleur);
}

void Grille::actualiserCellule(int i, int j) const
