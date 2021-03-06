#pragma once
#ifndef _PERIODE_
#define _PERIODE_

#include "Inclusion.h"
using namespace std;


class Periode
{
private:
	int duree;

public:

	int nbButsLocal, nbButsAdverse;

	//Constructeur
	Periode(int _nbButsLocal, int _nbButsAdverse)
	{
		nbButsLocal = _nbButsLocal;
		nbButsAdverse = _nbButsAdverse;
	}

	//destructeur virtuel pour assurer la supression de sa classe enfant.
	virtual ~Periode() {} 

	void setDuree(int _duree)
	{
		duree = _duree;
	}

};

class Resultat : public Periode
{
public:

	Resultat(int _nbButsLocal, int _nbButsAdverse) : Periode(_nbButsLocal, _nbButsAdverse) {}
	~Resultat() {} 
};

#endif