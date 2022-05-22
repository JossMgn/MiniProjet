#pragma once
#include <SFML/Graphics.hpp>
#include "Grille.h"
#include <string>


class Plateau
{
	Grille* grille_;

public:

	Plateau(Grille* g) { grille_ = g; }
	~Plateau();

	//void afficherGrille(sf::RenderWindow &window);
	void creerfenetre();
	void rectangle(sf::RenderWindow& window, size_t i, size_t j, int couleur);
	void colorer(int i, int j);
	void choisirplace(Grille* g);
	void simuler(Grille* g);

};