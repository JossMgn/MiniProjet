#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plateau.h"
#include <windows.h>
#include <chrono>
using namespace std;

Plateau::Plateau(MenuJeu* m, Grille* g) {
	menu_ = m;
	grilles_.push_back(g);
	pasApas_ = false;
	focus_=false;
	simule_=false;
	tour_=false;
	sortie_ = false;
} 

Plateau::~Plateau()
{
	while (!grilles_.empty()) {
		delete grilles_.back();
		grilles_.pop_back();
	}
} //Détruit grilles_

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
}//affiche la fenêtre sfml

void Plateau::retourDebut() {
	while (grilles_.size() > 1) {
		delete grilles_.back();
		grilles_.pop_back();
	}
}//Permet de réinitialiser la lsite de grille grilles_ jusqu'à la première

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
}//Paramètre la forme et la couleur des cellules

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

}//Permet de déduire la couleur prise par la cellule au tour suivant et génère une nouvelle grille pour la stocker

void Plateau::Gameplay()
{
	//localPosition.x renvoie les colonnes, .y les lignes: c'est inversé !!!
	string nom;
	string choix;

	list<Grille*>::iterator origine = grilles_.begin();
	sf::RenderWindow window(sf::VideoMode(600, 600), "Test Grille");


	sf::Time ecoule = sf::milliseconds(0);
	sf::Time ecart = sf::milliseconds(1500);
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		if (getsortie() == true)
			window.close();
		else
		{
			while (window.pollEvent(event))
			{
				if (getsimule() == false)
				{
					switch (event.type)
					{
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
							}
							else
							{
								(*origine)->setCellule(localPosition.x, localPosition.y, "Blanc");
							}
						}
						break;
					case sf::Event::LostFocus:
						menu_->executer();
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

					case sf::Event::GainedFocus:
						setfocus(!getfocus());
						break;

					case sf::Event::LostFocus:
						setfocus(!getfocus());
						menu_->executer();

						break;

					case sf::Event::MouseButtonPressed:
						if (event.mouseButton.button == sf::Mouse::Right && getpasApas() == true) {
							if (gettour() == false) {
								simuler();
								settour(true);
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
								settour(false);
							}
						}


					}
				}
			}
			if (getsimule() == true && getpasApas() == false && getfocus() == true)
			{
				ecoule += clock.restart();
				if (ecoule >= ecart) {
					if (gettour() == false) {
						simuler();
						settour(true);
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
						settour(false);
					}
					ecoule = sf::milliseconds(0);
				}

			}
			afficher(window);
		}
	}
}//Permet d'associer à chaque évènement son intérêt



void Plateau::sauverNom(ofstream& os, string const &nom) const {
	if (!os.good())
		cout << "erreur";
	os << nom << endl;
}
