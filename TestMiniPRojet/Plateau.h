#pragma once
#include <SFML/Graphics.hpp>
#include "Grille.h"

class Plateau
{
	Grille* grille_;

public:

	void afficher();
	void colorer(int i, int j);

};