/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#ifndef COURSECATALOG_H
#define COURSECATALOG_H

#include "CourseList.h"
#include <unordered_map>

class CourseCatalog
{
public:
	CourseCatalog();

	void addDepartment(const std::string& pref);

	void addCourseList(const CourseList& list);

	void addCourse(const Course& newCourse);

	// See if there is a course with the supplied course num in the list w/ the given prefix
	bool searchCourse(const std::string& pref, int num) const;

	void printCoursesByDept(const std::string& pref) const;

	void printAllCourses() const;

	~CourseCatalog();

private:
	std::unordered_map<std::string, CourseList> courseCatalog;
};

#endif