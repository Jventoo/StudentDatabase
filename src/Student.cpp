/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#include "include/Student.h"

using namespace std;

// default constructor
Student::Student()
{
	studentID = 0;
	totalCourses = 0;
	tuitionWasPaid = false;
}

// setStudentInfo
void Student::setStudentInfo(const string& newFirst,
	const string& newLast, int newID, bool newPaid,
	const multimap<Course, char>& newCompleted)
{
	setName(newFirst, newLast);

	studentID = newID;
	totalCourses = static_cast<int>(newCompleted.size());
	tuitionWasPaid = newPaid;
	coursesCompleted = newCompleted;
}

// getID
int Student::getID() const
{
	return studentID;
}

// getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return totalCourses;
}

// getUnitsCompleted
double Student::getUnitsCompleted() const
{
	double units = 0.0;

	for (auto i : coursesCompleted)
	{
		units += i.first.getCourseUnits();
	}

	return units;
}

// getGpa
double Student::getGpa() const
{
	double gradePtsEarned = 0.0;
	double unitsAttempted = 0.0;

	for (auto i : coursesCompleted)
	{
		double courseUnits = i.first.getCourseUnits();
		unitsAttempted += courseUnits;

		switch (i.second)
		{
		case 'A': gradePtsEarned += 4.0 * courseUnits; break;
		case 'B': gradePtsEarned += 3.0 * courseUnits; break;
		case 'C': gradePtsEarned += 2.0 * courseUnits; break;
		case 'D': gradePtsEarned += 1.0 * courseUnits; break;
		case 'F': gradePtsEarned += 0.0;			   break;
		default:
			cerr << "Invalid Course Grade";
		}
	}

	return (gradePtsEarned / unitsAttempted);
}

// isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

// courseIsCompleted
bool Student::courseIsCompleted(
	const string& coursePref, int courseNo) const
{
	auto begin = coursesCompleted.cbegin();
	auto end = coursesCompleted.cend();

	while (begin != end)
	{
		if (begin->first.getCoursePrefix() == coursePref
			&& begin->first.getCourseNo() == courseNo)
			return true;

		++begin;
	}

	return false;
}

// printStudent
void Student::printStudent() const
{
	cout << studentID << " - ";
	printName();
}

// printStudentInfo
void Student::printStudentInfo() const
{
	auto oldSettings = cout.flags();

	cout << "Student Name: ";
	printName();

	cout << "\nStudent ID: " << studentID << endl;
	cout << "Number of courses completed: " << totalCourses << endl;

	cout << "\nCourse" << setw(9) << "Units"
		<< setw(10) << "Grade" << endl;

	auto begin = coursesCompleted.cbegin();
	auto end = coursesCompleted.cend();
	while (begin != end)
	{
		begin->first.printCourseInfo();

		if (tuitionWasPaid)
			cout << setw(8) << begin->second << endl;
		else
			cout << setw(10) << "***" << endl;

		++begin;
	}

	cout.flags(oldSettings);
	cout << "\nTotal number of unit hours: " 
		<< static_cast<int>(getUnitsCompleted()) << endl;

	if (tuitionWasPaid)
	{
		cout << fixed << setprecision(2) << "Current Term GPA: "
			<< getGpa() << endl;
	}
	else
	{
		cout << "*** Grades are being held for not paying the tuition. ***"
			<< endl;
	}

	cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
}

// destructor
Student::~Student()
{

}