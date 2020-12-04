#ifndef Database_hpp
#define Database_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

#include "Student.hpp"
#include "Faculty.hpp"
#include "GenBST.hpp"
//#include "GenStack.hpp"
#include "BSTIterator.hpp"
#include "GenStack.hpp"
#include "RollbackCommand.hpp"

using namespace std;

class Database{
    private:
        void readStudentFile();
        void readFacultyFile();
        void assignAdviseeTofaculty();
    
        GenStack<RollbackCommand> rollbackStack;
    
        void deleteStudent(Student& del_student);
        void deleteFaculty(Faculty& del_faculty);
        void addStudent(Student& student);
        void addFaculty(Faculty& faculty);

    
    public:
        Database();
        ~Database();
    
        void initializefromdisk();
    
        void printStudentInfo();
        void printFacultyInfo();
        void printStudentInfoAscendingOrder();
        void printFacultyInfoAscendingOrder();
        void displayOneStudentInfo();
        void displayOneFacultyInfo();
        void printAdvisor();
        void printAdvisees();
        void addStudent();
        void deleteStudent();
        void addFaculty();
        void deleteFaculty();
        void changeStudentAdvisor();
        void removeAdviseeFromFaculty();
        void rollback();
//        void exit();
        void menu();
        void save();
        void saveStudent();
        void saveFaculty();
    
        BST<int, Faculty> masterFaculty;
        BST<int, Student> masterStudent;
        string studentFileName;
        string facultyFileName;
        string studentOutputFileName;
        string facultyOutputFileName;
    
//        typedef GenStack<Student> myStack; //creating stack object with char in place of the generic typ from the template
//        typedef GenStack<Faculty> myStack; //creating stack object with char in place of the generic typ from the template

//        myStack ms(10);
};

#endif /* Database_hpp */
