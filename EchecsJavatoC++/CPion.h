#pragma once
#include "CPiece.h"

class CPion :public CPiece
{
private:
	bool premierCoup = true;

public:
	CPion(Couleur c, CEchequier* ech);
	~CPion();
	CPiece* Deplacer(int xa, int ya);
};

