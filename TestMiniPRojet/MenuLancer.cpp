#include <iostream>
#include <cstdlib>
#include "MenuLancer.h"

using namespace std;


MenuLancer::MenuLancer() : Menu("Exemple de menu :")
{

	ajouterOption("aide", "Afficher de l'aide");
	ajouterOption("nvlpartie", "Lancer une nouvelle partie");
	ajouterOption("chargpartie", "Charger une partie existante");

	ajouterOption("quitter", "Sortir de l'application");
}

void MenuLancer::executerOption(const string& nom, bool& fin)
{
	if (nom == "nvlpartie") ;
	if (nom == "chargpartie") ;

	if (nom != "calculmoyenne" && nom != "saisirnote" && nom != "saisirmatiere") Menu::executerOption(nom, fin);

}

