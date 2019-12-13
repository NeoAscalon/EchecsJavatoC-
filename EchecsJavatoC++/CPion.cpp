#include "CPion.h"

CPion::CPion(Couleur c, CEchequier* ech) :CPiece(c, ech)
{
	rep = 'P';
	if (c == Couleur(Noir))
		rep = 'p';
}
CPion::~CPion()
{
}

CPiece* CPion::Deplacer(int xa, int ya)
{
	CPiece* prise = nullptr;
	// arreter si deplacement non verifie
	if (verifier(xa, ya) != true) {
		throw CExceptionDeplacement(xa, ya, "deplacement non valide");
	}

	// calculer le deplacement demande
	int dx = xa - x;
	int dy = ya - y;

	// verification du sens de deplacement
	if ((dx > 0 || couleur == Couleur(Rouge)) && (dx < 0 || couleur == Couleur(Noir)))
	{
		cout << "sens non valide pour ce pion" << endl;
		throw CExceptionDeplacement(xa, ya, "Sens non valide pour ce pion");
	}
	// le deplacement du pion est autorise si le deplacement est vertical

	//s'il n'y a pas de deplacement horizontal
	if (dy == 0) {
		// si deplacement de 2 cases
		if (abs(dx) == 2) {
			// il faut que cela soit le premier coup pour ce pion
			if (!premierCoup) {
				// sinon ce n'est pas autorisé
				//System.out.println(" deplacement de 2 cases non autorise");
				cout << "deplacement de 2 cases non autorise" << endl;
				throw CExceptionDeplacement(xa, ya, "Deplacement de 2 cases non autorise");
			} // le deplacement de 2 cases est autorise 
			  // si la trajectoire n'est pas validee
			else if (trajectoire(xa, ya) != true) {
				// on arrete
				throw CExceptionDeplacement(xa, ya, "Trajectoire non valide");
			}
		} // sinon, il faut que le deplacement ne soit que d'une case
		  //si il n'est pas d'une case
		else if (abs(dx) != 1) {
			//on arrete
			//System.out.println(" deplacement non conforme pour le pion");
			cout << "deplacement non conforme pour le pion" << endl;
			throw CExceptionDeplacement(xa, ya, "Deplacement non conforme pour le pion");
		}

		// il ne manque plus qu'a verifier que la case d'arrivee soit libre
		if (unEchiquier->getPiece(xa, ya) != nullptr) {
			//Si elle n'est pas libre, on arrete
			//System.out.println(" case d'arrivee non libre");
			cout << "case d'arrivee non libre" << endl;
			throw CExceptionDeplacement(xa, ya, "Case d'arrivee non libre");

		}
	} // sinon, on eut avoir un deplacement d'une case en biais pour une prise
	else if (abs(dx) != 1 || abs(dy) != 1) {
		//Si ce n'est pas un deplacement en biais d'une case, on arrete
		//System.out.println(" ce n'est pas un deplacement en diagonale d'1 case");
		cout << "ce n'est pas un deplacement en diagonale d'1 case" << endl;
		throw CExceptionDeplacement(xa, ya, "Deplacement non vallide");
	} // si deplacement en biais d'un case : case occupee par une piece opposee
	else {
		// Si la case est occupée par une piece de la même couleur, on arrete
		if (unEchiquier->getPiece(xa, ya) == nullptr || unEchiquier->getPiece(xa, ya)->getCouleur() == couleur)
		{
			//System.out.println(" la case n'est pas occupee par une piece opposee");
			cout << "la case n'est pas occupee par une piece opposee" << endl;
			throw CExceptionDeplacement(xa, ya, "La case n'est pas occupee par une piece adverse");
		}
		// Ok pour deplacement avec prise
		//System.out.println(" prise de la piece");
		cout << "prise de la piece" << endl;
	}

	// le deplacement est possible
	prise = placer(xa, ya);
	//System.out.println(" deplacement effectue");
	cout << "deplacement effectue" << endl;

	// ce ne peut plus etre la premiere fois
	premierCoup = false;
	return prise;

}