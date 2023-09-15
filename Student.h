#ifndef Student_H
#define Student_H

#include <iostream>
#include <string>
#include "degree.h"


using namespace std;



class Student {
	public: 
		void SetStudentID(string sID);
		void SetFirstName(string ftName);
		void SetLastName(string ltName);
		void SetEmailAddress(string eAddress);
		void SetAge(int studentAge);
		void SetCourseDays(int daysForCourses[]);
		void SetDegreeProgram(DegreeProgram degreeProg);

	// Above are mutators, below accessors	

		string GetStudentID() const;
		string GetFirstName() const;
		string GetLastName() const;
		string GetEmailAddress()const;
		int GetAge() const;
		int* GetCourseDays() const;
		DegreeProgram GetDegreeProgram() const;
		void Print() const;

		// Constructor
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[], DegreeProgram degreeProgram); // finish definition
		~Student(); //Finish definition
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age = 0;
	int  numCourses = 3;
	int* courseDays;
	DegreeProgram degreeProgram;
};

#endif