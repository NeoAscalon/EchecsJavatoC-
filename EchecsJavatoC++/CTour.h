#pragma once
#include "CPiece.h"

class CTour :public CPiece
{
public:
	CTour(Couleur c, CEchequier* ech);
	~CTour();
	CPiece* Deplacer(int xa, int ya);

private:

};
