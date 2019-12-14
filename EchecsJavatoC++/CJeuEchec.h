#pragma once
#include "CPiece.h"
#include "CCavalier.h"
#include "CDame.h"
#include "CFou.h"
#include "CPion.h"
#include "CRoi.h"
#include "CRoi.h"
#include "CTour.h"

using namespace std;

class CJeuEchec
{
private:
	CEchequier* echequier;
public:
	CJeuEchec();
	~CJeuEchec();
	void initialiser();
	CPiece* jouer(int x, int y, int xa, int ya, int compteur);
	CPiece* lirePiece(int x, int y);
};

