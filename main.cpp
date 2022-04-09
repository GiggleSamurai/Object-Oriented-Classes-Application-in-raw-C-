// C867_Project_Louis_Wong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;
int main() {
    //Input Student Data Table
    string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Louis,Wong ,lwong33@my.wgu.edu,29,10,15,10,SOFTWARE"
    };

    //Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    printme();

    //Create an instance of the Roster class called classRoster.
    Roster classRoster;

    //Add each student to classRoster.
    classRoster.parseNadd(studentData);

    //Convert the Pseudo Code 

    //classRoster.printAll();
    classRoster.printAll();

    //classRoster.printInvalidEmails();
    classRoster.printInvalidEmails();

    //loop through classRosterArray and for each element:
    for (int i = 0; i < 5; i++) {
        string id = classRoster.classRosterArray[i]->GETstudentID(); //Use an accessor (i.e., getter) 

        //classRoster.printAverageDaysInCourse(/*current_object's student id*/);
        classRoster.printAverageDaysInCourse(id);
    }

    //classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.printByDegreeProgram(SOFTWARE);

    //classRoster.remove("A3");
    classRoster.remove("A3");

    //classRoster.printAll();
    classRoster.printAll();

    //expected: the above line should print a message saying such a student with this ID was not found.
    classRoster.remove("A3");

    //Destructor is automatically called release the memory that was allocated dynamically in Roster.
    return 0;
}