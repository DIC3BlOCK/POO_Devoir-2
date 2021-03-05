#ifndef PARCOURS_H
#define PARCOURS_H

#include <string>
using namespace std;

class Parcours 
{

	string nomClub;
	string datePassage;

public:
	Parcours(string _nomClub, string _datePassage);
	string getNomClub();
	string getDatePassage();

};

#endif 

