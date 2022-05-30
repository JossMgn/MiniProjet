#include "MenuJeu.h"

MenuJeu::MenuJeu(Grille* g) : Menu("Option de jeu")
{
	P_ = new Plateau(this,g);
	quitter_ = false;
	ajouterOption("Simuler", "Lancer la simulation");
	ajouterOption("Pas a pas", "Passer la simulation en pas a pas");
	ajouterOption("Retour debut", "Revenir a la grille d'origine");
	ajouterOption("Sauver grille", "Sauvegarder la grille d'origine");


	ajouterOption("quitter", "Revenir au menu de depart");
}

void MenuJeu::executerOption(const string& nom, bool& fin) {
	fin = true;
	if (nom == "Simuler") simulation();
	else if (nom == "Pas a pas") pasApas();
	else if (nom == "Retour debut") retour();
	else if (nom == "Sauver grille") sauver();
	else if (nom == "quitter") quitter();

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
	 int nLigne;
	 string ligne;
	 vector<string> listenom;
	 ifstream journ("Journal.txt");
	 journ >> nLigne;
	 if (nLigne < 0) 
		 nLigne = 0;
	 else {
		 for (int i = 0; i < nLigne; i++) {
			 journ >> ligne;
			 listenom.push_back(ligne);
		 }
	 }
	 nLigne++;
	 journ.close();
	 ofstream journal("Journal.txt");
	 journal << nLigne<<endl;
	 for (int i = 0; i < nLigne - 1; i++)
		 journal << listenom[i] << endl;

	 journal << nom<<endl;

	 cout << "Sauvegarde reussi !"<<endl<<"Cliquer sur la grille pour revenir";
 }

 void MenuJeu::quitter() {
	 bool fin = false;
	 char reponse;
	 cout << "Voulez-vous vraiment quitter le Plateau (o/n) ?";
	 cin >> reponse;
	 if ((reponse == 'o') || (reponse == 'O')) 
	 {
		 P_->setsortie(!P_->getsortie());
	 }
 }
