#include "LigueHockey.h"

#include "Club.h"


LigueHockey::LigueHockey(vector<Club*> _clubs) {

	clubs = _clubs;

}

LigueHockey::~LigueHockey() {

	for (vector<Club*>::iterator it = clubs.begin(); it != clubs.end(); it++) {

		delete *it;

	}

	clubs.clear();

}

vector<Club*> & LigueHockey::getClubs() {

	return clubs;

}

int LigueHockey::getNbClubs() {

	return clubs.size();

}

void LigueHockey::AjouterClub(Club* club) {

	clubs.push_back(club);

}