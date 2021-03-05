#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include <string>
#include <vector>
using namespace std;

class TitreGagne;

class Entraineur {

	string nom, prenom;
	string lieuObtentionGrade;
	vector<TitreGagne*> titresGagne;

public:

	//constructeur
	Entraineur(string _nom, string _prenom, string _lieuObtentionGrade);
	~Entraineur();

	//Getters
	string getNom();
	string getPrenom();
	string getLieuObtentionGrade();
	vector<TitreGagne*> getTitresGagne();
	int getNbTitresGagne();

	//setters
	void AjouterTitreGagne(TitreGagne* _titre);
	
};

#endif