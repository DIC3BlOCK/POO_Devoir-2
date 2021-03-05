#pragma once
#ifndef _DATE_
#define _DATE_


#include <string>
#include <iostream>

using namespace std;

class Date
{

private:

	short int year, month, day;

public:

	//Constructeur et destructeur
	Date(short int _year, short int _month, short int _day)
	{
		year = _year;
		month = _month;
		day = _day;

	}

	~Date() {}

	//Méthodes
	void showDate()
	{

		cout << year << "/" << month << "/" << day;

	}

	int getYear() { return year; }
	int getMonth(){return month;}
	int getDay() { return day; }

};


#endif
