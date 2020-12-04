#include "Faculty.hpp"
#include "Student.hpp"
#include <string>
#include <algorithm>

//default constructor
Faculty::Faculty(){}

Faculty::Faculty(int fID, string n, string l, string d){
    facultyID = fID;
    name = n;
    level = l;
    department = d;
//    for (int i = 0; i < numAdvisees; ++i){ //rows
//        myArray[i] = new Student(); //array consists of Cell datatype
//    }
}

//destructor
Faculty::~Faculty(){}

int Faculty::getFacultyID(){
    return facultyID;
}

void Faculty::setAdviseeID(int studentID){
    adviseeStudentIDs.push_back(studentID);
}

void Faculty::removeAdiseeID(int studentID){
    auto it = std::find(adviseeStudentIDs.begin(), adviseeStudentIDs.end(), 5);
    if(it != adviseeStudentIDs.end()) {
       adviseeStudentIDs.erase(it);
    }
}

string Faculty::toString(){
    string ret_val = "Faculty ID: " + to_string(this->facultyID) + ", Faculty Name: " + this->name + ", Faculty Level: " + this->level + ", Faculty Department: " + this->department+
        ", # of Advisees: " + to_string(this->adviseeStudentIDs.size());
    ret_val += " [";
    for (vector<int>::iterator it=adviseeStudentIDs.begin(); it!=adviseeStudentIDs.end(); ++it)
        ret_val += to_string(*it) + ",";
    ret_val += "]";
    return ret_val;
}

string Faculty::toCSV(){
    string ret_val = to_string(this->facultyID) + "," + this->name + "," + this->level + "," + this->department;
    return ret_val;
}
