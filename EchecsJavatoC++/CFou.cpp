#include "CFou.h"

CFou::CFou(Couleur c, CEchiquier* ech) :CPiece(c, ech)
{
	rep = 'F';
	if (c == Couleur(Noir))
	{
		rep = 'f';
	}
}

CFou::~CFou()
{
}

CPiece* CFou::Deplacer(int xa, int ya)
{
	CPiece* prise = nullptr;
	if (verifier(xa, ya))
	{
		int dx = abs(xa - x);
		int dy = abs(ya - y);

		// si deplacement en diagonale
		if (dx == dy) {
			if (trajectoire(xa, ya)) {
				prise = placer(xa, ya);
			}
		}
		else {
			throw  CExceptionDeplacement("Trajectoire non Conforme.");
		}
	}
	return prise;
}