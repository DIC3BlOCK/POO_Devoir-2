#pragma once
#ifndef _MATCH_
#define _MATCH_


#include "Inclusion.h"
#include "�quipe.h"
#include "Periode_Resultat.h"

using namespace std;

class Equipe;
class Periode;
class Resultat;

class Match
{
	Equipe* equipeLocale;
	Equipe* equipeInvite;
	vector<Periode*> listePeriodesJouees;
	Resultat* resultatFinal;

};


#endif