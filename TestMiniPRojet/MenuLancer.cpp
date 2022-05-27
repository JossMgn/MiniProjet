#include <iostream>
#include <cstdlib>

#include "MenuLancer.h"

using namespace std;


MenuLancer::MenuLancer(Plateau * p ) : Menu("Exemple de menu :")
{
	p_ = p; 
	ajouterOption("aide", "Afficher de l'aide");
	ajouterOption("nvlpartie", "Lancer une nouvelle partie");
	ajouterOption("chargpartie", "Charger une partie existante");

	ajouterOption("quitter", "Sortir de l'application");
}

void MenuLancer::executerOption(const string& nom, bool& fin)
{
	if (nom == "nvlpartie")
	{
		MenuDepart md(p_);
		md.executer();
		system("pause");
	}
	else if (nom == "chargpartie")
	{
		cout << "Choisir une partie" << endl;
		system("pause");
	}
	else
	{
		Menu::executerOption(nom, fin);
	}

}


/*MenuLancer::~MenuLancer()
{
	delete p_;
}
*/
