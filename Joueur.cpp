#include "Joueur.h"

#include "Parcours.h"

//constructeur
Joueur::Joueur(string _prenom, string _nom, float _taille, float _poids, string _villeNaissance, vector<Parcours*> _parcours) {

	prenom = _prenom;
	nom = _nom;
	taille = _taille;
	poids = _poids;
	villeNaissance = _villeNaissance;
	parcours = _parcours;

}

Joueur::~Joueur() {

	for (vector<Parcours*>::iterator it = parcours.begin(); it != parcours.end(); it++) {

		delete *it;
	}

	parcours.clear();

}

//getters
string Joueur::getNom() {

	return nom;

}
string Joueur::getPrenom() {

	return prenom;

}
float Joueur::getTaille() {

	return taille;

}
float Joueur::getPoids() {

	return poids;

}
string Joueur::getVilleNaissance() {

	return villeNaissance;

}
vector<Parcours*> Joueur::getParcours() {

	return parcours;

}

//setters
void Joueur::setParcours(vector<Parcours*> _parcours) {

	parcours = _parcours;

}

//autres méthodes
string Joueur::getNomComplet() {

	return prenom + " " + nom;

}

Parcours* Joueur::getParcours(int i) {

	return parcours[i];

}
int Joueur::getNbParcours() {

	return parcours.size();

}
