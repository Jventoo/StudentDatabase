/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
public:
	// default constructor
	Person();

	// overloaded constructor
	Person(const std::string& newFirst, 
		const std::string& newLast);
	
	// setName
	void setName(const std::string& newFirst, 
		const std::string& newLast);
	
	// getLastName
	std::string getLastName() const;

	// printName
	void printName() const;

	// destructor
	virtual ~Person();

private:
	std::string firstName;
	std::string lastName;
};

#endif 