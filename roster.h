#ifndef roster_h
#define roster_h

#include <iostream>
#include  <string>
#include "student.h"
#include "degree.h"


using namespace std;

class Roster {
public:
    void ParseStudentData(const string studentData[], int nStudents);
    void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void Remove(string studentID);
    void printAll();
    void PrintAverageDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
    Roster(); 
    ~Roster(); 
private:
    Student* classRosterArray[5];
    int numStudents = 5;
    int craIndex = 0;





};


#endif