/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Course
{
public:
	// default constructor
	Course();

	// setCourseInfo
	void setCourseInfo(const std::string& newName,
		const std::string& newPrefix, int newNo, double newUnits);


	// getCourseName
	std::string getCourseName() const;

	// getCoursePrefix
	std::string getCoursePrefix() const;

	// getCourseNo
	int getCourseNo() const;

	// getCourseUnits
	double getCourseUnits() const;


	// printCourseInfo
	void printCourseInfo() const;

	bool operator<(const Course& rhs) const;

	// destructor;
	~Course();

private:
	std::string courseName;
	std::string coursePrefix;
	int courseNo;
    double courseUnits;
};

#endif
