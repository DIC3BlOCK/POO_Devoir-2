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

public:


	Joueur* joueurContractant;
	Club* clubContractant, clubLibere;
	int dureeContrat;
	Date* dateEntree, dateContrat;
	Reglement* reglementContrat;

	//TODO : Faire ou finir les m�thodes. jpense que je stick avec les donn�es dem�me pour l'instant.


};







#endif

