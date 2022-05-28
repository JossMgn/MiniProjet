#pragma once
#ifndef _MENUDEPART
#define _MENUDEPART
#include "MenuLancer.h"
#include "Plateau.h"
#include "menu.h"

class Plateau;

class MenuDepart : public Menu
{
	Plateau* p_;
public:
	MenuDepart(Plateau* p);
	void executerOption(const string& nom, bool& fin);
	
};


#endif