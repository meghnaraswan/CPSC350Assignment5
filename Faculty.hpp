#ifndef Faculty_hpp
#define Faculty_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
//#include "Student.hpp"

using namespace std;

class Student;
class Faculty{
    public:
        Faculty();
        Faculty(const Faculty &f);
        Faculty(int fID, string n, string l, string d);
        ~Faculty();

        int facultyID;
        string name;
        string level;
        string department;
        
        int numAdvisees;
        vector<int> adviseeStudentIDs;

        int getFacultyID();
        string toString();
        string toCSV();
        void setAdviseeID(int studentID);
        void removeAdiseeID(int studentID);
};

#endif /* Faculty_hpp */
