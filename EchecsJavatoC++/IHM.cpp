#include "IHM.h"
#include "CExceptionDeplacement.h"
#include <vector>

IHM::IHM()
{
}

IHM::~IHM()
{
}

int* IHM::saisirCoordonnees()
{
	int* tab = new int[2];
	string place;
	cout << "entrer les coordonnees : " << endl;
	cin >> place;
	cout << endl;
	tab[0] = place.at(0) - 'A';
	tab[1] = place.at(1) - '1';
	return tab;
}


void main()
{
	CPiece* p;
	bool termine = false;
	int* coorSrc;
	int* coorDest;

	CJeuEchec jeu;

	IHM ihm;

	vector<CPiece*> listPrises[2];

	int compteur = 0;

	do {
		CPiece* prise = nullptr;
		try {
			cout << "Compteur : " << compteur << endl;
			if (compteur % 2 == 0) {
				cout << "C'est aux Blancs de Jouer! " << endl;
			}
			else {
				cout << "C'est aux Noirs de Jouer! " << endl;
			}
			coorSrc = ihm.saisirCoordonnees();
			coorDest = ihm.saisirCoordonnees();
			prise = jeu.jouer(coorSrc[0], coorSrc[1], coorDest[0], coorDest[1], compteur);
			if (prise != nullptr) {
				listPrises[compteur % 2].push_back(prise);
				if (typeid(prise) == typeid(CRoi)) {
					termine = true;
				}
			}
			compteur++;
		}
		catch (CExceptionDeplacement ed) {
			cout << "mouvement non valide " << ed.what() << endl;

		}
		catch (exception e) {
			cout << "Exception !!" << e.what() << endl;
		}
	} while (termine == false);
}