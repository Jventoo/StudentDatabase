/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

class StudentList
{
	StudentList(const StudentList&);

	StudentList& operator=(const StudentList&);

public:
	// default constructor
	StudentList();

	// addStudent
	void addStudent(const Student& newStudent);

	// getNoOfStudents
	int getNoOfStudents() const;

	// printStudentByID
	void printStudentByID(int ID) const;

	// printStudentsByCourse
	void printStudentsByCourse(const std::string& pref, int num) const;

	// printStudentByName
	void printStudentByName(const std::string& lastName) const;

	// printStudentsOnHold
	void printStudentsOnHold() const;

	// printAllStudents
	void printAllStudents() const;

	// printStudentsByGPA
	void printStudentsByGPA(double lowerBound, double upperBound) const;

	// printStudentsByUnits
	void printStudentsByUnits(int lowerBound, int upperBound) const;

	// destroyStudentList
	void destroyStudentList();

	// destructor
	~StudentList();

private:
	std::list<Student>* studentList;
};

#endif

