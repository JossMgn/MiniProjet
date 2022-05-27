#pragma once
#include"Menu.h"
#include"MenuDepart.h"
#include "Plateau.h"

class MenuJeu : public Menu
{
public:
	MenuJeu();
	void executerOption(const string& nom, bool& fin);
};