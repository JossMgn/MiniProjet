#pragma once
#include"Menu.h"
#include "Plateau.h"
#include "MenuAccueil.h"

class Plateau;

class MenuJeu : public Menu //CHANAVAT Emilie & MIGNON Jossua//
{
	Plateau* P_;
	bool quitter_;

public:

	MenuJeu(Grille* g = new Grille);
	void executerOption(const string& nom, bool& fin);
	Plateau* getPlateau() { return P_; }
	void pasApas();
	void simulation();
	void retour();
	void sauver() const;
	void quitter();
};