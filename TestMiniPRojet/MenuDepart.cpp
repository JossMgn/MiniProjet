#include <iostream>
#include <cstdlib>
#include "MenuDepart.h"
#include "MenuLancer.h"

using namespace std;


 MenuDepart::MenuDepart() : Menu("Exemple de menu :")
{
	
	ajouterOption("aide", "Afficher de l'aide");
	ajouterOption("nvlpartie", "Lancer une nouvelle partie");
	ajouterOption("chargpartie", "Charger une partie existante");
	
	ajouterOption("quitter", "Sortir de l'application");
}

void MenuDepart::executerOption(const string& nom, bool& fin)
{
	MenuLancer m();
	if (nom == "nvlpartie") MenuLancer();
	if (nom == "chargpartie") SaisirNotes();

	if (nom != "calculmoyenne" && nom != "saisirnote" && nom != "saisirmatiere") Menu::executerOption(nom, fin);

}
