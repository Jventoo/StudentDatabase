/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <iterator>
#include <fstream>
#include <string>

class Student: public Person
{
public:
	Student();

	void setStudentInfo(const std::string& newFirst, 
		const std::string& newLast, int newID, bool newPaid, 
		const std::multimap<Course, char>& newCompleted);

	int getID() const;

	int getNumberOfCourses() const;

	double getUnitsCompleted() const;

	double getGpa() const;

	bool isTuitionPaid() const;

	bool courseIsCompleted(const std::string& coursePref, 
		int courseNo) const;

	void printStudent() const;

	void printStudentInfo() const;

	~Student();

private:
    int studentID;				
    bool tuitionWasPaid;
	int totalCourses;
	std::multimap<Course, char> coursesCompleted;
};

#endif


