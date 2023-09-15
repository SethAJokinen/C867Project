// SethJC867PA.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "roster.h"

int main()
{

    cout << "C867, C++, Seth Andrew Jokinen" << endl << endl;


    const string studentData[5] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
       "A5,Seth,Jokinen,sjokine@wgu.edu,25,25,26,27,SOFTWARE"
    };

    const int nStudents = 5;


    

    Roster classRoster;

    classRoster.ParseStudentData(studentData, 5); //This makes use of a separate ADD function to add students to roster!

    // Prints all current students
    cout << "Here are our current students! :" << endl;
    classRoster.printAll(); //
    cout << endl;
    cout << endl;

    // Prints all invalid emails
    cout << "These emails are invalid!" << endl;
    classRoster.PrintInvalidEmails();
    cout << endl;

    // Prints average number of days spent in course.
    cout << "Average days spent in their courses: " << endl;
    classRoster.PrintAverageDaysInCourse("A1");
    classRoster.PrintAverageDaysInCourse("A2");
    classRoster.PrintAverageDaysInCourse("A3");
    classRoster.PrintAverageDaysInCourse("A4");
    classRoster.PrintAverageDaysInCourse("A5");
    cout << endl;

    // Prints all Software Degree students
    cout << "Here are our Software Experts!" << endl;
    classRoster.PrintByDegreeProgram(SOFTWARE);

    cout << endl;

    // Delete's student that has the ID "A3"
    cout << "Deleting A3" << endl;
    classRoster.Remove("A3");
    
    cout << endl;
    //Prints all students again.
    classRoster.printAll();

    //Attempts to remove student A3 again. Should state that they do not exist due to being deleted prior.
    cout << endl << "Deleting A3" << endl;
    classRoster.Remove("A3");

    classRoster.~Roster();
    
    cout << endl;

  
}

