/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#include "Course.h"

using namespace std;

// default constructor
Course::Course()
{
	courseNo = 0;
	courseUnits = 0.0;
}

// setCourseInfo
void Course::setCourseInfo(const string& newName,
	const string& newPrefix, int newNo, double newUnits)
{
	courseName = newName;
	coursePrefix = newPrefix;
	courseNo = newNo;
	courseUnits = newUnits;
}

// getCourseName
string Course::getCourseName() const
{
	return courseName;
}

// getCoursePrefix
string Course::getCoursePrefix() const
{
	return coursePrefix;
}

// getCourseNo
int Course::getCourseNo() const
{
	return courseNo;
}

// getCourseUnits
double Course::getCourseUnits() const
{
	return courseUnits;
}

// printCourseInfo
void Course::printCourseInfo() const
{
	cout << coursePrefix << " " 
		<< courseNo << fixed << setprecision(2) << setw(8) << courseUnits;
}

bool Course::operator<(const Course& rhs) const
{
	return (coursePrefix.at(0) < rhs.coursePrefix.at(0));
}

// destructor;
Course::~Course()
{

}