#include "roster.h"
#include <iostream>
#include <string>

/*
    Author: Louis Wong
    File: roster.cpp
*/

using namespace std;

//Add student to pointer array
void Roster::add(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, DegreeProgram Degreeprogram) {
    for (int i = 0; i < 4; i++) {
        if (classRosterArray[i] == 0) {
            classRosterArray[i] = new Student(StudentID, FirstName, LastName, EmailAddress, Age, DaysInCourse1, DaysInCourse2, DaysInCourse3, Degreeprogram);
            cout << classRosterArray[i]->GETstudentID() << " Student Added to Class." << endl; //working
            break;
        }
    }

}

//Function to set student to null.
void Roster::remove(string StudentID) {
    for (int i = 0; i < 4; i++) {
        if (classRosterArray[i]->GETstudentID() == StudentID) {
            cout << classRosterArray[i]->GETstudentID() << " Student Removed!" << endl; //working

            //Move one up, set last to NULL
            for (int j = i; j < 4; j++) {
                if (j != 4) {
                    classRosterArray[j] = classRosterArray[j + 1];
                }
                else { classRosterArray[4] = nullptr; }
            }
            return;

        }

    }
    cout << "Error: " << StudentID << " Student Not Found." << endl;
}

//Print all Student:
void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        //Only print Unique Data
        if (i == 0) {
            classRosterArray[i]->print();
        }
        else if (classRosterArray[i]->GETstudentID() != classRosterArray[i-1]->GETstudentID()) {
            classRosterArray[i]->print();
        }

    }
}

//Prints a student’s average number of days in the three courses        
void Roster::printAverageDaysInCourse(string StudentID) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->GETstudentID() == StudentID) {
            cout << "Avg. Days in Course:\t" << (classRosterArray[i]->GETdays2CC()[0] + classRosterArray[i]->GETdays2CC()[1] + classRosterArray[i]->GETdays2CC()[2]) / 3.0 << endl;
            return;
        }

    }
    cout << "Error: " << StudentID << " Student Not Found." << endl;
}
//Prints All Invalid Emails     
void Roster::printInvalidEmails() {
    bool allvaildCheck = 1;
    for (int i = 0; i < 4; i++) {
        string email = classRosterArray[i]->GETemailAddress();
        bool a = (email.find('@') != string::npos);
        bool b = (email.find('.') != string::npos);
        bool c = (email.find(' ') != string::npos);

        if (a == 0 || b == 0 || c == 1) {
            allvaildCheck = 0;
            cout << email << endl;
        }
    }
    //All Vaild Statment
    if (allvaildCheck == 1) {
        cout << "All emails are vaild." << endl;
    }
}
//Pints out student information for a degree program

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->GETdegreeprogram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}


void Roster::parseNadd(string studentData[]) {
    for (int i = 0; i < 5; i++) {
        int index = i;
        //Parsing
        int a = studentData[index].find(",");
        int b = studentData[index].find(",", a + 1);
        int c = studentData[index].find(",", b + 1);
        int d = studentData[index].find(",", c + 1);
        int e = studentData[index].find(",", d + 1);
        int f = studentData[index].find(",", e + 1);
        int g = studentData[index].find(",", f + 1);
        int h = studentData[index].find(",", g + 1);
        int k = studentData[index].find(",", h + 1);

        //Input Data
        string id = studentData[index].substr(0, a);
        string fn = studentData[index].substr(a + 1, b - a - 1);
        string ln = studentData[index].substr(b + 1, c - b - 1);
        string em = studentData[index].substr(c + 1, d - c - 1);
        int age = stoi(studentData[index].substr(d + 1, e - d - 1));
        int cc1 = stoi(studentData[index].substr(e + 1, f - e - 1));
        int cc2 = stoi(studentData[index].substr(f + 1, g - f - 1));
        int cc3 = stoi(studentData[index].substr(g + 1, h - g - 1));
        string maj = studentData[index].substr(h + 1, k - h - 1);
        DegreeProgram DP;

        //if statment to convert string to value
        if (maj == "SECURITY") { DP = SECURITY; }
        else if (maj == "NETWORK") { DP = NETWORK; }
        else if (maj == "SOFTWARE") { DP = SOFTWARE; }

        //Add student to array
        for (int i = 0; i < 5; i++) {
            if (classRosterArray[i] == 0) {
                classRosterArray[i] = new Student(id, fn, ln, em, age, cc1, cc2, cc3, DP);
                cout << classRosterArray[i]->GETstudentID() << " Student Added to Class." << endl; //working
                break;
            }
        }
    }
}
Roster::~Roster() {
    
    cout << "Object Roster Destructed." << endl;

    //Manually called sub-class Student Destructor
    for (int i = 0; i < 5; i++) {
        classRosterArray[i]->~Student();
    }
}

//Function to print my course title, the programming language used, your WGU student ID, and your name.
void printme() {
    cout << "Scripting and Programming - Applications  C867\tC++\t009457081\tLouis Wong" << endl;
}
