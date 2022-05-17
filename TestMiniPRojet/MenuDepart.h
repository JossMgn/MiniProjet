#pragma once
#ifndef _MENU_MOYENNE
#define _MENU_MOYENNE


#include "menu.h"


class MenuMoyenne : public Menu
{
	Semestre* semestre_;
public:
	MenuMoyenne(Semestre& s);
	void executerOption(const string& nom, bool& fin);
	void SaisirMatieres();
	void SaisirNotes();
	void CalculMoyenne();
};


#endif
