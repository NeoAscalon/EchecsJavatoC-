#include "CTour.h"

CTour::CTour(Couleur c, CEchequier* ech) :CPiece(c, ech)
{
	rep = 'T';
	if (c == Couleur(Noir))
		rep = 't';
}

CTour::~CTour()
{
}

CPiece* CTour::Deplacer(int xa, int ya)
{
	CPiece* prise = nullptr;
	if (verifier(xa, ya)) {
		int dx = abs(xa - x);
		int dy = abs(ya - y);

		// OK si deplacement en parallele
		if (dx == 0 || dy == 0) {
			if (trajectoire(xa, ya)) {
				prise = placer(xa, ya);
			}
		}
		else {
			throw CExceptionDeplacement("Trajectoire non Conforme.");
		}
	}
	return prise;
}