#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <string>
using namespace std;

class Parcours;

class Joueur {

	string nom, prenom;
	float taille;
	float poids;
	string villeNaissance;
	vector<Parcours*> parcours;

public:

	//constructeur
	Joueur(string _prenom, string _nom, float _taille, float _poids, string _villeNaissance, vector<Parcours*> _parcours);
	~Joueur();

	//getters
	string getNom();
	string getPrenom();
	float getTaille();
	float getPoids();
	string getVilleNaissance();
	vector<Parcours*> getParcours();
	Parcours* getParcours(int i);
	int getNbParcours();

	//setters
	void setParcours(vector<Parcours*> _parcours);

	//autres méthodes
	string getNomComplet();


};

#endif
