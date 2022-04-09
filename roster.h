#pragma once

/*
    Author: Louis Wong
    File: roster.h
*/

#include <iostream>
#include "student.h"
#include "degree.h"

using namespace std;
//class RosterArray
class Roster {
public:
    //Pointers array;
    Student* classRosterArray[5] = {};

    //Function to add student to the pointerRosterArray
    void add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, DegreeProgram Degreeprogram);

    //Function to set student to null.
    void remove(string StudentID);

    //Print all Student:
    void printAll();

    //Prints a student’s average number of days in the three courses        
    void printAverageDaysInCourse(string StudentID);

    //Prints All Invalid Emails     
    void printInvalidEmails();

    //Parse & Add Function
    void parseNadd(string studentData[]);

    //Pints out student information for a degree program
    void printByDegreeProgram(DegreeProgram degreeProgram);

    // Destructor
    ~Roster();
};

void printme();