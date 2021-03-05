#include "TitreGagne.h"

#include "Palmares.h"

//constructeur
TitreGagne::TitreGagne(string _titre, string _date, string _nomClub)
{
	
	titre = new Palmares(_titre, _date);
	nomClub = _nomClub;

}


string TitreGagne::getNomTitre() {

	return titre->getTitre();

}
string TitreGagne::getDate(){

	return titre->getDate();

}
string TitreGagne::getNomClub() {

	return nomClub;

}

TitreGagne::~TitreGagne() {

	delete titre;

}

