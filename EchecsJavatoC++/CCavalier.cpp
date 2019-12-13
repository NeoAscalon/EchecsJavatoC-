#include "CCavalier.h"

CCavalier::CCavalier(Couleur c, CEchequier* ech) :CPiece(c, ech)
{
	rep = 'C';
	if (c == Couleur(Noir))
		rep = 'c';
}

CCavalier::~CCavalier()
{
}

CPiece* CCavalier::Deplacer(int xa, int ya) //Seulement en L
{
	CPiece* prise = nullptr;
	if (verifier(xa, ya)) {

		int dx = abs(xa - x);
		int dy = abs(ya - y);

		if (dx + dy == 3 && dx > 0 && dy > 0) {
			prise = placer(xa, ya);
		}
		else {
			cout << "Mouvement non Valide" << endl;
			throw CExceptionDeplacement(xa, ya, "Deplacement Cavalier non conforme");
		}
	}
	else {
		throw CExceptionDeplacement(xa, ya, "Deplacement Cavalier impossible");
	}

	return prise;
}