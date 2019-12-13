#include "CEchequier.h"

CEchequier::CEchequier()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			damier[i][j] = nullptr;
		}
	}
}

CPiece* CEchequier::getPiece(int x, int y)
{
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
	{
		return damier[x][y];
	}
	else
	{
		cout << "Coordonnees incorrectes" << endl;
		return nullptr;
	}

}

void CEchequier::setPiece(int x, int y, CPiece* p)
{
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
	{
		damier[x][y] = p;
	}
	else {
		cout << "Coordonnees incorrectes" << endl;
	}
}

CPiece* CEchequier::enleverPiece(int x, int y)
{
	CPiece* pEnlevee = nullptr;
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
	{
		pEnlevee = damier[x][y];
		damier[x][y] = nullptr;
	}
	else
		cout << "Coordonnees incorrectes" << endl;
	return pEnlevee;
}

void CEchequier::Afficher()
{
	for (int i = 7; i >= 0; i--)
	{
		cout << "" << (char)(i + 'A') << " ";
		for (int j = 0; j < 8; j++)
		{
			if (damier[i][j] != nullptr)
				cout << " " << damier[i][j]->getRepresentation();
			else
				cout << " .";
		}
		cout << endl;
	}
	cout << "  ";
	for (int i = 0; i < 8; i++)
	{
		cout << " " << i + 1;
	}
	cout << endl << endl;
}
