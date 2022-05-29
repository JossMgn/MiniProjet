#include "MenuJeu.h"

MenuJeu::MenuJeu(Plateau* p) : Menu("Option de jeu")
{
	p_ = p;
	ajouterOption("Depart", "Lancer la simulation");
	ajouterOption("PasApas", "Lancer ou passer la simulation en pas a pas");
	ajouterOption("Retour debut", "Revenir a la grille d'origine");
	ajouterOption("Sauver grille", "Sauvegarder la grille d'origine");

	ajouterOption("quitter", "Revenir au menu de départ");
}

void MenuJeu::executerOption(const string& nom, bool& fin) {
	if (nom == "quitter") MenuDepart m();
	else if (nom == "Depart") p_->setsimule(true);
	else if (nom == "Retour debut") p_->retourDebut();
	else if (nom == "Sauver grille") {
		string nom;
		cout << "Choisissez le nom de la grille (precisez .txt a la fin): " << endl;
		cin >> nom;
		ofstream os(nom);
		p_->origine()->sauverGrille(os);
	}
	else if (nom == "pasApas") {
		p_->setpasApas(!p_->getpasApas());
		p_->setsimule(true);
	}
	else
	{
		Menu::executerOption(nom, fin);
	}
}
