#pragma once
#include <iostream>
#include <string>
using namespace std;


class Cellule
{
	string Couleur_;
	int Position_[2];

public:

	Cellule(int i, int j, string couleur);
	string setCouleur(string couleur) { return Couleur_ = couleur; }
	void setPosition(int i, int j);
};