/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#include <sstream>
#include "ExceptionHandler.h"

using namespace std;

int ExceptionHandler::validateSelection(const string& input) const
{
	if (input.length() > 1)
		return 0;
	else
	{
		int id = input[0] - 48;
		if (id >= 1 && id <= 8)
			return id;
		else
			return 0;
	}
}

bool ExceptionHandler::lastNameValid(string& input) const
{
	for (auto it = input.begin(); it != input.end(); ++it) 
		if (isspace(*it)) 
			return false;

	input[0] = toupper(input[0]);
	for_each(input.begin() + 1, input.end(),
			[](char& c) { c = ::tolower(c); });

	return true;
}

bool ExceptionHandler::validateID
	(const string& input, int& id) const
{
	auto iter = input.begin();
	while (iter != input.end() && isdigit(*iter))
		++iter;
	
	if (input.length() < 6 || input.length() > 6
		|| iter != input.end())
	{
		cout << "Invalid input. ID is 6 digits. Try again." << endl;
		return false;
	}

	id = stoi(input);
	return true;
}

bool ExceptionHandler::validateCoursePrefix(string& input) const
{
	if (input.length() != 3)
	{
		cout << "Invalid input. Course prefix is 3 letters. "
			<< "Try again." << endl;
		input = "";
		return false;
	}
	else
	{
		for_each(input.begin(), input.end(),
			[](char& c) { c = ::toupper(c); });
		return true;
	}
}

bool ExceptionHandler::validateCourseNo
	(const string& input, int& courseNo) const
{
	int temp = 0;
	auto stream = istringstream(input);

	stream >> temp;
	
	if (stream.fail() || !stream.eof() || input.length() != 3)
	{
		cout << "Invalid input. Course number is 3 digits. "
			<< "Try again." << endl;
		return false;
	}
	else
	{
		courseNo = temp;
		return true;
	}
}

bool ExceptionHandler::validateGPA(const string& input,
	double& studentGPA) const
{
	double temp = 0.0;
	auto stream = istringstream(input);

	stream >> temp;

	if (!stream.fail() && stream.eof())
	{
		if (temp < 0.0 || temp > 5.0)
		{
			cout << "Invalid input. GPA supplied must be between 0.0-5.0."
				<< " Try again." << endl;
			return false;
		}
		else
		{
			studentGPA = temp;
			return true;
		}
	}
	else
	{
		cout << "Invalid input. Must be a double. Try again." << endl;
		return false;
	}
}

bool ExceptionHandler::validateUnits(const string& input,
	int& studentUnits) const
{
	auto iter = input.begin();
	while (iter != input.end() && isdigit(*iter))
		++iter;

	if (input.length() < 1 || input.length() > 3
		|| iter != input.end())
	{
		cout << "Invalid input. Units supplied must be between 0 and 999." 
			<< " Try again." << endl;
		return false;
	}

	studentUnits = stoi(input);
	return true;
}