#include "Club.h"

#include "Joueur.h"
#include "Arena.h"
#include "Personne.h"
#include "Palmares.h"
#include "Entraineur.h"
#include "ContratEngagement.h"

//Constructeur
Club::Club(string _nom, string _histoire, string _couleur, int _annee, string _ville, string _adresse)
{
	nom = _nom;
	histoire = _histoire;
	couleur = _couleur;
	annee = _annee;
	ville = _ville;
	adresse = _adresse;

}

Club::~Club() {

	delete entraineur;
	delete arena;

	//joueurs
	for (vector<Joueur*>::iterator it = effectif.begin(); it != effectif.end(); it++) {

		delete *it;

	}

	effectif.clear();

	//personnes
	for (vector<Personne*>::iterator it = staffTechnique.begin(); it != staffTechnique.end(); it++) {

		delete *it;

	}

	staffTechnique.clear();

	//palmarès
	for (vector<Palmares*>::iterator it = palmares.begin(); it != palmares.end(); it++) {

		delete *it;

	}

	palmares.clear();

}

//Getters
string Club::getNomClub() { return nom; }
string Club::getHistoire() { return histoire; }
string Club::getCouleur() { return couleur; }
int Club::getAnnee() { return annee; }
vector<Joueur*> Club::getEffectif() { return effectif; }
string Club::getVille() { return ville; }
string Club::getAdresse() { return adresse; }
Arena* Club::getArena() { return arena; }
vector<Personne*> Club::getStaffTechnique() { return staffTechnique; }
Entraineur* Club::getEntraineur() { return entraineur; }

int Club::getNbJoueurs() { return effectif.size(); }
Joueur* Club::getJoueur(int i) { return effectif[i]; }

Palmares* Club::getPalmares(int i) { return palmares[i]; }
int Club::getNbPalmares() { return palmares.size(); }

//Setters
void Club::ajouterJoueur(Joueur* _joueur) { effectif.push_back(_joueur); }
void Club::setArena(Arena* _arena) { arena = _arena; }
void Club::setPalmares(vector<Palmares*> _palmares) { palmares = _palmares; }
void Club::ajouterStaffTechnique(Personne* _staffTechnique) { staffTechnique.push_back(_staffTechnique); }
void Club::setEntraineur(Entraineur* _entraineur) { entraineur = _entraineur; }