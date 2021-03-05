#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include <string>
using namespace std;

class Joueur;
class Palmares;
class Arena;
class Personne;
class Entraineur;
class ContratEngagement;

class Club
{
	//Variables de la classe.
	string nom, histoire, couleur, ville, adresse;
	int annee;

	//Variables, de classes externes 
	vector<Joueur*> effectif; //est une liste de joueurs dynamique
	vector<Palmares*> palmares; //palmarès du club
	Entraineur* entraineur; // Entraîneur du club
	Arena* arena; //arena du club
	vector<Personne*> staffTechnique; //Staff technique, de type Personne.
	vector<ContratEngagement*> listeContrats;

public:

	//constructeurs
	Club(string _nom, string _histoire, string _couleur, int _annee, string _ville, string _adresse);
	~Club();

	//getters standards
	string getNomClub();
	string getHistoire();
	string getCouleur();
	int getAnnee();
	string getVille();
	string getAdresse();

	//getters objets
	vector <Joueur*> getEffectif();
	Joueur* getJoueur(int i);
	int getNbJoueurs();
	Palmares* getPalmares(int i);
	int getNbPalmares();
	Arena* getArena();
	vector<Personne*> getStaffTechnique();
	Entraineur* getEntraineur();

	//setters
	void ajouterJoueur(Joueur* _joueur); //juste une liste, quand on ajoute, le tableau est de taille 1 à la dernière position.
	void setArena(Arena* _arena);
	void setPalmares(vector<Palmares*> _palmares); //ajout d'un objet palmares à la classe club
	void ajouterStaffTechnique(Personne* _staffTechnique);
	void setEntraineur(Entraineur* _entraineur); //ajout d'un entraîneur à la classe club



};

#endif 
