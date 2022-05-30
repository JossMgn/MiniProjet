#pragma once
#include <SFML/Graphics.hpp>
#include "Grille.h"
#include <string>
#include <list>
#include "MenuJeu.h"

class MenuJeu;

class Plateau
{
	MenuJeu* menu_;
	list<Grille*> grilles_;
	bool pasApas_;
	bool focus_;
	bool simule_;
	bool tour_;
	bool sortie_;

public:

	Plateau(MenuJeu* m = 0, Grille* g = new Grille);
	~Plateau();
	void ajouterGrille(Grille* g) { grilles_.push_back(g); }


	void rectangle(sf::RenderWindow& w, size_t i, size_t j, int couleur);
	void afficher(sf::RenderWindow& w);
	void initialiser();
	void simuler();
	MenuJeu* setMenu(MenuJeu* m) { return menu_ = m; }
	void retourDebut();

	Grille* getorigine() { return (*grilles_.begin()); }

	bool setsortie(bool s) { return sortie_ = s; }
	bool getsortie() { return sortie_; }
	bool setfocus(bool focus) { return focus_ = focus; }
	bool getfocus() { return focus_; }
	bool settour(bool tour) { return tour_ = tour; }
	bool gettour() { return tour_; }
	bool setsimule(bool s) { return simule_ = s; }
	bool getsimule() { return simule_; }
	bool setpasApas(bool pAp) { return pasApas_=pAp; }
	bool getpasApas() { return pasApas_; }

	void Gameplay();

	void sauverNom(ofstream& os, string const &nom) const;


};