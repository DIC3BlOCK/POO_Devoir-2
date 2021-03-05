#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
using namespace std;

class Personne
{

	string nom, role;
	int age;

public:

	//Constructeur
	Personne(string _nom, int _age, string _role);

	//Getters
	string get_Nom();
	int get_Age();
	string get_Role();

};
#endif 
