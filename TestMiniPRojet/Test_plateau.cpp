#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plateau.h"
using namespace std;

Plateau::~Plateau()
{
	delete grille_;
}

void Plateau::afficherGrille(sf::RenderWindow& window)
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
}

void Plateau::rectangle(sf::RenderWindow& window, size_t i, size_t j)
{
	sf::RectangleShape r1(sf::Vector2f(28, 28));
	// Par défaut, l'origine est en haut à droite du rectangle
	// On met l'origine au milieu pour simplifier les calculs
	r1.setOrigin(14, 14);
	// Positionnement
	r1.setPosition(i * 30 + 15, j * 30 + 15);
	// Coueleur bleu
	r1.setFillColor(sf::Color::Green);
	// Affichage
	window.draw(r1);
}

void Plateau::executer(Grille* g)
{
	// Création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(300, 300), "Test Grille");
	// Tableau de jeu
	int tab[10][10];
	for (size_t i = 0; i < 10; i++)
		for (size_t j = 0; j < 10; j++)
			tab[i][j] = 0;
	// Compte le nombre de cases vide
	int nbLeft = 100;
	// Boucle principale
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
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
				if (tab[localPosition.x][localPosition.y] == 0) {
					// On remplie en fonction du tour du joueur 1 = vert et 0 rien
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
					rectangle(window, i, j);
			}
		}
		// Mise à jour de la fenêtre
		window.display();
	}

}


