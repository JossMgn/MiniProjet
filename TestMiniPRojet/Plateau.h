#pragma once
#include <SFML/Graphics.hpp>
#include "Grille.h"
#include <string>
#include <list>
#include "MenuJeu.h"


class Plateau
{
	list<Grille*> grilles_;
	bool pasApas_;
	bool simule_;
public:

	Plateau(Grille* g = new Grille);
	~Plateau();
	void ajouterGrille(Grille* g) { grilles_.push_back(g); }
	list<Grille*> getGrilles() { return grilles_; }
	void chargergrille(ifstream& is);
	void rectangle(sf::RenderWindow &w, size_t i, size_t j, int couleur);
	void afficher(sf::RenderWindow &w);
	void initialiser();
	void simuler();

	void retourDebut();

	Grille* origine() { return (*grilles_.begin()); }

	void setpasApas(bool pAp) { pasApas_=pAp; }
	bool getpasApas() { return pasApas_; }
	void setsimule(bool simule) { simule_ = simule; }
	bool getsimule() { return simule_; }
	void Gameplay();


};