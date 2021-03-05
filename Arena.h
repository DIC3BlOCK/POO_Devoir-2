#ifndef ARENA_H
#define ARENA_H

#include <string>
#include <iostream>
using namespace std;

class Arena
{
	int max_places;
	string typeGlace, nom_Arena, adresse; 

public:

	//Constructeur
	Arena(string _nom_Arena, string _adresse, string _typeGlace, int _max_places);

	//Getters
	string getNomArena();
	string getAdresseArena();
	string getTypeGlace();
	int getMaxPlaces();

};
#endif 

