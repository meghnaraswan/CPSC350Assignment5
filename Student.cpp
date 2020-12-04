#include "Student.hpp"
#include "Faculty.hpp"
#include <iostream>
#include <fstream>
#include <string>

//default constructor
Student::Student(){
    studentID = -1;
}

//copy constructor
Student::Student(const Student &s){
    studentID = s.studentID;
    name = s.name;
    level = s.level;
    major = s.major;
    GPA = s.GPA;
    facultyID = s.facultyID;
}

//overloaded constructor
Student::Student(int sID, string n, string l, string m, double gpa){
    studentID = sID;
    name = n;
    level = l;
    major = m;
    GPA = gpa;
    facultyID = -1;
//    facultyID = (f!=NULL)?f->getFacultyID():0;
}

void Student::setFacultyAdvisorID(int facultyID) {
//    facultyAdvisor = f;
    this->facultyID = facultyID;
}

//destructor
Student::~Student(){}

int Student::getStudentID(){
    return studentID;
}

string Student::toString(){
    return "Student ID: " + to_string(this->studentID) + ", Student Name: " + this->name + ", Student Level: " + this->level + ", Student Major: " + this->major + ", GPA: " + to_string(this->GPA) + ", Faculty ID: " + to_string(this->facultyID);
}

string Student::toCSV(){
    return to_string(this->studentID) + "," + this->name + "," + this->level + "," + this->major + "," + to_string(this->GPA) + ((facultyID==-1)?"":(","+to_string(facultyID)));
}
