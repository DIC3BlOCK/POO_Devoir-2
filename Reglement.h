#pragma once
#ifndef _REGLEMENT_
#define _REGLEMENT_

#include "Inclusion.h"
#include "Date.h"

class Date;

class Reglement
{
private:
	float seuil, montantTransfert, montantEncaisseClub, montantRestantJoueur;
	string droits;
	Date* dateContrat;

public:

	Reglement() {}
	~Reglement() { delete dateContrat; }

	void setMontants(float _seuil, float _montantTransfert, float _montantEncaisseClub, float _montantRestantJoueur)
	{
		seuil = _seuil;
		montantTransfert = _montantTransfert;
		montantEncaisseClub = _montantEncaisseClub;
		montantRestantJoueur = _montantRestantJoueur;
	}
	void setDroits(string _droits)
	{
		droits = _droits;
	}
	void setDate(Date* _dateContrat)
	{
		dateContrat = _dateContrat;
	}
};


#endif
