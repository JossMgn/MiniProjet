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


void Grille::actualiserCellule(int i, int j)
{
	int EstVert = 0;
	if (i > 0 && i<9)
	{
		if (j > 0 && j < 9)
		{
			for (int k = i - 1; k < i + 2; k++)
			{
				for (int l = j - 1; l < j + 2; l++)
				{
					if (tabCellule_[k][l].getCouleur() == "Vert")
						EstVert++;
				}
			}
			if (tabCellule_[i][j].getCouleur() == "Vert")
				EstVert--;
		}
	}
	else if (j == 0 && i > 0 && i < 9)
	{
		EstVert = 0;
		for (int k = i - 1; k < i + 2; k++)
		{
			if (tabCellule_[k][4].getCouleur() == "Vert")
				EstVert++;

			for (int l = j; j < j + 2; j++)
			{
				if (tabCellule_[k][l].getCouleur() == "Vert")
					EstVert++;
			}
		}
		if (tabCellule_[i][j].getCouleur() == "Vert")
			EstVert--;
	}
	else if (j == 9 && i > 0 && i < 9)
	{
		EstVert = 0;
		for (int k = i - 1; k < i + 2; k++)
		{
			if (tabCellule_[k][0].getCouleur() == "Vert")
				EstVert++;

			for (int l = j-1; j < j + 1; j++)
			{
				if (tabCellule_[k][l].getCouleur() == "Vert")
					EstVert++;
			}
		}
		if (tabCellule_[i][j].getCouleur() == "Vert")
			EstVert--;
	}
	else if (i == 0 && j > 0 && j < 9)
	{
		EstVert = 0;
		for (int k = i ; k < i + 2; k++)
		{
			for (int l = j - 1; j < j + 2; j++)
			{
				if (tabCellule_[k][l].getCouleur() == "Vert")
					EstVert++;
			}
		}
		for (int l = j - 1; j < j + 2; j++)
		{
			if (tabCellule_[9][l].getCouleur() == "Vert")
				EstVert++;
		}
		if (tabCellule_[i][j].getCouleur() == "Vert")
			EstVert--;
	}
	else if (i == 9 && j > 0 && j < 9)
	{
		EstVert = 0;
		for (int k = i - 1; k < i + 1; k++)
		{
			for (int l = j - 1; j < j + 2; j++)
			{
				if (tabCellule_[k][l].getCouleur() == "Vert")
					EstVert++;
			}
		}
		for (int l = j - 1; j < j + 2; j++)
		{
			if (tabCellule_[0][l].getCouleur() == "Vert")
				EstVert++;
		}
		if (tabCellule_[i][j].getCouleur() == "Vert")
			EstVert--;
	}
	//Cas particuliers: les coins
	else if (i == 0 && j == 0 )
	{
		EstVert = 0;
		if (tabCellule_[0][0].getCouleur() == "Vert")
			EstVert--;
		if (tabCellule_[9][9].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[9][0].getCouleur() == "Vert")
			EstVert++;
		else if (tabCellule_[0][9].getCouleur() == "Vert")
			EstVert++;
		for (int k = i; k < i + 2; k++)
		{
			for (int l = j; l < j + 2; l++)
			{
				if (tabCellule_[k][l].getCouleur() == "Vert")
					EstVert++;
			}
		}

	}
	else if (i == 9 && j == 0)
	{
	EstVert = 0;
	if (tabCellule_[9][0].getCouleur() == "Vert")
		EstVert--;
	if (tabCellule_[9][9].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[0][0].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[0][9].getCouleur() == "Vert")
		EstVert++;
	for (int k = i-1; k < i + 1; k++)
	{
		for (int l = j; l < j + 2; l++)
		{
			if (tabCellule_[k][l].getCouleur() == "Vert")
				EstVert++;
		}
	}

	}
	else if (i == 0 && j == 9)
	{
	EstVert = 0;
	if (tabCellule_[0][9].getCouleur() == "Vert")
		EstVert--;
	if (tabCellule_[9][9].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[0][0].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[9][0].getCouleur() == "Vert")
		EstVert++;
	for (int k = i; k < i + 2; k++)
	{
		for (int l = j-1; l < j + 1; l++)
		{
			if (tabCellule_[k][l].getCouleur() == "Vert")
				EstVert++;
		}
	}

	}
	else if (i == 9 && j == 9)
	{
	EstVert = 0;
	if (tabCellule_[9][9].getCouleur() == "Vert")
		EstVert--;
	if (tabCellule_[9][0].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[0][0].getCouleur() == "Vert")
		EstVert++;
	else if (tabCellule_[0][9].getCouleur() == "Vert")
		EstVert++;
	for (int k = i-1; k < i + 1; k++)
	{
		for (int l = j - 1; l < j + 1; l++)
		{
			if (tabCellule_[k][l].getCouleur() == "Vert")
				EstVert++;
		}
	}

	}
	//Code la couleur
	if (EstVert < 2 || EstVert>3)
	{
		if (tabCellule_[i][j].getCouleur() == "Vert")
			tabCellule_[i][j].setCouleur("Rouge");
	}
	else if (EstVert == 3)
	{
		tabCellule_[i][j].setCouleur("Vert");
	}
	
}
