#include "student.h"
#include "degree.h"

/*
    Author: Louis Wong
    File: student.cpp
*/

#include <iostream>


using namespace std;

//Constructor
Student::Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, DegreeProgram Degreeprogram) {
    studentID = StudentID;
    firstName = FirstName;
    lastName = LastName;
    emailAddress = EmailAddress;
    age = Age;
    days2CC[0] = DaysInCourse1;
    days2CC[1] = DaysInCourse2;
    days2CC[2] = DaysInCourse3;
    degreeprogram = Degreeprogram;
    cout << "New Student, " << firstName << " " << lastName << " is created." << endl;
};

//Setter Function
void Student::SETstudentID(string StudentID) { studentID = StudentID; };
void Student::SETfirstName(string FirstName) { firstName = FirstName; };
void Student::SETlastName(string LastName) { lastName = LastName; };
void Student::SETemailAddress(string EmailAddress) { emailAddress = EmailAddress; };
void Student::SETage(int Age) { age = Age; };
void Student::SETdays2CC(int DaysInCourse1, int DaysInCourse2, int DaysInCourse3) {
    days2CC[0] = DaysInCourse1;
    days2CC[1] = DaysInCourse2;
    days2CC[2] = DaysInCourse3;
};
void Student::SETdegreeprogram(DegreeProgram Degreeprogram) { degreeprogram = Degreeprogram; };

//Getter Function
string Student::GETstudentID() { return studentID; };
string Student::GETfirstName() { return firstName; };
string Student::GETlastName() { return lastName; };
string Student::GETemailAddress() { return emailAddress; };
int Student::GETage() { return age; };
int* Student::GETdays2CC() { return days2CC; };
DegreeProgram Student::GETdegreeprogram() { return degreeprogram; };

//Print Object    
void Student::print() {
    cout << studentID << "\t";
    cout << "First_Name: " << firstName << "\t";
    cout << "Last_Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {" << days2CC[0] << "," << days2CC[1] << "," << days2CC[2] << "}\t";

    //Switch statment to interpret the enum result 
    string caseresult;
    int enumValue;
    enumValue = degreeprogram;

    switch (enumValue) {
    case 0:
        caseresult = "SECURITY";
        break;
    case 1:
        caseresult = "NETWORK";
        break;
    case 2:
        caseresult = "SOFTWARE";
        break;
    default: //Default output if everything is invaild
        caseresult = "UNKONWN";
    }
    cout << "Degree Program: " << caseresult << endl;
}

Student::~Student() {
    cout << "Object Student Destructed." << endl;;
};