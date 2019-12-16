# StudentDatabase
 
Student Database is a C++ console application focused on allowing college counselors to keep track of their students' various levels of success and relative trajectories. 

## Format

Courses in resources/courses.txt follow the following syntax: NAME PREFIX COURSE-NUM UNITS

Example: Chemistry CHM 348 4

Student entries in resources/student.txt are separated by an empty line and following the following syntax:

FIRST LAST 6-digit-ID TUITION-PAID NUM-COURSES-COMPLETED

COURSE1

COURSE2

...COURSEN


Example: 

Bruce Wayne 123456 Y 5

Chemistry CHM 348 4 B

ComputerScie CSC 201 4 B

Math MTH 345 4 A

English ENG 101 3 A

History HIS 101 3 A


Steven Rogers 789456 Y 3

Chemistry CHM 348 4 A

ComputerScie CSC 201 4 B

History HIS 101 3 A



**Both files are terminated by the "END" flag**

## Documentation
The program uses Course Lists and Student Lists to track both courses and students alike. 


Course Lists are compromised of courses, where courses have a three letter prefix, a 3 digit number, and number of units for that course. 


Student Lists are compromised of students and students are children of people. While people only have a first and last name, students have those, a 6 digit ID number, a boolean for whether tuition has been paid (if it has not, their grades will be withheld), and a map containing their courses completed (key = course completed, value = grade in single letter format without any + or -). 


The input handler handles input from courses.txt and students.txt at the beginning of the program. Exception handler handles user input as the program runs.


The menu options are self-explanatory consisting largely of search and information functions counselors need access to.

## Developed by Jack Vento
