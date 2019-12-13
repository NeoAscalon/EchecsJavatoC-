#pragma once
#include "CPiece.h"

class CDame : public CPiece
{
public:
	CDame(Couleur c, CEchequier* ech);
	CPiece* Deplacer(int xa, int ya);
};
