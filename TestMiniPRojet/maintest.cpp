#include "Plateau.h"
#include <iostream>
#include "MenuLancer.h"
//#include "MenuDepart.h"
using namespace std;

//Lorsqu'on initialise la grille avec plus de 3 cellules, une erreur se produit ouvrant le header xstring qui stop tout.

//Lorsque vous lancez le d�bogueur, vous pouvez modifier la grille en cliquant sur les cases. Une fois que vous avez initialis� la grille,
//il faut cliquer sur l'invit� de commande et valid� qu'on veut lancer la simulation. Ceci fait, il faut effectu� un clique droit afin de 
//l'ex�cuter.

int main()
{
	Grille* g = new Grille;
	
	Plateau p(g);
	
	MenuLancer m(&p);
	
	m.executer();
	//p.Gameplay();
	
	

	return 0;
}