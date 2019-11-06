#pragma once
#include "CEchequier.h"
#include<iostream>
#include <string>

using namespace std;

enum Couleur { Noir, Rouge };

class CPiece
{
public:
	void situer(int, int);
	void Deplacer(int,int);
	bool verifier(int, int);
	bool trajectoire(int, int);
	void placer(int, int);
	CPiece(Couleur, CEchequier&);
	~CPiece();

private:
	CEchequier unEchequier;
	char rep;
	int x = -1;
	int y = -1;

};