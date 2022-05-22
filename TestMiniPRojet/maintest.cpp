#include "Plateau.h"
#include <iostream>
using namespace std;

int main()
{
	Grille* g = new Grille;
	Plateau p(g);
	p.choisirplace(g);

	return 0;
}