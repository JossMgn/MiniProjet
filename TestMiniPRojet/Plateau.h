#pragma once
#include <SFML/Graphics.hpp>
#include "Grille.h"
#include <string>
#include <list>


class Plateau
{
	list<Grille*> grilles_;

public:

	Plateau();
	~Plateau();

	void rectangle(sf::RenderWindow& window, size_t i, size_t j, int couleur);
	void ajouterGrille(Grille* g) { grilles_.push_back(g); }
	void retourDebut();
	void afficher(sf::RenderWindow &window);

	void debut();
	void simuler();

	void Gameplay();


};