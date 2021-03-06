#pragma once
#ifndef _EQUIPE_
#define _EQUIPE_

#include "Inclusion.h"
#include "Club.h"
#include "Joueur.h"

using namespace std;

class Club;
class Joueur;

class Equipe
{
	Club* clubEquipe;
	int nbJoueurSurTerrain, nbGardiens;
	Joueur* capitaine;
	
public:

	//constructeur
	Equipe(Club* _clubEquipe, Joueur* _capitaine,int _nbJoueurSurTerrain, int _nbGardiens)
	{
		clubEquipe = _clubEquipe;
		capitaine = _capitaine;
		nbJoueurSurTerrain = _nbJoueurSurTerrain;
		nbGardiens = _nbGardiens;
	}

	//Destructeur
	~Equipe() {}

};


#endif