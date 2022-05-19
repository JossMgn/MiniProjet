#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plateau.h"
using namespace std;

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


