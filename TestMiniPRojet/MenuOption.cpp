#include <iostream>
#include <cstdlib>
#include "MenuOption.h"

using namespace std;


ExempleMenu::ExempleMenu() : Menu("Exemple de menu :")
{
	ajouterOption("aide", "Afficher de l'aide");
	ajouterOption("nouvelleOption", "Executer la nouvelle option");
	ajouterOption("quitter", "Sortir de l'application");
}

void ExempleMenu::executerOption(const string& nom, bool& fin)
{
	if (nom == "nouvelleOption") nouvelleOption();
	else Menu::executerOption(nom, fin);
}

void ExempleMenu::nouvelleOption()
{
	cout << "Vous avez choisi la nouvelle option" << endl << endl;
	system("pause");
}

