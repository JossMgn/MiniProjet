#include <iostream>
#include <cstdlib>

#include "MenuLancer.h"
#include "MenuJeu.h"
using namespace std;


MenuLancer::MenuLancer(Plateau * p ) : Menu("Exemple de menu :")
{
	p_ = p; 
	ajouterOption("aide", "Afficher de l'aide");
	ajouterOption("nvlpartie", "Lancer une nouvelle partie");
	ajouterOption("chargpartie", "Charger une partie existante");

	ajouterOption("quitter", "Sortir de l'application");
}

/*void MenuLancer::executerOption(const string& nom, bool& fin)
{
	if (nom == "nvlpartie")
	{
		p_ = new Plateau;
		p_->Gameplay();
		MenuJeu mj(p_);
		mj.executer();
		system("pause");
	}
	else if (nom == "chargpartie")
	{
		cout << "Choisir une partie" << endl;
		/*list<Grille*>::iterator it;
		for (p_->get; it != p_->getGrilles().end(); it++)
		{
			cout << it.getNom();

		}*/
		system("pause");
	}
	else
	{
		Menu::executerOption(nom, fin);
	}

}*/


MenuLancer::~MenuLancer()
{
	delete p_;
}

