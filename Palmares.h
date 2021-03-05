#ifndef PALMARES_H
#define PALMARES_H

#include <string>
using namespace std;

class Palmares
{

private:

	string titre, date;

public:
	
	//Constructeur
	Palmares(string _titre, string _date);

	//getters
	string getTitre();
	string getDate();


};

#endif

