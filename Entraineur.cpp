#include "Entraineur.h"
#include "TitreGagne.h"

//constructeur
Entraineur::Entraineur(string _nom, string _prenom, string _lieuObtentionGrade) {
	nom = _nom;
	prenom = _prenom;
	lieuObtentionGrade = _lieuObtentionGrade;
}

Entraineur::~Entraineur() {

	//on delete tous les pointeurs TitreGagne référencés dans cet entraineur
	for (vector<TitreGagne*>::iterator it = titresGagne.begin(); it != titresGagne.end(); it++) {

		delete *it;

	}

	titresGagne.clear();

}

//Getters
string Entraineur::getNom() { return nom; }
string Entraineur::getPrenom() { return prenom; }
string Entraineur::getLieuObtentionGrade() { return lieuObtentionGrade; }
vector<TitreGagne*> Entraineur::getTitresGagne() { return titresGagne; }
int Entraineur::getNbTitresGagne() { return titresGagne.size(); }

//setters
void Entraineur::AjouterTitreGagne(TitreGagne* _titre) { titresGagne.push_back(_titre); }
