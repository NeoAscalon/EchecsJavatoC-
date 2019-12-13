#pragma once
#include "CPiece.h"

class CRoi :public CPiece
{
public:
	CRoi(Couleur c, CEchequier* ech);
	~CRoi();
	CPiece* Deplacer(int xa, int ya);

private:

};
