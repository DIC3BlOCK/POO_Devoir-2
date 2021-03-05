#ifndef LIGUEHOCKEY_H
#define LIGUEHOCKEY_H

#include <vector>
using namespace std;

class Club;

class LigueHockey {

	vector<Club*> clubs;

public:

	LigueHockey() {}
	LigueHockey(vector<Club*> _clubs);
	~LigueHockey();

	//getters
	vector<Club*> & getClubs();
	int getNbClubs();

	void AjouterClub(Club* club);

};

#endif
