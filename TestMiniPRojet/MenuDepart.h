#pragma once
#include "MenuLancer.h"
#include "Plateau.h"


#include "menu.h"


class MenuDepart : public Menu
{
	
public:
	MenuDepart();
	void executerOption(const string& nom, bool& fin);
	
};


