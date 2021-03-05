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

//#Inclusions des autres fichiers n�cessaires au fonctionnement du programme.
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

//Constructeur classe �cran
Ecran::Ecran(LigueHockey* _ligue) {

	ligue = _ligue;

}

void Ecran::Menu() {

	system("cls");

	cout << "----------Bienvenue dans le gestionnaire de ligue de Hockey!----------";
	cout << endl << endl;
	cout << "Il y a pr�sentement " << ligue->getNbClubs() << " clubs dans la ligue" << endl << endl;
	cout << "1) Ajouter un nouveau club" << endl;
	cout << "2) Supprimer un club" << endl;
	cout << "3) Caract�ristiques d'un sportif" << endl;
	cout << "4) Trouver l'entraineur le plus titr� de la ligue" << endl;
	cout << "5) Trouver le club le plus titr� de la ligue" << endl;
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

				//Menu de caract�ristiques d'un sportif (Entraineur ou joueur)
				CaracteristiquesSportif();

				break;
			case 4:

				//Entraineur le plus titr� de la ligue
				AfficherEntraineurPlusTitre();

				break;
			case 5:

				//Club le plus titr� de la ligue
				AfficherClubPlusTitre();

				break;
			default :

				cout << "Entr�e invalide. Veuillez r�essayer" << endl;

				break;

		}

		Menu();
		entree = CinIntFailSafe();

	}

}

void Ecran::AjouterClub() {

	//variables locales � la fonction
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
	cout << "Quelle est l'ann�e de cr�ation du club? : ";
	annee = CinIntFailSafe(); 
	cout << "Quelle est la ville du club? : ";
	ville = CinString();
	cout << "Quelle est l'adresse du club? : ";
	adresse = CinString();
	

	Club* club = new Club(nom, histoire, couleur, annee, ville, adresse);//Cr�ation de l'objet club

	// ### Appels de sous-programmes ####

	CreationEffectif(club); 

	CreationEntraineur(club);

	CreationStade(club);

	CreationPalmares(club);

	CreationStaffTechnique(club);

	ligue->AjouterClub(club); //Ajouter l'objet club � la liste des clubs

	system("cls");
	cout << "Le club a �t� cr�� avec succ�s!" << endl;
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

	//Variables locales � la fonction
	int choix(0);

	cout << "Voulez-vous ajouter un/des joueur(s) � l'�quipe?" << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;

	choix = CinIntFailSafe();

	//Loop pour ajouter des joueurs � l'�quipe
	while (choix == 1) {

		system("cls");
		club->ajouterJoueur(CreationJoueur());

		system("cls");
		cout << "Voulez-vous ajouter un autre joueur � l'�quipe? : " << endl;
		cout << "1) Oui" << endl;
		cout << "2) Non" << endl;

		choix = CinIntFailSafe();

	}


}

Joueur* Ecran::CreationJoueur() {

	//variables locales � la fonction
	string prenom, nom;
	string nomComplet;
	float taille, poids;
	string villeNaissance;

	cout << "Quel est le pr�nom du joueur? : ";
	prenom = CinString();
	cout << "Quel est le nom du joueur? : ";
	nom = CinString();
	cout << "Quelle est la taille du joueur (en m�tres)? : ";
	taille = CinFloatFailSafe();
	cout << "Quel est le poids du jouueur (en kg)? : ";
	poids = CinFloatFailSafe();
	cout << "Quelle est la ville de naissance du joueur? : ";
	villeNaissance = CinString();

	vector<Parcours*> parcoursJoueur = CreationParcoursJoueur(); //Appel d'une fonction pour ajouter un parcours de joueur, avant d'en cr�er l'objet.

	return new Joueur(prenom, nom, taille, poids, villeNaissance, parcoursJoueur); //Retour de la cr�ation d'un joueur. 

}

vector<Parcours*> Ecran::CreationParcoursJoueur() {

	//Variables locales � la fonction
	int choix;
	string nomClub, datePassage;

	vector<Parcours*> resultat; //Liste (vecteur) de r�sultat

	cout << "Voulez-vous ajouter un/des parcours au joueur? : " << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;

	choix = CinIntFailSafe();

	//Loop pour ajouter des parcours au joueur
	while (choix == 1) {


		cout << "Quel est le nom du club dans lequel le joueur a jou�? : ";
		nomClub = CinString();

		cout << "Quelle a �t� la date du passage dans ce club? : ";
		datePassage = CinString();

		Parcours* p = new Parcours(nomClub, datePassage);

		resultat.push_back(p); //Push du parcours temp 'p' dans le vector r�sultat 
		cout << "Le parcours a �t� ajout�!" << endl << endl;

		cout << "Voulez-vous ajouter un autre parcours au joueur? : " << endl;
		cout << "1) Oui" << endl;
		cout << "2) Non" << endl;

		choix = CinIntFailSafe();

	}

	return resultat;

}


void Ecran::CreationPalmares(Club* club) {

	//variables locales � la fonction
	string titre ("Aucun"), date ("");
	vector<Palmares*> palmares;
	int choix;

	system("cls");
	cout << "Le club a-t'il gagn� un palmar�s?" << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;

	choix = CinIntFailSafe();

	while (choix == 1) {

		cout << "Quel est le nom du titre gagn�? : ";
		titre = CinString();
		cout << "Quelle est la date d'obtention du titre? : ";
		date = CinString();

		palmares.push_back(new Palmares(titre, date));

		cout << "Le palmar�s a �t� ajout� avec succ�s!" << endl << endl;

		cout << "Le club a-t'il gagn� un autre palmar�s?" << endl;
		cout << "1) Oui" << endl;
		cout << "2) Non" << endl;

		choix = CinIntFailSafe();

	}
	club->setPalmares(palmares);

}

void Ecran::CreationEntraineur(Club* club)
{
	//variables locales � la fonction
	Entraineur* entraineur;

	int choix;
	string nom("Aucun"), prenom(""), lieuObtentionGrade(""); //Variables par d�faut, si l'utilisateur ne choisit pas d'ajouter un entra�neur.

	cout << "Voulez-vous ajouter un entra�neur? " << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;

	choix = CinIntFailSafe();

	if (choix == 1) {

		cout << "Quel est le nom de l'entra�neur? : ";
		nom = CinString();
		cout << "Quel est le pr�nom de l'entra�neur? : ";
		prenom = CinString();
		cout << "Quel est le lieu de l'obtention de son grade ? : ";
		lieuObtentionGrade = CinString();

		entraineur = new Entraineur(nom, prenom, lieuObtentionGrade);
		CreationTitreGagne(entraineur);  //Appel de fonction, qui demande si l'entra�neur a gagn� des titres ou non.

		cout << "L'entra�neur a �t� ajout�e avec succ�s!" << endl;

	}
	else {

		//Cr�ation de l'objet (par d�faut) et push de celui-ci dans l'objet club.
		entraineur = new Entraineur(nom, prenom, lieuObtentionGrade);

	}

	club->setEntraineur(entraineur);

}

void Ecran::CreationTitreGagne(Entraineur* entraineur) {

	//variables locales � la fonction
	string titre, nomClub, date;
	int choix;

	cout << "L'entraineur a-t'il gagn� un titre?" << endl;
	cout << "1) Oui" << endl;
	cout << "2) Non" << endl;
	choix = CinIntFailSafe();

	while (choix == 1) {

		cout << "Quel est le nom du titre gagn�? : ";
		titre = CinString();
		cout << "Avec quel club le titre a-t'il �t� gagn�? : ";
		nomClub = CinString();
		cout << "Quelle est la date d'obtention du titre? : ";
		date = CinString();

		entraineur->AjouterTitreGagne(new TitreGagne(titre, date, nomClub));

		cout << "Le titre a �t� ajout� avec succ�s!" << endl;

		cout << "L'entraineur a-t'il gagn� un autre titre? : " << endl;
		cout << "1) Oui" << endl;
		cout << "2) Non" << endl;

		choix = CinIntFailSafe();

	}

}


void Ecran::CreationStade(Club* club) {

	//variables locales � la fonction
	string nom, adresse;
	string typeGlace;
	int capacite;

	system("cls");
	cout << "Quel est le nom de l'ar�na du club? : ";
	nom = CinString();
	cout << "Quelle est l'adresse de l'ar�na? : ";
	adresse = CinString();
	cout << "Quel est le type de glace? : ";
	typeGlace = CinString();
	cout << "Quelle est la capacit� maximale de l'ar�na? : ";
	capacite = CinIntFailSafe();

	club->setArena(new Arena(nom, adresse, typeGlace, capacite));

	cout << "L'ar�na a �t� ajout�e avec succ�s!" << endl;

}

void Ecran::CreationStaffTechnique(Club* club) {

	//variables locales � la fonction
	string nom, role;
	int age;
	int choix (1);

	system("cls");
	cout << "---------- Cr�ation staff technique ----------" << endl;

	while (choix == 1) {

		cout << "Quel est le nom de l'employ�? : ";
		nom = CinString();
		cout << "Quel est l'�ge de l'employ�? : ";
		age = CinIntFailSafe();
		cout << "Quel est le r�le de l'employ� au sein du club? : ";
		role = CinString();

		club->ajouterStaffTechnique(new Personne(nom, age, role));

		cout << "L'employ� a �t� ajout� avec succ�s!" << endl;

		cout << "Voulez-vous ajouter un autre employ�? : " << endl;
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

	//variables locales � la fonction
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

		// Demande le choix � l'utilisateur
		cout << "Votre choix : ";
		choix = CinIntFailSafe();

		if (choix > 0 && choix < (int)(ligue->getNbClubs() + 1)) {

			choixValide = true;

		}
		else {

			cout << "Entr�e invalide, veuillez r�essayer" << endl;

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

		// Demande le choix � l'utilisateur
		cout << "Votre choix : ";
		choix = CinIntFailSafe();

		if (choix > 0 && choix < (int)(ligue->getNbClubs() + 1)) {

			choixValide = true;

		}
		else {

			cout << "Entr�e invalide, veuillez r�essayer" << endl;

		}

	}

	return (choix-1);

}

Joueur* Ecran::ChoisirJoueur(Club* club) {

	//variables locales � la fonction
	int choix;
	bool choixValide = false;

	while (!choixValide) {

		// Affichage de la liste des joueurs
		for (int i = 0; i < club->getNbJoueurs(); i++) {

			cout << (i+1) << ") " << club->getJoueur(i)->getNomComplet() << ", de " << club->getJoueur(i)->getVilleNaissance() << endl;

		}

		// Demande le choix � l'utilisateur
		cout << "Votre choix : ";
		choix = CinIntFailSafe();

		if (choix > 0 && choix <= club->getNbJoueurs()) {

			choixValide = true;

		}
		else {

			cout << "Entr�e invalide, veuillez r�essayer" << endl;

		}

	}

	return club->getJoueur(choix-1);

}

void Ecran::AfficherJoueur(Joueur* joueur){

	cout << "Caract�ristiques de " << joueur->getNomComplet() << endl << endl;
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

	cout << "L'entra�neur le plus titr� est : " << entraineur->getPrenom() << " " << entraineur->getNom() << " avec " << entraineur->getNbTitresGagne()
		<< " titres gagn�s." << endl;

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

	cout << "Le club le plus titr� est : " << max->getNomClub() << " avec " << max->getNbPalmares()
		<< " titres obtenus." << endl;

	system("pause");

}

int Ecran::CinIntFailSafe() 
{
	/* Fonction pour emp�cher le cin de planter si on entre un string au lieu d'un int (dans le cas d'un int). */

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
	/* Fonction pour emp�cher le cin de planter si on entre un string au lieu d'un int (dans le cas d'un float). */

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
	/* Fonction qui permet d'entrer des cha�nes de caract�res avec des espaces. Souvent appel� apr�s un cout qui
	   demande une variable de type string. */

	string str;

	getline(cin, str);
	return str;

}