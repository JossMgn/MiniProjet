#pragma once
#ifndef _MENU_MOYENNE
#define _MENU_MOYENNE


#include "menu.h"


class MenuDepart : public Menu
{
	
public:
	MenuDepart();
	void executerOption(const string& nom, bool& fin);
	
};


#endif
