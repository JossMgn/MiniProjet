#pragma once
#include <SFML/Graphics.hpp>
#include "Grille.h"
#include <string>
#include <list>


class Plateau
{
	list<Grille*> grilles_;

public:

	Plateau(Grille* g) { grilles_.push_back(g); }
	~Plateau();

	//void afficherGrille(sf::RenderWindow &window);
	void rectangle(sf::RenderWindow& window, size_t i, size_t j, int couleur);
	void ajouterGrille(Grille* g) { grilles_.push_back(g); }

	void Gameplay();
	//void simuler(Grille* g, Grille* precedent);
	//void initialiserGrille(sf::RenderWindow window);

};