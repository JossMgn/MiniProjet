#include "Grille.h"

Grille::Grille()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			tabCellule_[i][j] = Cellule(i, j, "Blanc");
		}
	}
}

void Grille::setCellule(int i, int j, string couleur)
{
	tabCellule_[i][j].setCouleur(couleur);
}


string Grille::actualiserCellule(int x, int y)
{
	int EstVert=0;
	if (x > 0 && x < 10)
		if (y > 0 && y < 10)
			EstVert = (tabCellule_[x - 1][y - 1].getCouleur() == "Vert") + (tabCellule_[x - 1][y].getCouleur() == "Vert") + (tabCellule_[x - 1][y + 1].getCouleur() == "Vert")
			+ (tabCellule_[x][y - 1].getCouleur() == "Vert") + (tabCellule_[x][y + 1].getCouleur() == "Vert") + (tabCellule_[x + 1][y - 1].getCouleur() == "Vert") +
			(tabCellule_[x + 1][y].getCouleur() == "Vert") + (tabCellule_[x + 1][y + 1].getCouleur() == "Vert");

	//cout << "Cellule " << "(" << x << "/" << y << ")" << endl;
	//Y: ligne, X: colonne
	//int EstVert=0;
	//cout << "Dans la fonction acutaliserCouleur" << endl;
	/*if (x > 0 && x < 10 && y>0 && y < 10)
	{
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (tabCellule_[x + j][y + i].getCouleur() == "Vert" && i != 0 && j != 0)
				{
					EstVert ++;
					cout << "Cellule x " << x << " y " << y << " est verte" << endl;
					//cout << "Cellule (x+j/y+i): " << x+j << "/" << y+i << endl;
					//cout << "dans if EstVert = " << EstVert << endl;
				}
			}
		}
	}*/
	//cout << "Hors if EstVert = " << EstVert<<endl;
	// Si on est sur un côté
	/*else if (y == 0 && x > 0 && x < 10)
	{
		for (int i = 0; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (tabCellule_[x + j][y + i].getCouleur() == "Vert" && i != 0 && j != 0)
					EstVert++;
			}
		}
		for (int j = -1; j < 2; j++)
			if (tabCellule_[x + j][9].getCouleur() == "Vert" && j != 0)
				EstVert++;
	}
	else if (y == 9 && x > 0 && x < 10)
	{
		for (int i = -1; i < 1; i++) {
			for (int j = -1; j < 2; j++) {
				if (tabCellule_[x + j][y + i].getCouleur() == "Vert" && i != 0 && j != 0)
					EstVert++;
			}
		}
		for (int j = -1; j < 2; j++)
			if (tabCellule_[x + j][0].getCouleur() == "Vert" && j != 0)
				EstVert++;
	}
	else if (x == 0 && y > 0 && y < 10)
	{
		for (int i = -1; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (tabCellule_[x + j][y + i].getCouleur() == "Vert" && i != 0 && j != 0)
					EstVert++;
			}
		}
		for (int i = -1; i < 2; i++)
			if (tabCellule_[9][y + i].getCouleur() == "Vert" && i != 0)
				EstVert++;
	}
	else if (x == 9 && y > 0 && y < 10)
	{
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 1; j++) {
				if (tabCellule_[x + j][y + i].getCouleur() == "Vert" && i != 0 && j != 0)
					EstVert++;
			}
		}
		for (int i = -1; i < 2; i++)
			if (tabCellule_[0][y + i].getCouleur() == "Vert" && i != 0)
				EstVert++;
	}
	// Si on est sur une extrêmité
	else if (x == 0 && y == 0)
	{
		if (tabCellule_[9][9].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[0][9].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[1][9].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[9][0].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[1][0].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[9][1].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[0][1].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[1][1].getCouleur() == "Vert")
			EstVert++;
	}
	else if (x == 9 && y == 0)
	{
		if (tabCellule_[8][9].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[9][9].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[0][9].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[8][0].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[0][0].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[8][1].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[9][1].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[0][1].getCouleur() == "Vert")
			EstVert++;
	}
	else if (x == 0 && y == 9)
	{
		if (tabCellule_[9][8].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[0][8].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[1][8].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[9][9].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[1][9].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[9][0].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[0][0].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[1][0].getCouleur() == "Vert")
			EstVert++;
	}
	else if (x == 9 && y == 9)
	{
	if (tabCellule_[8][8].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[9][8].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[0][8].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[8][9].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[0][9].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[8][0].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[9][0].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[0][0].getCouleur() == "Vert")
		EstVert++;
	}*/
	//int f = 1;
	//cout << "EstVert" << EstVert << endl;
	if (EstVert == 3) {
		return "Vert";
		//f=1+f;
	}
	else if (EstVert == 2 && tabCellule_[x][y].getCouleur() == "Rouge")
		return "Blanc";
	else if (EstVert == 2 && tabCellule_[x][y].getCouleur() == "Blanc")
		return "Blanc";
	else if (EstVert < 2 || EstVert >3) { //&& tabCellule_[x][y].getCouleur() == "Vert")
		if (tabCellule_[x][y].getCouleur() == "Vert")
			return "Rouge";
	}


	//cout << "Couleur: " << Couleur << endl;
	//cout <<"f:"<< f << endl;
	//return Couleur;
}
