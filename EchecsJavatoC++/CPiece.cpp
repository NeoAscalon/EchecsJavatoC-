#include "CPiece.h"

CPiece::CPiece(Couleur coul, CEchequier* ech)
{
	if (ech == nullptr)
	{
		cout << "L'echiquier est vide" << endl;
	}
	else
	{
		unEchiquier = ech;
		if (coul == Noir || coul == Rouge)
		{
			couleur = coul;
		}
		else
			cout << "Couleur erronee : " << couleur << endl;
	}
}

void CPiece::situer(int x, int y)
{
	if (x < 0 || x>7 || y < 0 || y>7)
	{
		cout << "coordonnees erronees : " << x << ", " << y << endl;
	}
	else {
		this->x = x;
		this->y = y;
		unEchiquier->setPiece(x, y, this);
	}
}

Couleur CPiece::getCouleur()
{
	return couleur;
}

char CPiece::getRepresentation()
{
	return rep;
}

bool CPiece::verifier(int xa, int ya)
{
	bool deplacer = true;
	if (xa == x && ya == y)
	{
		cout << "sans deplacement" << endl;
		deplacer = false;
	}
	else if (xa < 0 || ya < 0 || xa>7 || ya>7)
	{
		cout << "Hors echiquier" << endl;
		deplacer = false;
	}
	return deplacer;
}

bool CPiece::trajectoire(int xa, int ya)
{
	bool trajectoireOK = true;
	int dx = 0;
	int dy = 0;
	int nbCases = abs(xa - x) - 1;
	if (xa < x)
	{
		dx = -1;
	}
	if (xa > x)
	{
		dx = +1;
	}
	if (ya < y)
	{
		dy = -1;
	}
	if (ya > y)
	{
		dy = +1;
	}

	if (abs(ya - y) > nbCases)
	{
		nbCases = abs(ya - y) - 1;
	}

	for (int c = 1; c <= nbCases; c++)
	{
		int ix = x + c * dx;
		int iy = y + c * dy;

		if (unEchiquier->getPiece(ix, iy) != nullptr)
		{
			cout << "case(" << ix << "," << iy << ") occupee" << endl;
			trajectoireOK = false;
		}
	}
	return trajectoireOK;
}

CPiece* CPiece::placer(int xa, int ya)
{
	CPiece* prise = nullptr;
	if (unEchiquier->getPiece(xa, ya) != nullptr)
	{
		if (unEchiquier->getPiece(xa, ya)->getCouleur() == couleur)
		{
			cout << "La case d'arrivee est occupee par une piece de meme couleur" << endl;
			//throw new ExceptionDeplacement(xa,ya,"Case occupe par une piece de meme couleur");
		}
		else {
			cout << "prise de la piece" << endl;
			prise = unEchiquier->enleverPiece(xa, ya);
		}
	}
	unEchiquier->enleverPiece(x, y);
	situer(xa, ya);
	cout << "Deplacement effectue" << endl;
	return prise;
}