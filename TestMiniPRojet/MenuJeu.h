#pragma once
#include"Menu.h"
#include"MenuDepart.h"
#include "Plateau.h"

class Plateau;
class MenuJeu : public Menu
{
	Plateau* p_;
public:
	MenuJeu(Plateau* p);
	void executerOption(const string& nom, bool& fin);
};