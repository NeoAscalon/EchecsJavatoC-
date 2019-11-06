#include "CPiece.h"

void CPiece::situer(int, int)
{
}

void CPiece::Deplacer(int, int)
{
}

bool CPiece::verifier(int, int)
{
	return false;
}

bool CPiece::trajectoire(int, int)
{
	return false;
}

void CPiece::placer(int, int)
{
}

CPiece::CPiece(Couleur Coul, CEchequier &ech)
{
	if (ech == NULL) {
		cout << "l'echiquier est vide"<<endl;
	}
	else {
		unEchiquier = ech;
		if (coul == Couleur.Noir || coul == Couleur.Blanc) {
			couleur = coul;
		}
		else {
			System.out.println("Couleur erronee : " + couleur);
		}
	}
}

CPiece::~CPiece()
{

}