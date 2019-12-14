#pragma once
#include "CEchequier.h"

using namespace std;

enum Couleur { Noir, Rouge };

class CPiece
{
public:
	CPiece(Couleur, CEchequier*);
	void situer(int x, int y);
	Couleur getCouleur();
	char getRepresentation();
	virtual CPiece* Deplacer(int xa, int ya) = 0;
	bool verifier(int xa, int ya);
	bool trajectoire(int xa, int ya);
	CPiece* placer(int xa, int ya);

	protected:
	CEchequier *unEchequier;
	char rep;
	Couleur couleur;
	int x = -1;
	int y = -1;
};