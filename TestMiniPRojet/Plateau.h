#pragma once
#include <SFML/Graphics.hpp>
#include "Grille.h"

class Plateau
{
	Grille* grille_;

public:

	void afficherGrille(sf::RenderWindow &window);
	void rectangle(sf::RenderWindow& window, size_t i, size_t j);
	void colorer(int i, int j);

};