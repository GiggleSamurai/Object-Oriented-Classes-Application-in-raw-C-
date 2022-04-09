#pragma once
/*
    Author: Louis Wong
    File: student.h
*/
#include <iostream>
#include "degree.h"
using namespace std;

class Student {
    //All Variables
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days2CC[3]; //array of number of days to complete each course
    DegreeProgram degreeprogram;


public:
    //Constructor
    Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, DegreeProgram Degreeprogram);

    //Setter Function
    void SETstudentID(string StudentID);
    void SETfirstName(string FirstName);
    void SETlastName(string LastName);
    void SETemailAddress(string EmailAddress);
    void SETage(int Age);
    void SETdays2CC(int DaysInCourse1, int DaysInCourse2, int DaysInCourse3);
    void SETdegreeprogram(DegreeProgram Degreeprogram);

    //Getter Function
    string GETstudentID();
    string GETfirstName();
    string GETlastName();
    string GETemailAddress();
    int GETage();
    int* GETdays2CC();
    DegreeProgram GETdegreeprogram();

    //Print Object    
    void print();

    //Destructor
    ~Student();
};
