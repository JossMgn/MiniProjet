#include "Grille.h"

Grille::Grille(string nom):nom_(nom)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tabCellule_[i][j] = Cellule(i, j, "Blanc");
		}
	}
}

void Grille::operator=(const Grille& g)
{
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tabCellule_[i][j] = g.tabCellule_[i][j];
		}
	}
}

void Grille::setCellule(int i, int j, string couleur)
{
	tabCellule_[i][j].setCouleur(couleur);
}//Permet d'initialiser la couleur de la cellule (i/j)

void Grille::sauverGrille(ofstream& os) const {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			tabCellule_[i][j].sauver(os);
}//Permet la sauvegarde de grille

void Grille::chargerGrille(ifstream& is) {

	 while (!is.eof()) 
	 {
		 for (int i = 0; i < 10; i++) 
			 for (int j = 0; j < 10; j++) 
				 tabCellule_[i][j].charger(is);
	 }
}//Permet de charger une grille existente

string Grille::actualiserCellule(int x, int y)
{
	int EstVert = 0;
	if (x > 0 && x < 9 && y>0 && y < 9)
		EstVert = (tabCellule_[x - 1][y - 1].getCouleur() == "Vert" || tabCellule_[x - 1][y - 1].getCouleur() == "Noir") + (tabCellule_[x - 1][y].getCouleur() == "Vert" || tabCellule_[x - 1][y].getCouleur() == "Noir") 
		+ (tabCellule_[x - 1][y + 1].getCouleur() == "Vert" || tabCellule_[x - 1][y + 1].getCouleur() == "Noir")
		+ (tabCellule_[x][y - 1].getCouleur() == "Vert" || tabCellule_[x][y - 1].getCouleur() == "Noir") + (tabCellule_[x][y + 1].getCouleur() == "Vert" || tabCellule_[x][y + 1].getCouleur() == "Noir")
		+ (tabCellule_[x + 1][y - 1].getCouleur() == "Vert" || tabCellule_[x + 1][y - 1].getCouleur() == "Noir") +
		(tabCellule_[x + 1][y].getCouleur() == "Vert" || tabCellule_[x + 1][y].getCouleur() == "Noir") + (tabCellule_[x + 1][y + 1].getCouleur() == "Vert" || tabCellule_[x + 1][y + 1].getCouleur() == "Noir");

	else if (x == 0)
	{
		if (y == 0)
			EstVert = (tabCellule_[9][9].getCouleur() == "Vert" || tabCellule_[9][9].getCouleur() == "Noir") + (tabCellule_[9][0].getCouleur() == "Vert" || tabCellule_[9][0].getCouleur() == "Noir")
			+ (tabCellule_[9][1].getCouleur() == "Vert" || tabCellule_[9][1].getCouleur() == "Noir")
			+ (tabCellule_[0][9].getCouleur() == "Vert" || tabCellule_[0][9].getCouleur() == "Noir") + (tabCellule_[0][1].getCouleur() == "Vert"|| tabCellule_[0][1].getCouleur() == "Noir") 
			+ (tabCellule_[1][9].getCouleur() == "Vert" || tabCellule_[1][9].getCouleur() == "Noir") +
			(tabCellule_[1][0].getCouleur() == "Vert" || tabCellule_[1][0].getCouleur() == "Noir") + (tabCellule_[1][1].getCouleur() == "Vert" || tabCellule_[1][1].getCouleur() == "Noir");

		else if (y == 9)
			EstVert = (tabCellule_[9][8].getCouleur() == "Vert" || tabCellule_[9][8].getCouleur() == "Noir") + (tabCellule_[9][9].getCouleur() == "Vert" || tabCellule_[9][9].getCouleur() == "Noir") 
			+ (tabCellule_[9][0].getCouleur() == "Vert" || tabCellule_[9][0].getCouleur() == "Noir")
			+ (tabCellule_[0][8].getCouleur() == "Vert" || tabCellule_[0][8].getCouleur() == "Noir") + (tabCellule_[0][0].getCouleur() == "Vert" || tabCellule_[0][0].getCouleur() == "Noir") 
			+ (tabCellule_[1][8].getCouleur() == "Vert" || tabCellule_[1][8].getCouleur() == "Noir") +
			(tabCellule_[1][9].getCouleur() == "Vert" || tabCellule_[1][9].getCouleur() == "Noir") + (tabCellule_[1][0].getCouleur() == "Vert" || tabCellule_[1][0].getCouleur() == "Noir");

		else
			EstVert = (tabCellule_[9][y - 1].getCouleur() == "Vert" || tabCellule_[9][y - 1].getCouleur() == "Noir") + (tabCellule_[9][y].getCouleur() == "Vert" || tabCellule_[9][y].getCouleur() == "Noir")
			+ (tabCellule_[9][y + 1].getCouleur() == "Vert" || tabCellule_[9][y + 1].getCouleur() == "Noir")
			+ (tabCellule_[x][y - 1].getCouleur() == "Vert" || tabCellule_[x][y - 1].getCouleur() == "Noir") + (tabCellule_[x][y + 1].getCouleur() == "Vert" || tabCellule_[x][y + 1].getCouleur() == "Noir") 
			+ (tabCellule_[x + 1][y - 1].getCouleur() == "Vert" || tabCellule_[x + 1][y - 1].getCouleur() == "Noir") +
			(tabCellule_[x + 1][y].getCouleur() == "Vert" || tabCellule_[x + 1][y].getCouleur() == "Noir") + (tabCellule_[x + 1][y + 1].getCouleur() == "Vert" || tabCellule_[x + 1][y + 1].getCouleur() == "Noir");
	}

	else if (x == 9)
	{
		if (y == 0)
			EstVert = (tabCellule_[8][9].getCouleur() == "Vert" || tabCellule_[8][9].getCouleur() == "Noir") + (tabCellule_[8][0].getCouleur() == "Vert" || tabCellule_[8][0].getCouleur() == "Noir") 
			+ (tabCellule_[8][1].getCouleur() == "Vert" || tabCellule_[8][1].getCouleur() == "Noir")
			+ (tabCellule_[9][9].getCouleur() == "Vert" || tabCellule_[9][9].getCouleur() == "Noir") + (tabCellule_[9][1].getCouleur() == "Vert" || tabCellule_[9][1].getCouleur() == "Noir") + (tabCellule_[0][9].getCouleur() == "Vert" || tabCellule_[0][9].getCouleur() == "Noir")
			+(tabCellule_[0][0].getCouleur() == "Vert" || tabCellule_[0][0].getCouleur() == "Noir") + (tabCellule_[0][1].getCouleur() == "Vert" || tabCellule_[0][1].getCouleur() == "Noir");

		else if (y == 9)
			EstVert = (tabCellule_[8][8].getCouleur() == "Vert" || tabCellule_[8][8].getCouleur() == "Noir") + (tabCellule_[8][9].getCouleur() == "Vert" ||tabCellule_[8][9].getCouleur() == "Noir") 
			+ (tabCellule_[8][0].getCouleur() == "Vert" || tabCellule_[8][0].getCouleur() == "Noir")
			+ (tabCellule_[9][8].getCouleur() == "Vert" || tabCellule_[9][8].getCouleur() == "Noir") + (tabCellule_[9][0].getCouleur() == "Vert" || tabCellule_[9][0].getCouleur() == "Noir") 
			+ (tabCellule_[0][8].getCouleur() == "Vert" || tabCellule_[0][8].getCouleur() == "Noir") +
			(tabCellule_[0][9].getCouleur() == "Vert" || tabCellule_[0][9].getCouleur() == "Noir") + (tabCellule_[0][0].getCouleur() == "Vert" || tabCellule_[0][0].getCouleur() == "Noir");

		else
			EstVert = (tabCellule_[x - 1][y - 1].getCouleur() == "Vert" || tabCellule_[x - 1][y - 1].getCouleur() == "Noir") + (tabCellule_[x - 1][y].getCouleur() == "Vert" || tabCellule_[x - 1][y].getCouleur() == "Noir") 
			+ (tabCellule_[x - 1][y + 1].getCouleur() == "Vert" || tabCellule_[x - 1][y + 1].getCouleur() == "Noir")
			+ (tabCellule_[x][y - 1].getCouleur() == "Vert" || tabCellule_[x][y - 1].getCouleur() == "Noir") + (tabCellule_[x][y + 1].getCouleur() == "Vert" || tabCellule_[x][y + 1].getCouleur() == "Noir")
			+ (tabCellule_[0][y - 1].getCouleur() == "Vert" || tabCellule_[0][y - 1].getCouleur() == "Noir") 
			+(tabCellule_[0][y].getCouleur() == "Vert" || tabCellule_[0][y].getCouleur() == "Noir") + (tabCellule_[0][y + 1].getCouleur() == "Vert" || tabCellule_[0][y + 1].getCouleur() == "Noir");
	}

	else if (x > 0 && x < 9 && y == 0)
		EstVert = (tabCellule_[x - 1][9].getCouleur() == "Vert" || tabCellule_[x - 1][9].getCouleur() == "Noir") + (tabCellule_[x - 1][y].getCouleur() == "Vert" || tabCellule_[x - 1][y].getCouleur() == "Noir") 
		+ (tabCellule_[x - 1][y + 1].getCouleur() == "Vert" || tabCellule_[x - 1][y + 1].getCouleur() == "Noir")
		+ (tabCellule_[x][9].getCouleur() == "Vert" || tabCellule_[x][9].getCouleur() == "Noir") + (tabCellule_[x][y + 1].getCouleur() == "Vert" || tabCellule_[x][y + 1].getCouleur() == "Noir") + (tabCellule_[x+1][9].getCouleur() == "Vert" || tabCellule_[x + 1][9].getCouleur() == "Noir") +
		(tabCellule_[x+1][y].getCouleur() == "Vert" || tabCellule_[x + 1][y].getCouleur() == "Noir") + (tabCellule_[x+1][y + 1].getCouleur() == "Vert" || tabCellule_[x + 1][y + 1].getCouleur() == "Noir");

	else
		EstVert = (tabCellule_[x - 1][y - 1].getCouleur() == "Vert" || tabCellule_[x - 1][y - 1].getCouleur() == "Noir") + (tabCellule_[x - 1][y].getCouleur() == "Vert" || tabCellule_[x - 1][y].getCouleur() == "Noir") 
		+ (tabCellule_[x - 1][0].getCouleur() == "Vert" || tabCellule_[x - 1][0].getCouleur() == "Noir")
		+ (tabCellule_[x][y - 1].getCouleur() == "Vert" || tabCellule_[x][y - 1].getCouleur() == "Noir") + (tabCellule_[x][0].getCouleur() == "Vert" || tabCellule_[x][0].getCouleur() == "Noir") 
		+ (tabCellule_[x+1][y - 1].getCouleur() == "Vert" || tabCellule_[x + 1][y - 1].getCouleur() == "Noir") +
		(tabCellule_[x + 1][y].getCouleur() == "Vert" || tabCellule_[x + 1][y].getCouleur() == "Noir") + (tabCellule_[x + 1][0].getCouleur() == "Vert" || tabCellule_[x + 1][0].getCouleur() == "Noir");

	if (EstVert == 3) 
	{
		return "Vert";
	}
	else if (EstVert == 2) 
	{
		if (tabCellule_[x][y].getCouleur() == "Rouge")
			return "Blanc";
		else if (tabCellule_[x][y].getCouleur() == "Vert" || tabCellule_[x][y].getCouleur() == "Noir")
			return "Rouge";
		else
			return "Blanc";
	}
	else if (EstVert < 2 || EstVert >3)
	{ 
		if (tabCellule_[x][y].getCouleur() == "Vert" || tabCellule_[x][y].getCouleur() == "Noir")
			return "Rouge";
	}
	return "Blanc";

}//retourne la couleur de la cellule (x/y) au tour suivant
