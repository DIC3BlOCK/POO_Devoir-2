#include "Arena.h"

//Constructeur
Arena::Arena(string _nom_Arena, string _adresse, string _typeGlace, int _max_places)
{
	nom_Arena = _nom_Arena;
	adresse = _adresse;
	typeGlace = _typeGlace;
	max_places = _max_places;

}


//Getters
string Arena::getNomArena() {return nom_Arena;}
string Arena::getAdresseArena() { return adresse; }
string Arena::getTypeGlace() { return typeGlace; }
int Arena::getMaxPlaces() { return max_places; }