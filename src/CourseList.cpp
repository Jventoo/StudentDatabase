/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#include "CourseList.h"

using namespace std;

const int CourseList::CAP = 10;

// CourseList
CourseList::CourseList()
{
	courseList.reserve(CAP);
}

// Overloaded constructor
CourseList::CourseList(int newCapacity)
{
	courseList.reserve(newCapacity);
}


// Copy constructor
CourseList::CourseList(const CourseList& rhs)
{
	courseList = rhs.courseList;
}

// addCourse
void CourseList::addCourse(const Course& newCourse)
{
	if (courseList.size() == courseList.capacity())
		courseList.reserve(courseList.capacity() * 2);

	courseList.push_back(newCourse);
}

// getCourseUnits
double CourseList::getCourseUnits(const string& pref, int num) const
{
	for (auto i : courseList)
	{
		if (i.getCoursePrefix() == pref && i.getCourseNo() == num)
			return i.getCourseUnits();
	}

	return -1;
}

// searchCourse
bool CourseList::searchCourse(const string& pref, int num) const
{
	for (auto i : courseList)
	{
		if (i.getCoursePrefix() == pref && i.getCourseNo() == num)
			return true;
	}

	return false;
}

// overloaded operator=
CourseList& CourseList::operator=(const CourseList& rhs)
{
	if (this != &rhs)
	{
		courseList = rhs.courseList;
	}
	else
		cerr << "Cannot self assign";

	return *this;
}

// destructor
CourseList::~CourseList()
{
}