#include <iostream>
#include <cstdlib>
#include "MenuDepart.h"
#include "MenuLancer.h"

using namespace std;


 MenuDepart::MenuDepart() : Menu("Menu Depart")
 {
	
	ajouterOption("aide", "Afficher de l'aide");
	ajouterOption("nvlpartie", "Lancer une nouvelle partie");
	ajouterOption("chargpartie", "Charger une partie existante");
	
	ajouterOption("quitter", "Sortir de l'application");
}

void MenuDepart::executerOption(const string& nom, bool& fin)
{
	Plateau* p = new Plateau;
	MenuJeu menu(p);
	if (nom == "nvlpartie") {menu; p->Gameplay();}
	//if (nom == "chargpartie") //SaisirNotes();
}

