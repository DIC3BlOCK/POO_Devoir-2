/*---------------------------------------------------------------------*/
/* FICHIER: Ecran.cpp                                                  */
/*                                                                     */
/* AUTEUR(S): Thomas Bergeron, Alex Roberge                            */
/*                                                                     */
/* DATE: 2021/02/10                                                    */
/*                                                                     */
/* DESCRIPTION: Fonction 'secondaire' du programme. En fait, tout se   */
/*				passe ici, affichage comme appel de fonction.          */
/*---------------------------------------------------------------------*/

//#Inclusions des autres fichiers nécessaires au fonctionnement du programme.
#include "Ecran.h"
#include "Club.h"
#include "Palmares.h"
#include "Parcours.h"
#include "Joueur.h"
#include "Arena.h"
#include "Entraineur.h"
#include "TitreGagne.h"
#include "Personne.h"
#include "LigueHockey.h"

//Constructeur classe écran
Ecran::Ecran(LigueHockey* _ligue) {

	ligue = _ligue;

}

void Ecran::Menu() {

	system("cls");

	cout << "----------Bienvenue dans le gestionnaire de ligue de Hockey!----------";
	cout << endl << endl;
	cout << "Il y a présentement " << ligue->getNbClubs() << " clubs dans la ligue" << endl << endl;
	cout << "1) Ajouter un nouveau club" << endl;
	cout << "2) Supprimer un club" << endl;
	cout << "3) Caractéristiques d'un sportif" << endl;
	cout << "4) Trouver l'entraineur le plus titré de la ligue" << endl;
	cout << "5) Trouver le club le plus titré de la ligue" << endl;
	cout << "0) Quitter" << endl;
	cout << endl << "Votre choix: ";

}

void Ecran::MenuPrincipal() {

	int entree;

	Menu(); //Appel de la fonction d'affichage plus haut.
	entree = CinIntFailSafe();//Entrer le choix de l'utilisateur.

	while (entree != 0) { 

		switch (entree) {

			case 1:

				//Ajout de club
				AjouterClub();

				break;
			case 2:

				//supprimer club
				SupprimerClub();

				break;
			case 3:

				//Menu de caractéristiques d'un sportif (Entraineur ou joueur)
				CaracteristiquesSportif();

				break;
			case 4:

				//Entraineur le plus titré de la ligue
				AfficherEntraineurPlusTitre();

				break;
			case 5:

				//Club le plus titré de la ligue
				AfficherClubPlusTitre();

				break;
			default :

				cout << "Entrée invalide. Veuillez réessayer" << endl;

				break;

		}

		Menu();
		entree = CinIntFailSafe();

	}

}

void Ecran::AjouterClub() {

	//variables locales à la fonction
	string nom, histoire, couleur;
	int annee;
	string ville, adresse;

	system("cls"); //Clear l'invite de commande.

	cout << "----------AJOUT CLUB----------" << endl;
	cout << "Quel est le nom du club ? " << endl;
	nom = CinString();
	cout << "Quelle est l'histoire du club? : ";
	histoire = CinString();
	cout << "Quelle est la couleur du club? : ";
	couleur = CinString();
	cout << "Quelle est l'année de création du club? : ";
	annee = CinIntFailSafe(); 
	cout << "Quelle est la ville du club? : ";
	ville = CinString();
	cout << "Quelle est l'adresse du club? : ";
	adresse = CinString();
	

	Club* club = new Club(nom, histoire, couleur, annee, ville, adresse);//Création de l'objet club

	// ### Appels de sous-programmes ####

	CreationEffectif(club); 

	CreationEntraineur(club);

	CreationStade(club);

	CreationPalmares(club);

	CreationStaffTechnique(club);

	ligue->AjouterClub(club); //Ajouter l'objet club à la liste des clubs

	system("cls");
	cout << "Le club a été créé avec succès!" << endl;
	system("PAUSE");

}

void Ecran::SupprimerClub() {

	system("cls");
	cout << "Quel club voulez-vous supprimer?" << endl;
	int clubActuel = ChoisirClubIndex();

	vector<Club*>::iterator it = ligue->getClubs().begin();

	advance(it, clubActuel);

	delete *it;

	ligue->getClubs().erase(it);



}

void Ecran::CreationEffectif(Club* club) {

	//Variables locales à la fonction
	int choix(0);

	cout << "Voulez-vous ajouter un/des joueur(s) à l'équipe?" << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;

	choix = CinIntFailSafe();

	//Loop pour ajouter des joueurs à l'équipe
	while (choix == 1) {

		system("cls");
		club->ajouterJoueur(CreationJoueur());

		system("cls");
		cout << "Voulez-vous ajouter un autre joueur à l'équipe? : " << endl;
		cout << "1) Oui" << endl;
		cout << "2) Non" << endl;

		choix = CinIntFailSafe();

	}


}

Joueur* Ecran::CreationJoueur() {

	//variables locales à la fonction
	string prenom, nom;
	string nomComplet;
	float taille, poids;
	string villeNaissance;

	cout << "Quel est le prénom du joueur? : ";
	prenom = CinString();
	cout << "Quel est le nom du joueur? : ";
	nom = CinString();
	cout << "Quelle est la taille du joueur (en mètres)? : ";
	taille = CinFloatFailSafe();
	cout << "Quel est le poids du jouueur (en kg)? : ";
	poids = CinFloatFailSafe();
	cout << "Quelle est la ville de naissance du joueur? : ";
	villeNaissance = CinString();

	vector<Parcours*> parcoursJoueur = CreationParcoursJoueur(); //Appel d'une fonction pour ajouter un parcours de joueur, avant d'en créer l'objet.

	return new Joueur(prenom, nom, taille, poids, villeNaissance, parcoursJoueur); //Retour de la création d'un joueur. 

}

vector<Parcours*> Ecran::CreationParcoursJoueur() {

	//Variables locales à la fonction
	int choix;
	string nomClub, datePassage;

	vector<Parcours*> resultat; //Liste (vecteur) de résultat

	cout << "Voulez-vous ajouter un/des parcours au joueur? : " << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;

	choix = CinIntFailSafe();

	//Loop pour ajouter des parcours au joueur
	while (choix == 1) {


		cout << "Quel est le nom du club dans lequel le joueur a joué? : ";
		nomClub = CinString();

		cout << "Quelle a été la date du passage dans ce club? : ";
		datePassage = CinString();

		Parcours* p = new Parcours(nomClub, datePassage);

		resultat.push_back(p); //Push du parcours temp 'p' dans le vector résultat 
		cout << "Le parcours a été ajouté!" << endl << endl;

		cout << "Voulez-vous ajouter un autre parcours au joueur? : " << endl;
		cout << "1) Oui" << endl;
		cout << "2) Non" << endl;

		choix = CinIntFailSafe();

	}

	return resultat;

}


void Ecran::CreationPalmares(Club* club) {

	//variables locales à la fonction
	string titre ("Aucun"), date ("");
	vector<Palmares*> palmares;
	int choix;

	system("cls");
	cout << "Le club a-t'il gagné un palmarès?" << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;

	choix = CinIntFailSafe();

	while (choix == 1) {

		cout << "Quel est le nom du titre gagné? : ";
		titre = CinString();
		cout << "Quelle est la date d'obtention du titre? : ";
		date = CinString();

		palmares.push_back(new Palmares(titre, date));

		cout << "Le palmarès a été ajouté avec succès!" << endl << endl;

		cout << "Le club a-t'il gagné un autre palmarès?" << endl;
		cout << "1) Oui" << endl;
		cout << "2) Non" << endl;

		choix = CinIntFailSafe();

	}
	club->setPalmares(palmares);

}

void Ecran::CreationEntraineur(Club* club)
{
	//variables locales à la fonction
	Entraineur* entraineur;

	int choix;
	string nom("Aucun"), prenom(""), lieuObtentionGrade(""); //Variables par défaut, si l'utilisateur ne choisit pas d'ajouter un entraîneur.

	cout << "Voulez-vous ajouter un entraîneur? " << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;

	choix = CinIntFailSafe();

	if (choix == 1) {

		cout << "Quel est le nom de l'entraîneur? : ";
		nom = CinString();
		cout << "Quel est le prénom de l'entraîneur? : ";
		prenom = CinString();
		cout << "Quel est le lieu de l'obtention de son grade ? : ";
		lieuObtentionGrade = CinString();

		entraineur = new Entraineur(nom, prenom, lieuObtentionGrade);
		CreationTitreGagne(entraineur);  //Appel de fonction, qui demande si l'entraîneur a gagné des titres ou non.

		cout << "L'entraîneur a été ajoutée avec succès!" << endl;

	}
	else {

		//Création de l'objet (par défaut) et push de celui-ci dans l'objet club.
		entraineur = new Entraineur(nom, prenom, lieuObtentionGrade);

	}

	club->setEntraineur(entraineur);

}

void Ecran::CreationTitreGagne(Entraineur* entraineur) {

	//variables locales à la fonction
	string titre, nomClub, date;
	int choix;

	cout << "L'entraineur a-t'il gagné un titre?" << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;
	choix = CinIntFailSafe();

	while (choix == 1) {

		cout << "Quel est le nom du titre gagné? : ";
		titre = CinString();
		cout << "Avec quel club le titre a-t'il été gagné? : ";
		nomClub = CinString();
		cout << "Quelle est la date d'obtention du titre? : ";
		date = CinString();

		entraineur->AjouterTitreGagne(new TitreGagne(titre, date, nomClub));

		cout << "Le titre a été ajouté avec succès!" << endl;

		cout << "L'entraineur a-t'il gagné un autre titre? : " << endl;
		cout << "1) Oui" << endl;
		cout << "2) Non" << endl;

		choix = CinIntFailSafe();

	}

}


void Ecran::CreationStade(Club* club) {

	//variables locales à la fonction
	string nom, adresse;
	string typeGlace;
	int capacite;

	system("cls");
	cout << "Quel est le nom de l'aréna du club? : ";
	nom = CinString();
	cout << "Quelle est l'adresse de l'aréna? : ";
	adresse = CinString();
	cout << "Quel est le type de glace? : ";
	typeGlace = CinString();
	cout << "Quelle est la capacité maximale de l'aréna? : ";
	capacite = CinIntFailSafe();

	club->setArena(new Arena(nom, adresse, typeGlace, capacite));

	cout << "L'aréna a été ajoutée avec succès!" << endl;

}

void Ecran::CreationStaffTechnique(Club* club) {

	//variables locales à la fonction
	string nom, role;
	int age;
	int choix (1);

	system("cls");
	cout << "---------- Création staff technique ----------" << endl;

	while (choix == 1) {

		cout << "Quel est le nom de l'employé? : ";
		nom = CinString();
		cout << "Quel est l'âge de l'employé? : ";
		age = CinIntFailSafe();
		cout << "Quel est le rôle de l'employé au sein du club? : ";
		role = CinString();

		club->ajouterStaffTechnique(new Personne(nom, age, role));

		cout << "L'employé a été ajouté avec succès!" << endl;

		cout << "Voulez-vous ajouter un autre employé? : " << endl;
		cout << "1) Oui" << endl;
		cout << "2) Non" << endl;
		choix = CinIntFailSafe();

	}

}

void Ecran::CaracteristiquesSportif() {
	/* Ce programme effectue une recherche de joueur. Elle appelle deux autres sous-programmes suite aux choix de l'utilisateur.
	   Ensuite, elle appelle une fonction d'affichage du joueur ainsi choisit. */

	system("cls");
	cout << "Dans quel club voulez-vous chercher le joueur?" << endl;
	Club* clubActuel = ChoisirClub(); 

	system("cls");
	cout << "Quel joueur voulez-vous regarder?" << endl;
	Joueur* joueurInspecte = ChoisirJoueur(clubActuel);

	system("cls");
	AfficherJoueur(joueurInspecte);



}

Club* Ecran::ChoisirClub() {

	//variables locales à la fonction
	int choix;
	bool choixValide = false;

	while (!choixValide) {

		// Affichage de la liste des clubs
		int i = 1;
		for (auto it = ligue->getClubs().begin(); it != ligue->getClubs().end(); it++) {

			Club* club = *it;
			cout << i << ") " << club->getAdresse() << ", " << club->getAnnee() << endl;
			i++;

		}

		// Demande le choix à l'utilisateur
		cout << "Votre choix : ";
		choix = CinIntFailSafe();

		if (choix > 0 && choix < (int)(ligue->getNbClubs() + 1)) {

			choixValide = true;

		}
		else {

			cout << "Entrée invalide, veuillez réessayer" << endl;

		}

	}

	return ligue->getClubs()[choix-1];

}

int Ecran::ChoisirClubIndex() {


	//variable temporaire
	int choix;
	bool choixValide = false;

	while (!choixValide) {

		// Affichage de la liste des clubs
		vector<Club*>::iterator it;
		int i = 1;
		for (it = ligue->getClubs().begin(); it != ligue->getClubs().end(); it++) {

			Club* club = *it;
			cout << i << ") " << club->getAdresse() << ", " << club->getAnnee() << endl;
			i++;

		}

		// Demande le choix à l'utilisateur
		cout << "Votre choix : ";
		choix = CinIntFailSafe();

		if (choix > 0 && choix < (int)(ligue->getNbClubs() + 1)) {

			choixValide = true;

		}
		else {

			cout << "Entrée invalide, veuillez réessayer" << endl;

		}

	}

	return (choix-1);

}

Joueur* Ecran::ChoisirJoueur(Club* club) {

	//variables locales à la fonction
	int choix;
	bool choixValide = false;

	while (!choixValide) {

		// Affichage de la liste des joueurs
		for (int i = 0; i < club->getNbJoueurs(); i++) {

			cout << (i+1) << ") " << club->getJoueur(i)->getNomComplet() << ", de " << club->getJoueur(i)->getVilleNaissance() << endl;

		}

		// Demande le choix à l'utilisateur
		cout << "Votre choix : ";
		choix = CinIntFailSafe();

		if (choix > 0 && choix <= club->getNbJoueurs()) {

			choixValide = true;

		}
		else {

			cout << "Entrée invalide, veuillez réessayer" << endl;

		}

	}

	return club->getJoueur(choix-1);

}

void Ecran::AfficherJoueur(Joueur* joueur){

	cout << "Caractéristiques de " << joueur->getNomComplet() << endl << endl;
	cout << "Ville natale: " << joueur->getVilleNaissance() << endl;
	cout << "Poids: " << joueur->getPoids() << endl;
	cout << "Taille: " << joueur->getTaille() << endl;
	
	//affichage de tous les parcours du joueur
	cout << "Parcours du joueur: " << endl;

	for (int i = 0; i < (int)joueur->getNbParcours(); i++) {

		cout << i << ")\t Nom du club: " << joueur->getParcours(i)->getNomClub() << endl;
		cout << "  \t Date de passage: " << joueur->getParcours(i)->getDatePassage() << endl;

	}

	system("PAUSE");

}

void Ecran::AfficherPalmares(Club* club) {

	system("cls");

	for (int i = 0; i < club->getNbPalmares(); i++) {

		cout << (i + 1) << ") " << club->getPalmares(i)->getTitre() << ", obtenu le " << club->getPalmares(i)->getDate() << endl;

	}

	system("pause");

}

void Ecran::AfficherEntraineurPlusTitre()
{

	vector<Club*>::iterator it;
	it = ligue->getClubs().begin();

	Entraineur *entraineur = (*it)->getEntraineur();

	for (it = ligue->getClubs().begin() + 1; it != ligue->getClubs().end(); it++)
	{
		Club * club = *it;

		if (club->getEntraineur()->getNbTitresGagne() > entraineur->getNbTitresGagne())
		{

			entraineur = club->getEntraineur();

		}
	}

	cout << "L'entraîneur le plus titré est : " << entraineur->getPrenom() << " " << entraineur->getNom() << " avec " << entraineur->getNbTitresGagne()
		<< " titres gagnés." << endl;

	system("pause");

}

void Ecran::AfficherClubPlusTitre() {

	vector<Club*>::iterator it;
	it = ligue->getClubs().begin();

	Club* max = *it;

	for (it = ligue->getClubs().begin() + 1; it != ligue->getClubs().end(); it++)
	{
		
		if ((*it)->getNbPalmares() > max->getNbPalmares()) 
		{
		
			max = *it;
		
		}
		
	}

	cout << "Le club le plus titré est : " << max->getNomClub() << " avec " << max->getNbPalmares()
		<< " titres obtenus." << endl;

	system("pause");

}

int Ecran::CinIntFailSafe() 
{
	/* Fonction pour empêcher le cin de planter si on entre un string au lieu d'un int (dans le cas d'un int). */

	int var;
	cin >> var;

	while (cin.fail()) { 

		cin.clear(); //reset les flags de cin
		cin.ignore(100, '\n'); //vide le buffer
		cout << "Svp, entrez un nombre!\n";
		cin >> var;
	}

	cin.ignore();
	return var;
}

float Ecran::CinFloatFailSafe() 
{
	/* Fonction pour empêcher le cin de planter si on entre un string au lieu d'un int (dans le cas d'un float). */

	float var;
	cin >> var;

	while (cin.fail()) {

		cin.clear(); //reset les flags de cin
		cin.ignore(100, '\n'); //vide le buffer
		cout << "Svp, entrez un nombre!\n";
		cin >> var;
	}

	cin.ignore();
	return var;
}

string Ecran::CinString()
{
	/* Fonction qui permet d'entrer des chaînes de caractères avec des espaces. Souvent appelé après un cout qui
	   demande une variable de type string. */

	string str;

	getline(cin, str);
	return str;

}