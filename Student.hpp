#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>
//#include "Faculty.hpp"

using namespace std;
class Faculty;

class Student{
    public:
        Student();
        Student(const Student &s);
        Student(int sID, string n, string l, string m, double gpa);
        ~Student();

        int studentID;
        string name;
        string level;
        string major;
        double GPA;
        int facultyID;
//        Faculty *facultyAdvisor;
    
        int getStudentID();
        string toString();
        string toCSV();
//        void setFacultyAdvisor(Faculty *f);
        void setFacultyAdvisorID(int facultyID);
};

#endif /* Student_hpp */
