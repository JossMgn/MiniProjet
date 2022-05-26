#pragma once
#include <iostream>
#include <string>
using namespace std;


class Cellule
{
	string Couleur_;
	int Position_[2];

public:

	Cellule(int i=0, int j=0, string couleur="Blanc");
	string setCouleur(string couleur) { return Couleur_ = couleur; }
	int getPosition(int i) { return Position_[i]; }
	void setPosition(int i, int j);
	string getCouleur() { return Couleur_; }
};