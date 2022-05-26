#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plateau.h"
#include <windows.h>

using namespace std;

Plateau::Plateau() {
	Grille* g = new Grille;
	grilles_.push_back(g);
}

Plateau::~Plateau()
{
	for (list<Grille*>::iterator it = grilles_.begin(); it != grilles_.end(); it++)
	{
		delete* it;
	}
	grilles_.clear();
}

void Plateau::rectangle(sf::RenderWindow& window, size_t i, size_t j, int couleur)
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

	window.draw(r1);
}

void Plateau::Gameplay()
{
	//localPosition.x renvoie les colonnes, .y les lignes: c'est inversé !!!
	string choix;
	bool simule = false;
	cout << "simule = " << simule << endl;

	list<Grille*>::iterator origine = grilles_.begin();
	sf::RenderWindow window(sf::VideoMode(600, 600), "Test Grille");

	int Cellule[10][10];
	for (size_t i = 0; i < 10; i++)
		for (size_t j = 0; j < 10; j++)
			Cellule[i][j] = 0;

	int nbLeft = 100;
	while (window.isOpen())
	{
		sf::Event event;
			while (window.pollEvent(event))
			{
				if (simule == false)
				{
					// on regarde le type de l'évènement...
					switch (event.type)
					{
						// fenêtre fermée
					case sf::Event::Closed:
						window.close();
						break;

						// touche pressée
					case sf::Event::MouseButtonPressed:
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							sf::Vector2i localPosition = sf::Mouse::getPosition(window);
							localPosition /= 60;

							if (Cellule[localPosition.x][localPosition.y] == 0)
							{
								Cellule[localPosition.x][localPosition.y] = 3;
								(*origine)->setCellule(localPosition.x, localPosition.y, "Vert");
								//cout << "colonne: " << localPosition.x << " " << "ligne: " << localPosition.y << endl;
							}
							else
							{
								Cellule[localPosition.x][localPosition.y] = 0;
								(*origine)->setCellule(localPosition.x, localPosition.y, "Blanc");
								//cout << "colonne: " << localPosition.x << " " << "ligne: " << localPosition.y << endl;
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
							cout << "simule = " << simule << endl;
						}
						break;
					}
				}
				else
				{
					//cout << "Dans la boucle simule == true" << endl;
					switch (event.type)
					{
					case sf::Event::Closed:
						window.close();
						break;

					case sf::Event::LostFocus:

						do {
							cout << "Voulez-vous stopper la simulation ? (o/n): ";
							cin >> choix;
						} while (choix != "o" && choix != "n");
						if (choix == "o")
							simule = false;
						break;

					case sf::Event::MouseButtonPressed:
						if (event.mouseButton.button == sf::Mouse::Right) {
							Grille* g = new Grille;
							list<Grille*>::iterator precedent = grilles_.end();
							precedent--;
							for (int x = 0; x < 10; x++)  //Si on passe à (x=0; x<10) on a une erreur qui ouvre un fichier "throw_bad_alloc.cpp"
							{
								for (int y = 0; y < 10; y++)
								{
									string Couleur = (*precedent)->actualiserCellule(x, y);

									if (Couleur == "Vert")
										Cellule[x][y] = 1;
									else if (Couleur == "Rouge")
										Cellule[x][y] = 2;
									else if (Couleur == "Vert" && (*precedent)->getCellule(x, y).getCouleur() == "Vert")
										Cellule[x][y] = 3;
									else
										Cellule[x][y] = 0;
									g->setCellule(x, y, Couleur);
								}
							}
							ajouterGrille(g);
							//Sleep(1000);
						}
						break;
					}
				}
			}
		
		window.clear(sf::Color::White);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (Cellule[i][j] == 1)
					rectangle(window, i, j, 1);
				else if (Cellule[i][j] == 2)
					rectangle(window, i, j, 2);
				else if (Cellule[i][j] == 3)
					rectangle(window, i, j, 3);
				else
					rectangle(window, i, j, 0);
			}
		}
		window.display();
	}
}


/*void Plateau::simuler(Grille* g, Grille* precedent)
{
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			g->setCellule(x, y, precedent->actualiserCellule(x, y));
		}
	}
}*/




