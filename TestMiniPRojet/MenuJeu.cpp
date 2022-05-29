#include "MenuJeu.h"

MenuJeu::MenuJeu() : Menu("Option de jeu")
{
	P_ = new Plateau;
	P_->setMenu(this);
	ajouterOption("Simuler", "Lancer la simulation");
	ajouterOption("Pas a pas", "Passer la simulation en pas a pas");
	ajouterOption("Retour debut", "Revenir a la grille d'origine");
	ajouterOption("Sauver grille", "Sauvegarder la grille d'origine");


	ajouterOption("quitter", "Revenir au menu de départ");
}

void MenuJeu::executerOption(const string& nom, bool& fin) {
	fin = true;
	if (nom == "Simuler") simulation();
	if (nom == "Pas a pas") pasApas();
	if (nom == "Retour debut") retour();
	if (nom == "Sauver grille") sauver();
	

}

 void MenuJeu::simulation() {
	 bool fin = true;
	 string choix;
	 do {
		 cout << "Voulez-vous lancer la simulation ? (o/n): ";
		 cin >> choix;
	 } while (choix != "o" && choix != "n");
	 if (choix == "o") {
		 cout << "Cliquer sur la grille pour lancer: " << endl;
		 P_->setsimule(true);
	 }
	 //return fin;
}

 void MenuJeu::pasApas() {
		 P_->setpasApas(!P_->getpasApas());
		 P_->setfocus(!P_->getfocus());
		 cout << "Cliquer sur la grille pour relancer" << endl;
 }

 void MenuJeu::retour() {
		 P_->retourDebut();
		 P_->setsimule(false);
		 P_->setfocus(!P_->getfocus());
 }

 void MenuJeu::sauver() const {
	 string nom;
	 cout << "choisir nom (avec .txt): ";
	 cin >> nom;
	 string ext(nom, nom.size() - 4, nom.size());
	 while (ext != ".txt") {
		 cout << "ajouter .txt " << endl;
		 cin >> nom;
		 string ext(nom, nom.size() - 4, nom.size());
	 };
	 ofstream os(nom);
	 P_->getorigine()->sauverGrille(os);
	 os.close();
	 ofstream flux("Journal.txt");
	 P_->sauverNom(flux, nom);

	 cout << "Sauvegarde réussi !";
 }


