#ifndef ECRAN_H
#define ECRAN_H

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

class Club;
class Joueur;
class Parcours;
class Entraineur;
class LigueHockey;

class Ecran {

	LigueHockey* ligue; //la liste des clubs de la ligue
	

public:

	Ecran(LigueHockey* _ligue);

	//Menus
	void Menu();
	void MenuPrincipal();
	void AjouterClub();
	void SupprimerClub();
	void CreationEffectif(Club* club);
	void CreationPalmares(Club* club);
	void CreationEntraineur(Club* club);
	void CreationTitreGagne(Entraineur*  entraineur);
	void CreationStade(Club* club);
	void CreationStaffTechnique(Club* club);

	Joueur* CreationJoueur();
    vector<Parcours*> CreationParcoursJoueur();
	Club* ChoisirClub();
	int ChoisirClubIndex();
	Joueur* ChoisirJoueur(Club* club);
	void AfficherJoueur(Joueur* joueur);
	void CaracteristiquesSportif();
	void AfficherEntraineurPlusTitre();
	void AfficherClubPlusTitre();
	void AfficherPalmares(Club* club);

	int CinIntFailSafe();
	float CinFloatFailSafe();
	string CinString();

};

#endif
