#include "Cellule.h"

using namespace std;

Cellule::Cellule(int i, int j, string couleur)
{
	setPosition(i, j);
	setCouleur(couleur);
}

void Cellule::setPosition(int i, int j)
{
	Position_[0] = i;
	Position_[1] = j;
}

void Cellule::sauver(ofstream& os) const {
	if (!os.good())
		cout << "erreur";
	os << Couleur_ << endl;
	os << Position_[0] << endl;
	os << Position_[1] << endl;
}