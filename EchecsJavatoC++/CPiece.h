#pragma once
#include "CEchequier.h"

enum Couleur { Noir, Rouge };

class CPiece
{
public:

	CPiece(Couleur, CEchequier&);
	~CPiece();

private:
	CEchequier ech;
	char rep;
	int x;
	int y;

};