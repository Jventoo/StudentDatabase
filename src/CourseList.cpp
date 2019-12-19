/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#include "include/CourseList.h"

using namespace std;

const int CourseList::CAP = 10;

CourseList::CourseList()
{
	courseList.reserve(CAP);
}

CourseList::CourseList(const std::string& pref)
{
	courseList.reserve(CAP);
	coursePref = pref;
}

CourseList::CourseList(const CourseList& rhs)
{
	courseList = rhs.courseList;
}

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

void CourseList::setListPrefix(const std::string& pref)
{
	coursePref = pref;
}

void CourseList::addCourse(const Course& newCourse)
{
	if (courseList.size() == courseList.capacity())
		courseList.reserve(courseList.size() + CAP);

	courseList.push_back(newCourse);
}

void CourseList::printCourses() const
{
	for (const auto& i : courseList)
	{
		cout << "     ";
		i.printCourseInfo();
		cout << endl;
	}
	cout << endl;
}

double CourseList::getCourseUnits(const string& pref, int num) const
{
	for (const auto& i : courseList)
	{
		if (i.getCoursePrefix() == pref && i.getCourseNo() == num)
			return i.getCourseUnits();
	}

	return -1;
}

CourseList::~CourseList()
{
}