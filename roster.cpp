#include "roster.h"
#include <string>
#include <iostream>
#include "student.h"



using namespace std;
// constructor
Roster::Roster() {
	
	

	
}



// This function is responsible for parsing student data from a string and then creating new Student Objects.
void Roster::ParseStudentData(const string studentData[], int nStudents) {


	
	for (int i = 0; i < nStudents; i++)
	{


		size_t rhs = studentData[i].find(",");
		string studentID = studentData[i].substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string firstName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string lastName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string studentEmail = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int age = stoi(studentData[i].substr(lhs, rhs - lhs)); //stoi to convert to integer

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int setfirstDay = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int setSecondDay = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int setThirdDay = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string degreeString = studentData[i].substr(lhs, rhs - lhs);
		
		DegreeProgram TheDegree = SECURITY;

		int Oopsie = 3675409;
	
			if (degreeString == "NETWORK") { TheDegree = DegreeProgram::NETWORK; }
			if (degreeString == "SOFTWARE") { TheDegree = DegreeProgram::SOFTWARE; }

			Add(studentID, firstName, lastName, studentEmail, age, setfirstDay, setSecondDay, setThirdDay, TheDegree);

	}
	
}
// A function to add a student object to the classRosterArray
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	const int numStudents = 5;

	int courseDays[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[craIndex++] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);


		


}
// A function to remove a student object from the classRosterArray
void Roster::Remove(string studentID) {
	bool foundYou = false;
	bool foundMe = false;

	for (int i = 0; (i < numStudents) && !foundYou; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			Student* classRosterA[5];
			classRosterA[0] = classRosterArray[0];
			classRosterA[1] = classRosterArray[1];
			classRosterA[2] = classRosterArray[3];
			classRosterA[3] = classRosterArray[4];

			for (int i = 0; i < 4; i++) {
				classRosterArray[i] = classRosterA[i];
			}
			numStudents--;
			foundYou = true;
		}

	}
		
		if (foundYou == true) {

			cout << "Student ID " << studentID << " has been located and removed." << endl;
		}
		else
			cout << "Student ID does not exist." << endl;
	

}
//Prints all elements in the classRosterArray
void Roster::printAll() {

	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i]->Print();
	}


}
//A function to print an individual students average number of days for all courses. Takes the student's ID for a parameter.
void Roster::PrintAverageDaysInCourse(string studentID) {
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			int* courseDays = classRosterArray[i]->GetCourseDays();
			cout << "This student, " << studentID << ", has an average of " << (courseDays[0]
				+ courseDays[1] + courseDays[2]) / 3 << " days for their courses" << endl;
		}
	}

}
//A function which will identify emails that are not valid in the system. I.E. No @ symbol, has spaces or does not have a period in it.
void Roster::PrintInvalidEmails() {
	for (int i = 0; i < numStudents; ++i) {
		string studentEmail = classRosterArray[i]->GetEmailAddress();
		size_t atSym = studentEmail.find('@');
		
		if (atSym == string::npos) {
			cout << "Error! This email is invalid, lacking an @ symbol!!!	" << studentEmail << endl;
		}

		size_t per = studentEmail.find('.');

		if (per == string::npos) {
			cout << "Error! This email is invalid, lacking a period!	" << studentEmail << endl;
		}

		if (studentEmail.find(' ') != string::npos) {
			cout << "Error! There is a space in this email!!!   " << studentEmail << endl;
		}
	}

}
// Prints all students that are from a particular degree program.
void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram)
			classRosterArray[i]->Print();
	}


}

Roster::~Roster() {
	delete[] classRosterArray;
}

