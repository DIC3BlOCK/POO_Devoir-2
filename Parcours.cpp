#include "Parcours.h"

Parcours::Parcours(string _nomClub, string _datePassage) {

	nomClub = _nomClub;
	datePassage = _datePassage;

}

string Parcours::getNomClub() {

	return nomClub;

}

string Parcours::getDatePassage() {

	return datePassage;

}