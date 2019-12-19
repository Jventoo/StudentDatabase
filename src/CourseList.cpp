/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#include "include/CourseList.h"

using namespace std;

// CourseList
CourseList::CourseList()
{
	courseList = new list<Course>;
}

// Copy constructor
CourseList::CourseList(const CourseList& rhs)
{
	*courseList = *rhs.courseList;
}

// addCourse
void CourseList::addCourse(const Course& newCourse)
{
	courseList->push_back(newCourse);
}

// getCourseUnits
double CourseList::getCourseUnits(const string& pref, int num) const
{
	for (const auto& i : *courseList)
	{
		if (i.getCoursePrefix() == pref && i.getCourseNo() == num)
			return i.getCourseUnits();
	}

	return -1;
}

// searchCourse
bool CourseList::searchCourse(const string& pref, int num) const
{
	for (const auto& i : *courseList)
	{
		if (i.getCoursePrefix() == pref && i.getCourseNo() == num)
			return true;
	}

	return false;
}

void CourseList::printCoursesByDept(const string& pref, int num) const
{

}

void CourseList::printAllCourses() const
{

}


// overloaded operator=
CourseList& CourseList::operator=(const CourseList& rhs)
{
	if (this != &rhs)
	{
		*courseList = *rhs.courseList;
	}
	else
		cerr << "Cannot self assign";

	return *this;
}

void CourseList::destroyCourseList()
{
	courseList->clear();
}

// destructor
CourseList::~CourseList()
{
	delete courseList;
	courseList = nullptr;
}