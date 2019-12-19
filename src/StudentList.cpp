/*
	Vento, Jack

	CS A250 - Fall 2019

	Project 2
*/

#include "include/StudentList.h"

using namespace std;

const int StudentList::CAP = 30;

// default constructor
StudentList::StudentList()
{
	studentList.reserve(CAP);
}

StudentList::StudentList(int newCap)
{
	studentList.reserve(newCap);
}

StudentList::StudentList(const StudentList& otherVect)
{
	studentList = otherVect.studentList;
}

StudentList& StudentList::operator=(const StudentList& otherVect)
{
	if (this != &otherVect)
	{
		studentList = otherVect.studentList;
	}
	else
		cerr << "Cannot self assign!";

	return *this;
}

// addStudent
void StudentList::addStudent(const Student& newStudent)
{
	if (studentList.size() == studentList.capacity())
		studentList.resize(studentList.size() + CAP);

	studentList.push_back(newStudent);
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return static_cast<int>(studentList.size());
}

// printStudentByID
void StudentList::printStudentByID(int ID) const
{
	if (getNoOfStudents())
	{
		bool found = false;
		auto search = studentList.cbegin(),
			end = studentList.cend();

		while (search != end && !found)
		{
			if (search->getID() == ID)
			{
				found = true;
				search->printStudentInfo();
			}

			++search;
		}

		if (!found)
		{
			cout << "No student with ID " << ID
				<< " found in the list." << endl;
		}
	}
	else
		cerr << "List is empty.";
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& pref, int num) const
{
	if (getNoOfStudents())
	{
		for (auto const &iter : studentList)
		{
			if (iter.getNumberOfCourses())
			{
				if (iter.courseIsCompleted(pref, num))
					iter.printStudent();
			}
		}
	}
	else
		cerr << "List is empty.";
}

// printStudentByName
void StudentList::printStudentsByName(const string& lastName) const
{
	if (getNoOfStudents())
	{
		bool found = false;
		for (auto const& iter : studentList)
		{
			if (iter.getLastName() == lastName)
			{
				iter.printStudent();
				found = true;
			}
		}

		if (!found)
		{
			cout << "No student with last name " << lastName
				<< " is in the list." << endl;
		}
	}
	else
		cerr << "List is empty.";
}

// printStudentsOnHold
void StudentList::printStudentsOnHold() const
{
	if (getNoOfStudents())
	{
		bool found = false;
		for (auto const& iter : studentList)
		{
			if (!iter.isTuitionPaid())
			{
				iter.printStudentInfo();
				found = true;
			}
		}

		if (!found)
			cout << "There are no students on hold" << endl;
	}
	else
		cerr << "No students in the list.";
}

// printAllStudents
void StudentList::printAllStudents() const
{
	if (getNoOfStudents())
	{
		for (auto const& iter : studentList)
			iter.printStudentInfo();
	}
	else
		cerr << "List is empty.";
}

void StudentList::printStudentsByGPA(double lowerBound, 
	double upperBound) const
{
	if (getNoOfStudents())
	{
		bool found = false;

		for (const auto& search : studentList)
		{
			double GPA = search.getGpa();
			if (GPA >= lowerBound && GPA <= upperBound
				&& search.isTuitionPaid())
			{
				found = true;
				search.printStudentInfo();
			}
		}

		if (!found)
		{
			cout << "No students in this range." << endl;
		}
	}
	else
		cerr << "List is empty.";
}

// printStudentsByUnits
void StudentList::printStudentsByUnits(int lowerBound, 
	int upperBound) const
{
	if (getNoOfStudents())
	{
		bool found = false;
		double lower = static_cast<double>(lowerBound), 
			upper = static_cast<double>(upperBound);

		for (const auto& search : studentList)
		{
			double units = search.getUnitsCompleted();
			if (units >= lower && units <= upper)
			{
				found = true;
				search.printStudentInfo();
			}
		}

		if (!found)
		{
			cout << "No students in this range." << endl;
		}
	}
	else
		cerr << "List is empty.";
}

// destructor
StudentList::~StudentList()
{
}