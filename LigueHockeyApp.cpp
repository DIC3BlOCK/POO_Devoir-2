/*---------------------------------------------------------------------*/
/* FICHIER: LigueHockeyApp.cpp                                         */
/*                                                                     */
/* AUTEUR(S): Thomas Bergeron, Alex Roberge                            */
/*                                                                     */
/* DATE: 2021/02/10                                                    */
/*                                                                     */
/* DESCRIPTION: Fonction principale du programme. L'éxécution de celui-*/
/*			    ci commence à cet endroit.                             */
/*---------------------------------------------------------------------*/

#include "Inclusion.h"
#include "Club.h"
#include "Ecran.h"
#include "Parcours.h"
#include "Joueur.h"
#include "Palmares.h"
#include "Entraineur.h"
#include "TitreGagne.h"
#include "LigueHockey.h"
#include "Date.h"
#include "Periode_Resultat.h"


void CreerValeursDefaut(vector<Club*> &clubs);

int main()
{
	setlocale(LC_CTYPE, "fr-FR");

	Periode test(2, 4);
	Resultat test2(5, 7);

	cout << test.nbButsLocal << endl << test2.nbButsLocal;

	/*
	vector<Club*> clubs;

	CreerValeursDefaut(clubs);

	LigueHockey* ligue = new LigueHockey(clubs);

	Ecran ecranPrincipal (ligue);
	ecranPrincipal.MenuPrincipal();

	delete ligue;*/

	return EXIT_SUCCESS;

}

void CreerValeursDefaut(vector<Club*> &clubs) {
	/* Cette fonction sert pour tester le programme principal. Elle crée des objets par défaut. */

	//Construction d'objets club par défaut
	Club* club01 = new Club("Club #1", "histoire du club #1", "couleur du club #1", 2001, "Ville du club #1", "adresse du club #1");
	Club* club02 = new Club("Club #2", "histoire du club #2", "couleur du club #2", 2002, "Ville du club #2", "adresse du club #2");
	Club* club03 = new Club("Club #3", "histoire du club #3", "couleur du club #3", 2003, "Ville du club #3", "adresse du club #3");
	Club* club04 = new Club("Club #4", "histoire du club #4", "couleur du club #4", 2003, "Ville du club #4", "adresse du club #4");
	Club* club05 = new Club("Club #5", "histoire du club #5", "couleur du club #5", 2003, "Ville du club #5", "adresse du club #5");

	//Construction de parcours de joueurs
	vector<Parcours*> parcoursJ1;
	Parcours* parcoursJoueurUn = new Parcours("clubNom1", "datePassageParcours1");
	parcoursJ1.push_back(parcoursJoueurUn);

	vector<Parcours*> parcoursJ2;
	Parcours* parcoursJoueurdeux = new Parcours("clubNom2", "datePassageParcours2");
	parcoursJ2.push_back(parcoursJoueurdeux);

	vector<Parcours*> parcoursJ3;
	Parcours* parcoursJoueurtrois = new Parcours("clubN2om3", "datePassageParcours3");
	parcoursJ2.push_back(parcoursJoueurtrois);

	vector<Parcours*> parcoursJ4;
	Parcours* parcoursJoueurquatre = new Parcours("clubN2om4", "datePassageParcours4");
	parcoursJ2.push_back(parcoursJoueurquatre);


	//Ajout de joueurs
	Joueur* j = new Joueur("Thomas", "Bergeron", 1.5f, 120, "villeNaissance", parcoursJ1);
	Joueur* j2 = new Joueur("Alex", "Roberge", 100, 54, "Sainte-Monique", parcoursJ2);
	Joueur* j3 = new Joueur("joueur3", "famille3", 123, 456, "villeNaissanceJ3", parcoursJ3);
	Joueur* j4 = new Joueur("joueur4", "famille4", 1020, 524, "villeNaissanceJ4", parcoursJ4);

	//Ajout du/des joueur(s) au club.
	club01->ajouterJoueur(j);
	club01->ajouterJoueur(j2);
	club02->ajouterJoueur(j3);
	club02->ajouterJoueur(j4);



	//palmarès des clubs
	Palmares* p1 = new Palmares("coupe stanley", "15 decembre 2001");
	Palmares* p2 = new Palmares("coupe memorial", "demain");
	Palmares* p3 = new Palmares("burger coupe", "2 juillet 1965");
	Palmares* p4 = new Palmares("coupe #4", "date #4");
	Palmares* p5= new Palmares("coupe #5", "date #5");
	Palmares* p6 = new Palmares("coupe #6", "date #6");
	Palmares* p7 = new Palmares("coupe #7", "date #7");
	Palmares* p8 = new Palmares("coupe #8", "date #8");

	vector<Palmares*> pal01;
	pal01.push_back(p1);
	pal01.push_back(p2);
	pal01.push_back(p3);
	pal01.push_back(p4);

	vector<Palmares*> pal02;
	pal02.push_back(p5);
	pal02.push_back(p6);

	vector<Palmares*> pal03;
	pal03.push_back(p7);

	vector<Palmares*> pal04;
	pal03.push_back(p8);

	club01->setPalmares(pal01);
	club02->setPalmares(pal02);
	club03->setPalmares(pal03);
	club04->setPalmares(pal04);

	//Liste de titres gagnées, pour tester l'option numéro 2 du menu (invite de commande).
	TitreGagne* titre01 = new TitreGagne("titre1", "22 novembre 1964", "Club #1");
	TitreGagne* titre02 = new TitreGagne("titre2", "23 novembre 1965", "Club #1"); //Réserver pour l'entraîneur 1, qui sera le plus titré (pour tester).
	TitreGagne* titre03 = new TitreGagne("titre3", "12 novembre 1970", "Club #1");
	/*---------------------------------------------------------------------------*/
	TitreGagne* titre04 = new TitreGagne("titre4", "25 décembre 1999", "Club #2");
	TitreGagne* titre05 = new TitreGagne("titre5", "13 septembre 2001", "Club #4");
	TitreGagne* titre06 = new TitreGagne("titre6", "12 novembre 3456", "Club #5");
	TitreGagne* titre07 = new TitreGagne("Aucun", "", "");
	

	// Ceci crée un entraîneur, lui ajoute un titre et ajoute ensuite cet entraîneur à un club. PS: peut=être faire un sous-programme si on le présente.
	Entraineur* entraineur01 = new Entraineur("Potvin", "Ivan", "Boîte de céréales"); 
	entraineur01->AjouterTitreGagne(titre01);
	entraineur01->AjouterTitreGagne(titre02); //Devrait être l'entraîneur le + titré.
	entraineur01->AjouterTitreGagne(titre03);
	club01->setEntraineur(entraineur01); 

	Entraineur* entraineur02 = new Entraineur("Massé", "Manon", "lieu d'obtention de grade 2");
	entraineur02->AjouterTitreGagne(titre04);
	club02->setEntraineur(entraineur02);

	Entraineur* entraineur03 = new Entraineur("Traillette", "Mami", "lieu d'obtention de grade 3");
	entraineur03->AjouterTitreGagne(titre05);
	club03->setEntraineur(entraineur03);

	Entraineur* entraineur04 = new Entraineur("Neutron", "Jimmy", "Laboratoire");
	entraineur04->AjouterTitreGagne(titre06);
	club04->setEntraineur(entraineur04);

	Entraineur* entraineur05 = new Entraineur("Ou-roche", "Caillou", "lieu d'obtention de grade 2");
	entraineur05->AjouterTitreGagne(titre07);
	club05->setEntraineur(entraineur05);
	

	//Envoie du club à une liste de clubs (sert entre autre à trouver le club le + titré).
	clubs.push_back(club01); 
	clubs.push_back(club02);
	clubs.push_back(club03);
	clubs.push_back(club04);
	clubs.push_back(club05);

}