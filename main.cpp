#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>


#include "Student.hpp"
#include "Faculty.hpp"
#include "GenBST.hpp"
#include "Database.hpp"

using namespace std;

int main (int argc, char **argv) {
    Database db;
    db.initializefromdisk();
    db.menu();
    cout << "Good Bye!!!" << endl;
    return 0;
}

//int main_0 (int argc, char **argv) {
//    Database db;
//    db.initializefromdisk();
//    db.printStudentInfo();
//    cout << endl;
//    db.printFacultyInfo();
//    db.save();
//    db.saveStudent();
//    db.saveFaculty();
//    db.addStudent();
//    db.addFaculty();
//    return 0;
//}
//
//int main_old (int argc, char **argv) {
//    BST<int, Faculty> masterFaculty;
//    BST<int, Student> masterStudent;
//    Student s(5, "Meghna Raswan", "Sophomore", "Computer Science", 3.80); //creating opject with input and output file parameters
//    Student s1(1, "Yuk Muck Duck", "Freshman", "Arts", 3.66); //creating opject with
//    Student s2(8, "Betty", "Freshman", "Film", 3.75); //creating opject with
//    Student s3(4, "Lucy", "Senior", "Game Dev", 3.90); //creating opject with
//    Student s4(9, "Margarie", "Junior", "Accounting", 3.85); //creating opject with
//    Student s5(7, "Martha", "Freshman", "Arts", 3.66); //creating opject with
//    Student s6(3, "Midge", "Freshman", "Film", 3.75); //creating opject with
//    Student s7(2, "Imogene", "Senior", "Game Dev", 3.90); //creating opject with
//    Student s8(10, "Rose", "Junior", "Accounting", 3.85); //creating opject with
//
//    Faculty f(7, "Mr. Feeny", "Professor", "English");
//    Faculty f1(5, "Mr. A", "Assoc. Professor", "English");
//    Faculty f2(3, "Mr. B", "Staff", "English");
//    Faculty f3(9, "Mr. C", "Assistant Professor", "English");
//    Faculty f4(8, "Mr. D", "Lecturer", "English");
//    Faculty f5(10, "Mr. E", "Professor", "English");
//    Faculty f6(4, "Mr. F", "Assoc. Professor", "English");
//    
//    cout << s.toString() << endl;
//    cout << f.toString() << endl;
//    cout << "<=========== linking ===========>" << endl;
//    s.setFacultyAdvisorID(f.facultyID);
//    f.setAdviseeID(5);
//    f.setAdviseeID(1);
//    
//    cout << s.toString() << endl;
//    cout << f.toString() << endl;
//    
//    cout << endl;
//    masterStudent.insertNode(5, s);
//    masterStudent.insertNode(1, s1);
//    masterStudent.insertNode(8, s2);
//    masterStudent.insertNode(4, s3);
//    masterStudent.insertNode(9, s4);
//    masterStudent.insertNode(7, s5);
//    masterStudent.insertNode(3, s6);
//    masterStudent.insertNode(2, s7);
//    masterStudent.insertNode(10, s8);
//
//    masterStudent.printTree();
//    
//    cout << endl;
//    
//    masterFaculty.insertNode(7, f);
//    masterFaculty.insertNode(5, f1);
//    masterFaculty.insertNode(3, f2);
//    masterFaculty.insertNode(9, f3);
//    masterFaculty.insertNode(8, f4);
//    masterFaculty.insertNode(10, f5);
//    masterFaculty.insertNode(4, f6);
//
//    masterFaculty.printTree();
//    
//    masterFaculty.deleteNode(5);
//
//    masterFaculty.printTree();
//
//    return 0;
//}
