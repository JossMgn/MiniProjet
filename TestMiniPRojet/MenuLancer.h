#pragma once
#ifndef _MENU_MOYENNE
#define _MENU_MOYENNE


#include "menu.h"


class MenuLancer : public Menu
{

public:
	MenuLancer();
	void executerOption(const string& nom, bool& fin);

};


#endif
