#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

// Affichage de la grille
void drawGrid(sf::RenderWindow& window) {
	std::vector<sf::RectangleShape> lines;
	// Lignes verticales
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 300))); //6 est l'épaisseur du trait et 300 sa longueur
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 300)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 300)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 300)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 300)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 300)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 300)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 300)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(6, 300)));
	// Lignes horizontales
	lines.push_back(sf::RectangleShape(sf::Vector2f(300, 6))); //On inverse les variables mais elles gardent leur fonction
	lines.push_back(sf::RectangleShape(sf::Vector2f(300, 6)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(300, 6)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(300, 6)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(300, 6)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(300, 6)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(300, 6)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(300, 6)));
	lines.push_back(sf::RectangleShape(sf::Vector2f(300, 6)));
	// Positionnement des lignes
	lines[0].setPosition(27, 0);
	lines[1].setPosition(57, 0); //Regle la position : plus on a un truc grand à la place de 197 plus on va à droite, Le 0 code la position % au haut >0 --> on s'éloigne de la bordure
	lines[2].setPosition(87, 0);
	lines[3].setPosition(117, 0);
	lines[4].setPosition(147, 0);
	lines[5].setPosition(177, 0);
	lines[6].setPosition(207, 0);
	lines[8].setPosition(237, 0);
	lines[9].setPosition(0, 27);
	lines[10].setPosition(0, 57);
	lines[11].setPosition(0, 87);
	lines[12].setPosition(0, 117);
	lines[13].setPosition(0, 147);
	lines[14].setPosition(0, 177);
	lines[15].setPosition(0, 207);
	lines[16].setPosition(0, 237);
	// Lignes de couleurs noires
	for (size_t i = 0; i < lines.size(); i++)
		lines[i].setFillColor(sf::Color::Black); //Donne la couleur de la ligne
	// Affichage
	for (size_t i = 0; i < lines.size(); i++)
		window.draw(lines[i]);
}

