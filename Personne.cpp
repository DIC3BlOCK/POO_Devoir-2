#include "Personne.h"

Personne::Personne(string _nom, int _age, string _role)
{

	nom = _nom;
	age = _age;
	role = _role;

}

string Personne::get_Nom() { return nom; }
int Personne::get_Age() { return age; }
string Personne::get_Role() { return role; }