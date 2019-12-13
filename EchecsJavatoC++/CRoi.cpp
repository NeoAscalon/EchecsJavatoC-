#include "CRoi.h"

CRoi::CRoi(Couleur c, CEchequier* ech) :CPiece(c, ech)
{
	rep = 'R';
	if (c == Couleur(Noir))
	{
		rep = 'r';
	}
}

CRoi::~CRoi()
{
}


CPiece* CRoi::Deplacer(int xa, int ya)
{
	CPiece* prise = nullptr;
	if (verifier(xa, ya)) {
		int dx = abs(xa - x);
		int dy = abs(ya - y);

		// seule un case voisine est admissible
		if (dx <= 1 && dy <= 1) {
			prise = placer(xa, ya);
		}
		else {
			throw CExceptionDeplacement("Trajectoire non Conforme.");
		}
	}
	return prise;
}