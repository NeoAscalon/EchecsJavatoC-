#pragma once
#include "CPiece.h"

class CCavalier :public CPiece
{
public:
	CCavalier(Couleur c, CEchequier* ech);
	~CCavalier();
	CPiece* Deplacer(int xa, int ya);
};
