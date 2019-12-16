/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H

#include <iostream>
#include <string>
#include <algorithm>

class ExceptionHandler
{
public:
	ExceptionHandler() {};
	~ExceptionHandler() {};

	int validateSelection(const std::string& input) const;

	bool lastNameValid(std::string& input) const;

	bool validateID(const std::string& input, int& id) const;

	bool validateCoursePrefix(std::string& input) const;

	bool validateCourseNo(const std::string& input, 
		int& courseNo) const;

	bool validateGPA(const std::string& input,
		double& studentGPA) const;

	bool validateUnits(const std::string& input,
		int& studentUnits) const;
};

#endif
