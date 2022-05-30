#pragma once
#include "Menu.h";
#include "MenuJeu.h"

class MenuAccueil : public Menu //CHANAVAT Emilie//
{
public:
	MenuAccueil();
	~MenuAccueil();
	void executerOption(const string& nom, bool& fin);
	Grille* Charger();
	void Lancer(Grille* g = new Grille);
};