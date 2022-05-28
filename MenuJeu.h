#pragma once

#ifndef _MENUJEU
#define _MENUJEU
#include"Menu.h"
#include"MenuDepart.h"
#include "Plateau.h"

class Plateau;
class MenuJeu : public Menu
{
public:
	MenuJeu(Plateau *p);
	void executerOption(const string& nom, bool& fin, Plateau*p);
};

#endif