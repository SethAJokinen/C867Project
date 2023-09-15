#include <iostream>
#include <string>

using namespace std;
#include "student.h"




//Constructor 
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[3], DegreeProgram degreeProgram) {

    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->courseDays = new int[numCourses];
    for (int i = 0; i < numCourses; i++) {
        this->courseDays[i] = courseDays[i];
    }
    this->degreeProgram = degreeProgram;
}
//constructor
Student::Student() {
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";
    age = 0;
   

}

// destructor
Student::~Student() {
    delete[] courseDays;
};

void Student::SetStudentID(string sID) {
    studentID = sID;
    return;
}

void Student::SetFirstName(string ftName) {
    firstName = ftName;
    return;

}

void Student::SetLastName(string ltName) {
    lastName = ltName;
    return;

}

void Student::SetEmailAddress(string eAddress) {
    emailAddress = eAddress;
    return;
}

void Student::SetAge(int studentAge) {
    age = studentAge;
    return;
}

void Student::SetCourseDays(int daysForCourses[]) {
    
    for (int i = 0; i < numCourses; i++) {
        courseDays[i] = daysForCourses[i];
    }
}

void Student::SetDegreeProgram(DegreeProgram degreeProg) {
    degreeProgram = degreeProg;
    return;
}
// Mutators above this point. Accessors Below!

string Student::GetStudentID()const {
    return studentID;

}

string Student::GetFirstName()const {
    return firstName;


}

string Student::GetLastName() const {
    return lastName;


}

string Student::GetEmailAddress() const {
    return emailAddress;

}

 int Student::GetAge() const {
     return age;

}

int* Student::GetCourseDays() const {
    return courseDays;

}

DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;

}
//PrintFunction
void Student::Print() const {
    cout << "Student ID: "  << studentID << "   First Name: " << firstName << "    Last Name: "
        << lastName << "    " << "Age: " << age << "    "  << "Email: " << emailAddress << "    " << "daysInCourse: " << "{";
      for (int i = 0; i < numCourses; i++) {

          cout << courseDays[i];
          if (i != numCourses - 1)
              cout << ",";
    }
       
        
      cout << "}" << "    " << "Degree Program: ";
      
      if (degreeProgram == SECURITY)
          cout << "Security";
      else if (degreeProgram == NETWORK)
          cout << "Network";
      else
          cout << "Software";
          
          
       cout << "." << endl;

       return;
}

