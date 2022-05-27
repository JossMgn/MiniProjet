#pragma once
#include <SFML/Graphics.hpp>
#include "Grille.h"
#include <string>
#include <list>
#include "MenuJeu.h"


class Plateau
{
	list<Grille*> grilles_;
	sf::RenderWindow window_;
	bool pasApas_;

public:

	Plateau(Grille* g = new Grille);
	~Plateau();
	void ajouterGrille(Grille* g) { grilles_.push_back(g); }
	sf::RenderWindow* getWindow() { return &window_; }


	void rectangle(size_t i, size_t j, int couleur);
	void afficher();
	void initialiser();
	void simuler();

	void retourDebut();

	Grille* origine() { return (*grilles_.begin()); }

	bool setpasApas(bool pAp) { return pasApas_=pAp; }
	bool getpasApas() { return pasApas_; }

	void Gameplay();


};