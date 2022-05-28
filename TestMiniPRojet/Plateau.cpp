#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plateau.h"
#include <windows.h>
#include <chrono>
using namespace std;

Plateau::Plateau(Grille* g) {
	grilles_.push_back(g);
	pasApas_ = false;
} 

Plateau::~Plateau()
{
	while (!grilles_.empty()) {
		delete grilles_.back();
		grilles_.pop_back();
	}
} //D�truit grilles_

void Plateau::afficher(sf::RenderWindow &w) {
	w.clear(sf::Color::White);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((*grilles_.rbegin())->getCellule(i,j).getCouleur() == "Vert")
				rectangle(w,i, j, 1);
			else if ((*grilles_.rbegin())->getCellule(i, j).getCouleur() == "Rouge")
				rectangle(w,i, j, 2);
			else if ((*grilles_.rbegin())->getCellule(i, j).getCouleur() == "Noir")
				rectangle(w,i, j, 3);
			else
				rectangle(w,i, j, 0);
		}
	}
	w.display();
}//affiche la fen�tre sfml

void Plateau::retourDebut() {
	bool Pap = setpasApas(false);
	while (grilles_.size() > 1) {
		delete grilles_.back();
		grilles_.pop_back();
	}
}//Permet de r�initialiser la lsite de grille grilles_ jusqu'� la premi�re

void Plateau::chargergrille(ifstream& is)
{
	list<Grille*>::iterator it;
	for (it = grilles_.begin(); it != grilles_.end(); it++)
	{
		it.
	}
}

void Plateau::rectangle(sf::RenderWindow &w, size_t i, size_t j, int couleur)
{
	sf::RectangleShape r1(sf::Vector2f(58, 58));

	r1.setOutlineThickness(2);
	r1.setOutlineColor(sf::Color(0, 0, 0));

	r1.setOrigin(29, 29);
	r1.setPosition(i * 60 + 30, j * 60 + 30);

	if (couleur == 1)
		r1.setFillColor(sf::Color::Green);
	else if (couleur == 2)
		r1.setFillColor(sf::Color(255, 127, 0));
	else if (couleur == 3)
		r1.setFillColor(sf::Color::Black);
	else
		r1.setFillColor(sf::Color::White);

	w.draw(r1);
}//Param�tre la forme et la couleur des cellules

void Plateau::simuler() {
	Grille* g = new Grille;
	list<Grille*>::iterator precedent = grilles_.end();
	precedent--;
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			string Couleur = (*precedent)->actualiserCellule(x, y);

			if ((Couleur == "Vert" && (*precedent)->getCellule(x, y).getCouleur() == "Vert") || (Couleur == "Vert" && (*precedent)->getCellule(x, y).getCouleur() == "Noir"))
				Couleur = "Noir";
			g->setCellule(x, y, Couleur);
		}
	}
	ajouterGrille(g);

}//Permet de d�duire la couleur prise par la cellule au tour suivant et g�n�re une nouvelle grille pour la stocker

void Plateau::Gameplay()
{
	//localPosition.x renvoie les colonnes, .y les lignes: c'est invers� !!!
	//MenuJeu m();
	string choix;
	bool simule = false;
	bool tour = false;
	//bool pasApas = false;
	MenuJeu mj(this);
	list<Grille*>::iterator origine = grilles_.begin();
	sf::RenderWindow window(sf::VideoMode(600, 600), "Test Grille");


	sf::Time ecoule = sf::milliseconds(0);
	sf::Time ecart = sf::milliseconds(1500);
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (simule == false)
			{
				// on regarde le type de l'�v�nement...
				switch (event.type)
				{
					// fen�tre ferm�e
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						sf::Vector2i localPosition = sf::Mouse::getPosition(window);
						localPosition /= 60;

						if ((*origine)->getCellule(localPosition.x, localPosition.y).getCouleur() == "Blanc")
						{
							(*origine)->setCellule(localPosition.x, localPosition.y, "Noir");
							//cout << "colonne: " << localPosition.x << " " << "ligne: " << localPosition.y << endl;
						}
						else
						{
							(*origine)->setCellule(localPosition.x, localPosition.y, "Blanc");
						}
					}
					break;
				case sf::Event::LostFocus:
					do {
						cout << "Voulez-vous lancer la simulation ? (o/n): ";
						cin >> choix;
					} while (choix != "o" && choix != "n");
					if (choix == "o") {
						simule = true;
						//cout << "simule = " << simule << endl;
					}


					break;
				}
			}
			else
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::LostFocus:
					
					//mj.executer();
					cout << "Que voulez vous faire ?: " << endl;
					cout << "1 - Revenir au debut" << endl;
					cout << "2 - Pas � pas" << endl;
					cout << "3 - Enregistrer grille" << endl;
					cout << "4 - Quitter" << endl;
					cin >> choix;
					while (choix != "1" && choix != "2" && choix!="3" && choix != "4")
					{
						cout << "Saisir un champ valide: ";
					}
					if (choix == "1") {
						retourDebut();
						simule = false;
					}
					if (choix == "2") {
						setpasApas(true);
					}
					if (choix == "3")
					{
						string nom;
						cout << "Choisissez le nom de la grille (precisez .txt a la fin): " << endl;
						cin >> nom;
						ofstream os(nom);
						Grille *g=new Grille(nom);
						g->sauverGrille(os);
						ajouterGrille(g);
					}
					if (choix == "4")
					{
						MenuLancer m(this);
						m.executer();
					}
					//m.afficherMenu();
					break;
					
				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Right && getpasApas() == true) {
						if (tour == false) {
							simuler();
							tour = true;
						}
						else {
							for (int i = 0; i < 10; i++) {
								for (int j = 0; j < 10; j++) {
									if ((*grilles_.rbegin())->getCellule(i, j).getCouleur() == "Rouge" || (*grilles_.rbegin())->getCellule(i, j).getCouleur() == "Blanc")
										(*grilles_.rbegin())->setCellule(i, j, "Blanc");
									else
										(*grilles_.rbegin())->setCellule(i, j, "Noir");
								}
							}
							tour = false;
						}
					}


				}
			}
		}
		afficher(window);

		if (simule == true && getpasApas() == false )
		{
			ecoule += clock.restart();
			if (ecoule >= ecart) {
				if (tour == false) {
					simuler();
					tour = true;
				}
				else {
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 10; j++) {
							if ((*grilles_.rbegin())->getCellule(i, j).getCouleur() == "Rouge" || (*grilles_.rbegin())->getCellule(i, j).getCouleur() == "Blanc")
								(*grilles_.rbegin())->setCellule(i, j, "Blanc");
							else
								(*grilles_.rbegin())->setCellule(i, j, "Noir");
						}
					}
					tour = false;
				}
				ecoule = sf::milliseconds(0);
			}

		}
			
		
	}
}//Permet d'associer � chaque �v�nement son int�r�t



