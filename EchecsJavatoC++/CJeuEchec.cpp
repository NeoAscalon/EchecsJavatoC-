#include "CJeuEchec.h"

CJeuEchec::CJeuEchec()
{
	echequier = new CEchequier();
	initialiser();
}

CJeuEchec::~CJeuEchec()
{
}

void CJeuEchec::initialiser()
{
	CTour* t1 = new CTour(Couleur(Rouge), echequier);
	t1->situer(0, 0);
	CTour* t2 = new CTour(Couleur(Noir), echequier);
	t2->situer(7, 0);
	CCavalier* c1 = new CCavalier(Couleur(Rouge), echequier);
	c1->situer(0, 1);
	CCavalier* c2 = new CCavalier(Couleur(Noir), echequier);
	c2->situer(7, 1);
	CFou* f1 = new CFou(Couleur(Rouge), echequier);
	f1->situer(0, 2);
	CFou* f2 = new CFou(Couleur(Noir), echequier);
	f2->situer(7, 2);

	CDame* d1 = new CDame(Couleur(Rouge), echequier);
	d1->situer(0, 3);
	CDame* d2 = new CDame(Couleur(Noir), echequier);
	d2->situer(7, 3);

	CRoi* r1 = new CRoi(Couleur(Rouge), echequier);
	r1->situer(0, 4);
	CRoi* r2 = new CRoi(Couleur(Noir), echequier);
	r2->situer(7, 4);

	CFou* f3 = new CFou(Couleur(Rouge), echequier);
	f3->situer(0, 5);
	CFou* f4 = new CFou(Couleur(Noir), echequier);
	f4->situer(7, 5);
	CCavalier* c3 = new CCavalier(Couleur(Rouge), echequier);
	c3->situer(0, 6);
	CCavalier* c4 = new CCavalier(Couleur(Noir), echequier);
	c4->situer(7, 6);
	CTour* t3 = new CTour(Couleur(Rouge), echequier);
	t3->situer(0, 7);
	CTour* t4 = new CTour(Couleur(Noir), echequier);
	t4->situer(7, 7);

	for (int j = 0; j < 8; j++) {
		CPion* p1 = new CPion(Couleur(Rouge), echequier);
		p1->situer(1, j);
		CPion* p2 = new CPion(Couleur(Noir), echequier);
		p2->situer(6, j);
	}
	echequier->Afficher();
}

CPiece* CJeuEchec::jouer(int x, int y, int xa, int ya, int compteur)
{
	CPiece* prise = nullptr;
	// on vérifie que les cases de départ et d'arrivee existe
	if (x < 0 || x > 7 || y < 0 || y > 7) {
		throw CExceptionDeplacement(x, y, "erreur de Depart");
	}
	if (xa < 0 || xa > 7 || ya < 0 || ya > 7) {
		throw CExceptionDeplacement(xa, ya, "Erreur d'arrive");
	}
	//System.out.println("jouer la case " + (char)(x + 'A') + "-" + (y + 1));
	cout << "jouer la case " << (char)(x + 'A') << "-" << (y + 1) << endl;

	// on récupère la pièce de la case
	CPiece* p = echequier->getPiece(x, y);
	//on vérifie qu'il y a bien une pièce 
	if (p == nullptr) {
		//System.out.println("aucune piece sur la case " + (char)(x + 'A') + "-" + y);
		cout << "aucune piece sur la case" << (char)(x + 'A') << "-" << y << endl;
		throw CExceptionDeplacement(x, y, "Pas de piece sur la case");
	}
	else {
		// on vérifie que la couleur de la pièce choisie est correcte
		if (p->getCouleur() != (compteur % 2)) {
			//System.out.println("Ce n'est pas la bonne couleur !!");
			cout << "Ce n'est pas la bonne couleur!!" << endl;
			throw CExceptionDeplacement(x, y, "Erreur de couleur");
		}
		//System.out.println(" -> la piece " + p + " vers " + (char)(xa + 'A') + "-" + (ya + 1));
		cout << " -> la piece " << p << " vers " << (char)(xa + 'A') << " - " << (ya + 1) << endl;
		// on effectue le deplacement
		prise = p->Deplacer(xa, ya);
		// on affiche l'echiquier
		echequier->Afficher();
	}

	// on retourne la prise eventuelle
	return prise;
}

CPiece* CJeuEchec::lirePiece(int x, int y)
{
	return echequier->getPiece(x, y);
}

