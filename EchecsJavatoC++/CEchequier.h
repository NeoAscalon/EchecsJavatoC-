#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "CExceptionDeplacement.h"

using namespace std;

class CPiece;

class CEchequier
{
private:
	CPiece* damier[8][8];
public:
	CEchequier();
	~CEchequier();
	CPiece* getPiece(int x, int y);
	void setPiece(int x, int y, CPiece* p);
	CPiece* enleverPiece(int x, int y);
	void Afficher();

};