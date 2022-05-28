#include "MenuJeu.h"

MenuJeu::MenuJeu(Plateau* p) : Menu("Option de jeu")
{
	p_ = p;
	ajouterOption("PasApas", "Passer la simulation en pas a pas");
	ajouterOption("Retour debut", "Revenir a la grille d'origine");
	ajouterOption("Sauver grille", "Sauvegarder la grille d'origine");

	ajouterOption("quitter", "Revenir au menu de départ");
}

void MenuJeu::executerOption(const string& nom, bool& fin) {
	if (nom == "quitter") MenuDepart m();
	if (nom == "Retour debut") p_->retourDebut();
	if (nom == "Sauver grille") {
		string nom;
		cout << "Choisissez le nom de la grille (precisez .txt a la fin): " << endl;
		cin >> nom;
		ofstream os(nom);
		p_->origine()->sauverGrille(os);
	}
	if (nom == "pasApas") {
		p_->setpasApas(!p_->getpasApas());
	}
}
