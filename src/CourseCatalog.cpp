/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#include "include/CourseCatalog.h"

using namespace std;

CourseCatalog::CourseCatalog()
{
}

void CourseCatalog::addDepartment(const string& pref)
{
	CourseList list(pref);
	courseCatalog.insert(make_pair(pref, list));
}

void CourseCatalog::addCourseList(const CourseList& list)
{
	courseCatalog.insert(make_pair(list.getListPrefix(), list));
}

void CourseCatalog::addCourse(const Course& newCourse)
{
	auto tempPref = newCourse.getCoursePrefix();

	if (courseCatalog.find(tempPref) == courseCatalog.end())
		addDepartment(tempPref);

	courseCatalog.at(tempPref).addCourse(newCourse);
}

bool CourseCatalog::searchCourse(const string& pref, int num) const
{
	auto list = courseCatalog.at(pref);

	for (const auto& i : list.getCourseList())
	{
		if (i.getCoursePrefix() == pref)
			return true;
	}
	
	return false;
}

void CourseCatalog::printCoursesByDept(const string& pref) const
{
	courseCatalog.at(pref).printCourses();
}

void CourseCatalog::printAllCourses() const
{
	for (const auto& i : courseCatalog)
	{
		cout << "\n   * " << i.first << " DEPARTMENT *" << endl;
		i.second.printCourses();
	}
	cout << endl;
}

CourseCatalog::~CourseCatalog()
{

}