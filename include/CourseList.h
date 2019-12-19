/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

#include <list>

class CourseList
{
public:
	// CourseList
	CourseList();

	// Copy constructor
	CourseList(const CourseList& otherList);

	void addCourse(const Course& newCourse);

	double getCourseUnits(const std::string& pref, int num) const;

	// See if there is a course in the list with the given prefix and number
	bool searchCourse(const std::string& pref, int num) const;

	void printCoursesByDept(const std::string& pref, int num) const;

	void printAllCourses() const;

	CourseList& operator=(const CourseList& rhs);

	// Remove all nodes (courses)
	void destroyCourseList();

	// destructor
	~CourseList();

private:
	std::list<Course>* courseList;	
};

#endif
