#pragma once

#ifndef _MENU_EXEMPLE
#define _MENU_EXEMPLE

#include "menu.h"

class MenuOption : public Menu
{
public:
    MenuOption();
    void executerOption(const string& nom, bool& fin);
    void nouvelleOption();
};


#endif

