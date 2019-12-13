#pragma once
#include "CEchequier.h"
#include<iostream>
#include <string>

using namespace std;

enum Couleur { Noir, Rouge };

class CPiece
{
protected:
	CEchequier* unEchiquier;
	char rep;
	Couleur couleur;
	int x = -1;
	int y = -1;
public:
	CPiece(Couleur coul, CEchequier* ech);
	void situer(int x, int y);
	Couleur getCouleur();
	char getRepresentation();
	virtual CPiece* deplacer(int xa, int ya) = 0;
	bool verifier(int xa, int ya);
	bool trajectoire(int xa, int ya);
	CPiece* placer(int xa, int ya);
};