#include "Palmares.h"


//Constructeur
Palmares::Palmares(string _titre, string _date)
{

	titre = _titre;
	date = _date;

}

//getters
string Palmares::getTitre() { return titre; }
string Palmares::getDate()  { return date; }

