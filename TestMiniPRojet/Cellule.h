#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Cellule //MIGNON Jossua//
{
	string Couleur_;
	int Position_[2];

public:

	Cellule(int i=0, int j=0, string couleur="Blanc");

	string getCouleur() { return Couleur_; }
	string setCouleur(string couleur) { return Couleur_ = couleur; }

	int getPosition(int i) { return Position_[i]; }
	void setPosition(int i, int j);

	void sauver(ofstream& os) const;

};