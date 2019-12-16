/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#include "Person.h"

using namespace std;

Person::Person()
{
	firstName = "N/A";
	lastName = "N/A";
}

// overloaded constructor
Person::Person(const string& newFirst, 
	const string& newLast)
{
	firstName = newFirst;
	lastName = newLast;
}

// setName
void Person::setName(const string& newFirst, 
	const string& newLast)
{
	firstName = newFirst;
	lastName = newLast;
}

// getLastName
string Person::getLastName() const
{
	return lastName;
}

// printName
void Person::printName() const
{
	cout << lastName << ", " << firstName << endl;
}

// destructor
Person::~Person()
{

}
