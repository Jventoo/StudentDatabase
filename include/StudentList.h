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
#include <vector>
#include <algorithm>

class StudentList
{

public:
	StudentList();

	StudentList(int newCap);

	StudentList(const StudentList&);

	StudentList& operator=(const StudentList&);

	// Add student to end of studentList
	void addStudent(const Student& newStudent);

	// Return number of students
	int getNoOfStudents() const;

	// Print full information of student with matching ID
	void printStudentByID(int ID) const;

	// Print full information of all students who have/are taking a current course
	void printStudentsByCourse(const std::string& pref, int num) const;

	// Print the ID numbers of all students with matching last name
	void printStudentsByName(const std::string& lastName) const;

	// Print full information of all students who haven't paid tuition
	void printStudentsOnHold() const;

	// Print full information of all students
	void printAllStudents() const;

	// Print full information of all students within an inclusive GPA range
	void printStudentsByGPA(double lowerBound, double upperBound) const;

	// Print full information of all students within an inclusive unit range
	void printStudentsByUnits(int lowerBound, int upperBound) const;

	// destructor
	~StudentList();

private:
	std::vector<Student> studentList;

	// Amount to increase vector when at capacity
	static const int CAP;
};

#endif

