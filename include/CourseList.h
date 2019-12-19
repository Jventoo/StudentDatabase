/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"
#include <vector>

class CourseList
{
public:
	CourseList();

	CourseList(const std::string& pref);

	CourseList(const CourseList& otherList);

	CourseList& operator=(const CourseList& rhs);

	void setListPrefix(const std::string& pref);

	void addCourse(const Course& newCourse);

	void printCourses() const;

	std::string getListPrefix() const { return coursePref; }

	std::vector<Course> getCourseList() const { return courseList; }

	double getCourseUnits(const std::string& pref, int num) const;

	~CourseList();

private:
	std::vector<Course> courseList;	
	std::string coursePref;

	static const int CAP;
};

#endif
