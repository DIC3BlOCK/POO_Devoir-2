#pragma once
#ifndef _CONTRAT_ENGAGEMENT_
#define _CONTRAT_ENGAGEMENT_

#include "Joueur.h"
#include "Club.h"
#include "Date.h"
#include "Reglement.h"

class Joueur;
class Club;
class Date;
class Reglement;

class ContratEngagement
{
private:

	Joueur* joueurContractant;
	Club* clubContractant, clubLibere;
	int dureeContrat;
	Date* dateEntree, dateContrat;
	Reglement* reglementContrat;

public:


};







#endif

