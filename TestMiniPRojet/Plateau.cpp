#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plateau.h"

using namespace std;

Plateau::~Plateau()
{
	delete grille_;
}

/*void Plateau::afficherGrille(sf::RenderWindow& window)
{
	std::vector<sf::RectangleShape> lines;
	// Lignes verticales

	for (int i = 0; i <= 17; i++)
	{
		if (i < 9) {
			lines.push_back(sf::RectangleShape(sf::Vector2f(4, 300)));
			lines[i].setPosition(i * 30 + 28, 0);
		}
		else {
			lines.push_back(sf::RectangleShape(sf::Vector2f(300, 4)));
			lines[i].setPosition(0, (i - 9) * 30 + 28);
		}
	}
	// Lignes de couleurs noires
	for (size_t i = 0; i < lines.size(); i++)
		lines[i].setFillColor(sf::Color::Black); //Donne la couleur de la ligne
	// Affichage
	for (size_t i = 0; i < lines.size(); i++)
		window.draw(lines[i]);

	sf::RectangleShape r2(sf::Vector2f(56, 56));
	r2.setOrigin(28, 28);
	r2.setPosition(16*30, 16*30);
	r2.setFillColor(sf::Color::Blue);

}*/

void Plateau::creerfenetre()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "Test Grille");

	int tab[10][10];
	for (size_t i = 0; i < 10; i++)
		for (size_t j = 0; j < 10; j++)
			tab[i][j] = 0;
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
	else
		r1.setFillColor(sf::Color::White);

	window.draw(r1);
}

void Plateau::choisirplace(Grille* g)
{
	//string choix;
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
						Cellule[localPosition.x][localPosition.y] = 1;
						g->setCellule(localPosition.x, localPosition.y, "Vert");
					}
					else
					{
						Cellule[localPosition.x][localPosition.y] = 0;
						g->setCellule(localPosition.x, localPosition.y, "Blanc");
					}
				}
				/*else if (event.mouseButton.button == sf::Mouse::Right)
				{
					sf::Vector2i localPosition = sf::Mouse::getPosition(window);
					localPosition /= 60;

					if (Cellule[localPosition.x][localPosition.y] == 0)
					{
						cout << "Ca marche !";
						for (int j = 0; j < 10; j++)
							Cellule[j][localPosition.y] = 1;
					}
					else
					{
						for (int j = 0; j < 10; j++)
							Cellule[j][localPosition.y] = 0;
					}
				}*/
				break;
			case sf::Event::LostFocus:

				string choix;
				do
				{
					cout << "Voulez-vous lancer la simulation ? (o/n): ";
					cin >> choix;
				} while (choix != "n" && choix != "o");
				if (choix == "o")
				{
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							g->actualiserCellule(i, j);
							if (g->getCellule(i, j).getCouleur() == "Vert")
								Cellule[i][j] = 1;
							else if (g->getCellule(i, j).getCouleur() == "Rouge")
								Cellule[i][j] = 2;
							else
								Cellule[i][j] = 0;
						}
					}
				}
				break;
			}
		window.clear(sf::Color::White);
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (Cellule[i][j] == 1)
					rectangle(window, i, j, 1);
				else if (Cellule[i][j] == 2)
					rectangle(window, i, j, 2);
				else
					rectangle(window, i, j, 0);
			}
		}
		window.display();
		}
	}
}
			/*while (window.pollEvent(event)) {
				// Demande de fermeture de la fenêtre
				if (event.type == sf::Event::Closed)
					window.close();
				// Appui sur le bouton gauche
				if ((event.type == sf::Event::MouseButtonPressed)
					&& (event.mouseButton.button == sf::Mouse::Left)) {

					// Position de la souris dans par rapport à la fenêtre
					sf::Vector2i localPosition = sf::Mouse::getPosition(window);
					// Position de la souris dans le tableau
					localPosition /= 30;
					// Affichage console des coordonées
					//std::cout << localPosition.x << " " << localPosition.y << std::endl;
					// Si on tombe sur une case vide
					if (tab[localPosition.x][localPosition.y] == 0)
					{
						tab[localPosition.x][localPosition.y] = 1;
						g->setCellule(localPosition.x, localPosition.y, "Green");
						//g->affichertabCellule_();
						// On met a jour le nombre de cases vides
						nbLeft--;
					}
					else {
						tab[localPosition.x][localPosition.y] = 0;
						g->setCellule(localPosition.x, localPosition.y, "White");
						//g.affichertabCellule_();

						nbLeft++;
					}
				}
			}
			// On efface la fenêtre (en blanc)
			window.clear(sf::Color::White);
			// On affiche la grille
			afficherGrille(window);
			// Parcours du tableau
			for (size_t i = 0; i < 10; i++) {
				for (size_t j = 0; j < 10; j++) {
					// Affichage du jeton
					if (tab[i][j] == 1)
						rectangle(window, i, j, 1);
				}
			}
			// Mise à jour de la fenêtre
			window.display();
		}
		//simuler(g);*/


/*void Plateau::simuler(Grille* g)
{
	string choix;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			g->actualiserCellule(i, j);
		}
	}
	sf::RenderWindow window(sf::VideoMode(300, 300), "Test Grille");
	int tab[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (g->getCellule(i, j).getCouleur() == "Vert")
				tab[10][10] = 1;
			else if (g->getCellule(i, j).getCouleur() == "Rouge")
				tab[10][10] = 2;
			else
				tab[10][10] = 0;
		}
	}
	cout << "stoper la simu ? (o/n)" << endl;
	while (window.isOpen() && choix != "n")
	{
		window.clear(sf::Color::White);
		// On affiche la grille
		afficherGrille(window);
		// Parcours du tableau
		for (size_t i = 0; i < 10; i++) {
			for (size_t j = 0; j < 10; j++) {
				// Affichage du jeton
				if (tab[i][j] == 1)
					rectangle(window, i, j, 1);
				else if (tab[i][j] == 2)
					rectangle(window, i, j, 2);
			}
		}
		// Mise à jour de la fenêtre
		window.display();
		cin >> choix;
	}
}*/




