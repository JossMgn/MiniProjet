#include <iostream>
#include <cstdlib>
#include "MenuOption.h"

using namespace std;


MenuOption::MenuOption() : Menu("Exemple de menu :")
{
	ajouterOption("aide", "Afficher de l'aide");
	ajouterOption("nouvelleOption", "Executer la nouvelle option");
	ajouterOption("quitter", "Sortir de l'application");
}

void MenuOption::executerOption(const string& nom, bool& fin)
{
	if (nom == "nouvelleOption") nouvelleOption();
	else Menu::executerOption(nom, fin);
}

void MenuOption::nouvelleOption()
{
	cout << "Vous avez choisi la nouvelle option" << endl << endl;
	system("pause");
}

