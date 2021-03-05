#ifndef TITREGAGNE_H
#define TITREGAGNE_H

#include <vector>
#include <string>
using namespace std;

class Palmares;

//Lien avec les autres classes.

class TitreGagne {

	Palmares* titre;
	string nomClub;

public:

	//constructeur
	TitreGagne(string _titre, string _date, string _nomClub);
	~TitreGagne();

	//getters
	string getNomTitre();
	string getDate();
	string getNomClub();

};

#endif