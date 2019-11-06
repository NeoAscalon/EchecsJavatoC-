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
		cout << "L'echiquier est vide" << endl;
	}
	else {
		unEchequier = ech;
		if (Coul != Noir || Coul != Rouge) {
			cout << "Une piece n'est pas de la bonne couleur /t" << "Couleur erronee : " << Coul;
		}
		}
	}
}

CPiece::~CPiece()
{

}