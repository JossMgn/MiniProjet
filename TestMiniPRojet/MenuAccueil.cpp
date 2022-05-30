#include "MenuAccueil.h"
#include <vector>

MenuAccueil::MenuAccueil() : Menu("Accueil")
{
	ajouterOption("Lancer", "Lancer une partie");
	ajouterOption("Charger", "Charger une grille existante");
	ajouterOption("quitter", "Quitter la solution");
}

void MenuAccueil::executerOption(const string& nom, bool& fin) {
	if (nom == "Lancer") Lancer();
	if (nom == "Charger") {
		Grille* g=Charger();
		Lancer(g);
	}
	else Menu::executerOption(nom, fin);
}

void MenuAccueil::Lancer(Grille* g) {
	MenuJeu* m = new MenuJeu(g);
	m->getPlateau()->Gameplay();
}

Grille* MenuAccueil::Charger() {
	Grille* g = new Grille;
	int num;
	ifstream ifs("Journal.txt");
	if (!ifs.good())
		cout << "Erreur echec d'ouverture" << endl;
	string ligne;
	int nLigne;
	ifs >> nLigne;
	vector<string> tab(nLigne);
	for (int i = 0; i < nLigne; i++) {
		//getline(ifs, tab[i]);
		ifs >> tab[i];
		cout << i << " - " << tab[i] << endl;
	}
	cout << endl;
	cout << "Choisissez votre grille: " << endl;
	cin >> num;
	while (num<0 && num>nLigne)
	{
		cout << "Choisisseze un choix valide: ";
		cin >> num;
	}
	ifstream grille(tab[num]);
	if (!grille.good())
		cout << "Erreur echec d'ouverture" << endl;
	for (int i = 0; i < 100; i++) {
		string x, y;
		string couleur;
		getline(grille, couleur);
		getline(grille, x);
		getline(grille, y);
		g->setCellule(stoi(x), stoi(y), couleur);
	}

	return g;
}