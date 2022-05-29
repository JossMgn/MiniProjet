#pragma once
#include"Menu.h"
#include "Plateau.h"

class Plateau;

class MenuJeu : public Menu
{
	Plateau* P_;

public:

	MenuJeu();
	//Plateau* setPlateau(Plateau *P) { return P_ = P; }
	void executerOption(const string& nom, bool& fin);
	Plateau* getPlateau() { return P_; }
	void pasApas();
	void simulation();
	void retour();
	void sauver() const;
	//void executer();
};