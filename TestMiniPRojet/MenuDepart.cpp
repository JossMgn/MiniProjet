#include <iostream>
#include <cstdlib>
#include "MenuDepart.h"


using namespace std;



MenuDepart::MenuDepart(Plateau* p) : Menu("Menu Départ :")
{
	p_ = p;
	
	ajouterOption("aide", "Afficher de l'aide");
	ajouterOption("Depart", "Lancer la partie");
	ajouterOption("Pause", "Mettre pause");
	ajouterOption("pasapas", "Mode pas a pas");
	
	ajouterOption("quitter", "Sortir de l'application");
}

void MenuDepart::executerOption(const string& nom, bool& fin)
{

	
	if (nom == "Depart" ) p_->Gameplay();
	if (nom == "Pause") ;
	if (nom == "paspapas");
	if (nom != "calculmoyenne" && nom != "saisirnote" && nom != "saisirmatiere") Menu::executerOption(nom, fin);


	if (nom == "nvlpartie") { p_->Gameplay();}
	//if (nom == "chargpartie") //SaisirNotes();

}

