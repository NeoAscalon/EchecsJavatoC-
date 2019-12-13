#pragma once
#include "CPiece.h"

class CFou :public CPiece
{
public:
	CFou(Couleur c, CEchiquier* ech);
	~CFou();
	CPiece* Deplacer(int xa, int ya);

private:

};
