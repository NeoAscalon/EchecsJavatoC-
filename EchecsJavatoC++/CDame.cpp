#include "CDame.h"

CDame::CDame(Couleur c, CEchequier* ech) :CPiece(c, ech)
{
	rep = 'D';
	if (c == Couleur(Noir))
		rep = 'd';
}

CDame::~CDame()
{
}

CPiece* CDame::Deplacer(int xa, int ya)
{
	CPiece* prise = nullptr;
	if (verifier(xa, ya)) {
		int dx = xa - x;
		int dy = ya - y;

		if (abs(dx) == abs(dy)
			|| dx == 0 || dy == 0) {
			if (trajectoire(xa, ya)) {
				prise = placer(xa, ya);
			}
		}
		else {
			throw CExceptionDeplacement("Trajectoire non comforme");
		}

	}
	else {

		throw CExceptionDeplacement(xa, ya, "Deplacement non valide");
	}
	return prise;
}