#pragma once
#ifndef _MENULANCER
#define _MENULANCER
//#include "MenuDepart.h"

#include "menu.h"
#include "Plateau.h"

class Plateau;

class MenuLancer : public Menu
{
	
	
	Plateau * p_;
public:
	MenuLancer(Plateau * p);
	
	void executerOption(const string& nom, bool& fin);
	//~MenuLancer();
};

#endif
