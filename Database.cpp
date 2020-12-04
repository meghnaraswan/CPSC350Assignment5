#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "Database.hpp"
#include "TreeNode.hpp"
#include "BSTIterator.hpp"


using namespace std;

Database::Database(){
    studentFileName = "/home/FirstCPP/BSTDatabase/sample_student_table.csv";
    facultyFileName = "/home/FirstCPP/BSTDatabase/sample_faculty_table.csv";
    studentOutputFileName = studentFileName;
    facultyOutputFileName = facultyFileName;
}

Database::~Database(){}

void Database::save(){
//    BSTIterator<int, Student> it = masterStudent.iterator();
//    while(it.hasNext()) {
//        TreeNode<int, Student>* node = it.next();
//        cout << node->valueToCSV() << endl;
//    }
    cout << "Saving to Disk" << endl;
    saveFaculty();
    saveStudent();
}

void Database::saveStudent(){
    ofstream out(studentOutputFileName); // open studentFileName in append mode
    BSTIterator<int, Student> it = masterStudent.iterator();
    while(it.hasNext()) {
        TreeNode<int, Student>* node = it.next();
//        cout << node->valueToCSV() << endl;
        out << node->valueToCSV() << endl; // append studnet info to the end of the file
    }
    out.close(); // close the file
    cout << "Student saved to disk successfully in: " <<  studentOutputFileName << endl;
}

void Database::saveFaculty(){
    ofstream out(facultyOutputFileName); // open studentFileName in append mode
    BSTIterator<int, Faculty> it = masterFaculty.iterator();
    while(it.hasNext()) {
        TreeNode<int, Faculty>* node = it.next();
//        cout << node->valueToCSV() << endl;
        out << node->valueToCSV() << endl; // append studnet info to the end of the file
    }
    out.close(); // close the file
    cout << "Faculty saved to disk successfully in: " << facultyOutputFileName << endl;
}

void Database::printStudentInfoAscendingOrder(){
    BSTIterator<int, Student> it = masterStudent.iterator();
//    it.setCurrentForNextOrdered();
    while(it.hasNext()) {
        TreeNode<int, Student>* node = it.next();
        cout << node->value.toString() << endl;
    }
}

void Database::printFacultyInfoAscendingOrder(){
    BSTIterator<int, Faculty> it = masterFaculty.iterator();
//    it.setCurrentForNextOrdered();
    while(it.hasNext()) {
        TreeNode<int, Faculty>* node = it.next();
        cout << node->value.toString() << endl;
    }
}

void Database::readStudentFile(){
    std::fstream fileInputStream;
    fileInputStream.open(studentFileName, std::ios::in);
    int lineCount = 0;
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line;
    while (std::getline(fileInputStream, line)) {
        row.clear();
        stringstream str_stream(line);
        string col;
        while (std::getline(str_stream, col, ',')) {
            row.push_back(col);
//            cout << col << endl;
        }
        int studentID = stoi(row[0]);
        string name = row[1];
        string level = row[2];
        string major = row[3];
        double GPA = stod(row[4]);
        Student student(studentID, name, level, major, GPA);
        int facultyID = -1;
        if(row.size() > 5)
            facultyID = stoi(row[5]);
        student.facultyID = facultyID;
        masterStudent.insertNode(studentID, student);        
        lineCount++;
    }
    fileInputStream.close(); //close the file object.
}

void Database::readFacultyFile(){
    std::fstream fileInputStream;
    fileInputStream.open(facultyFileName, std::ios::in);
    int lineCount = 0;
    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line;
    while (std::getline(fileInputStream, line)) {
        row.clear();
        stringstream str_stream(line);
        string col;
        while (std::getline(str_stream, col, ',')) {
            row.push_back(col);
//            cout << col << endl;
        }
        int facultyID = stoi(row[0]);
        string name = row[1];
        string level = row[2];
        string department = row[3];
//        facultyID = stoi(row[5]);
        Faculty faculty(facultyID, name, level, department);
        masterFaculty.insertNode(facultyID, faculty);
        lineCount++;
    }
    fileInputStream.close(); //close the file object.
}

void Database::assignAdviseeTofaculty(){
    BSTIterator<int, Student> it = masterStudent.iterator();
    while(it.hasNext()) {
        TreeNode<int, Student>* node = it.next();
        if(node->value.facultyID != -1) {
            TreeNode<int, Faculty>* faculty_node = masterFaculty.searchNode(node->value.facultyID);
            faculty_node->value.setAdviseeID(node->key);
        }
    }
}

void Database::initializefromdisk(){
    this->readStudentFile();
    this->readFacultyFile();
    this->assignAdviseeTofaculty();
}

void Database::printStudentInfo(){
    masterStudent.printTree();
}

void Database::printFacultyInfo(){
    masterFaculty.printTree();
}

//void Database::addStudent(){
//    int studentID;
//    string name;
//    string level;
//    string major;
//    double GPA;
////    int facultyID;
//    cout << "Student ID: " << endl;
//    cin >> studentID;
//    cout << "Student Name: " << endl;
//    cin >> name;
//    cout << "Student Major: " << endl;
//    cin >> major;
//    cout << "Student GPA: " << endl;
//    cin >> GPA;
//    cout << "Student Level: " << endl;
//    cin >> level;
////    cout << "Faculty ID: " << endl;
////    cin >> facultyID;
//    Student student(studentID, name, level, major, GPA);
//    bool insert_successful = masterStudent.insertNode(studentID, student);
//    if(insert_successful) {
//        rollbackStack.push(RollbackCommand("DS",&student,NULL));
//        cout << "Student (" << studentID << ") successfully inserted." << endl;
//    } else {
//        cout << "Student (" << studentID << ") NOT inserted." << endl;
//    }
//}

void Database::addStudent(){
    int studentID;
    string name;
    string level;
    string major;
    double GPA;
//    int facultyID;
    cout << "Student ID: " << endl;
    cin >> studentID;
    cout << "Student Name: " << endl;
    cin >> name;
    cout << "Student Major: " << endl;
    cin >> major;
    cout << "Student GPA: " << endl;
    cin >> GPA;
    cout << "Student Level: " << endl;
    cin >> level;
    Student student(studentID, name, level, major, GPA);
    addStudent(student);
}

void Database::addStudent(Student& student){
    int studentID;
    bool insert_successful = masterStudent.insertNode(studentID, student);
    if(insert_successful) {
        rollbackStack.push(RollbackCommand("DS",&student,NULL));
        cout << "Student (" << student.studentID << ") successfully inserted." << endl;
    } else {
        cout << "Student (" << student.studentID << ") NOT inserted." << endl;
    }
}

void Database::addFaculty(){
    int facultyID;
    string name;
    string level;
    string department;
//    int studentID;
    cout << "Faculty ID: " << endl;
    cin >> facultyID;
    cout << "Faculty Name: " << endl;
    cin >> name;
    cout << "Faculty Department: " << endl;
    cin >> department;
    cout << "Faculty Level: " << endl;
    cin >> level;
    Faculty faculty(facultyID, name, level, department);
    addFaculty(faculty);
}

void Database::addFaculty(Faculty& faculty){
    int facultyID;
    bool insert_successful = masterFaculty.insertNode(facultyID, faculty);
    if(insert_successful) {
        rollbackStack.push(RollbackCommand("DF",NULL,&faculty));
        cout << "Faculty (" << faculty.facultyID << ") successfully inserted." << endl;
    } else {
        cout << "Faculty (" << faculty.facultyID << ") NOT inserted." << endl;
    }
}

//void Database::addFaculty(){
//    int facultyID;
//    string name;
//    string level;
//    string department;
////    int studentID;
//    cout << "Faculty ID: " << endl;
//    cin >> facultyID;
//    cout << "Faculty Name: " << endl;
//    cin >> name;
//    cout << "Faculty Department: " << endl;
//    cin >> department;
//    cout << "Faculty Level: " << endl;
//    cin >> level;
//    Faculty faculty(facultyID, name, level, department);
//    bool insert_successful = masterFaculty.insertNode(facultyID, faculty);
//    if(insert_successful) {
//        rollbackStack.push(RollbackCommand("DF",NULL,&faculty));
//        cout << "Faculty (" << facultyID << ") successfully inserted." << endl;
//    } else {
//        cout << "Faculty (" << facultyID << ") NOT inserted." << endl;
//    }
//}

void Database::deleteStudent(){
    int studentID;
    cout << "Student ID you want to delete: " << endl;
    cin >> studentID;
    
    Student* del_student = masterStudent.deleteNode(studentID);
    deleteStudent(del_student);
}

void Database::deleteStudent(Student *del_student){
    if(del_student) {
        rollbackStack.push(RollbackCommand("IS",del_student,NULL));
        cout << "Student (" << del_student->studentID << ") successfully deleted." << endl;
    } else {
        cout << "Student (" << del_student->studentID << ") cannot be found!!!" << endl;
    }
}

void Database::deleteFaculty(){
    int facultyID;
    cout << "Faculty ID you want to delete: " << endl;
    cin >> facultyID;
    
    Faculty *del_faculty = masterFaculty.deleteNode(facultyID);
    deleteFaculty(del_faculty);
}

void Database::deleteFaculty(Faculty *del_faculty){
    if(del_faculty) {
        rollbackStack.push(RollbackCommand("IF",NULL,del_faculty));
        cout << "Faculty (" << del_faculty->facultyID << ") successfully deleted." << endl;
    } else {
        cout << "Faculty (" << del_faculty->facultyID << ") cannot be found!!!" << endl;
    }
}

//void Database::deleteFaculty(){
//    int facultyID;
//    cout << "Faculty ID you want to delete: " << endl;
//    cin >> facultyID;
//    Faculty *del_faculty = masterFaculty.deleteNode(facultyID);
//    if(del_faculty) {
//        rollbackStack.push(RollbackCommand("IF",NULL,del_faculty));
//        cout << "Faculty (" << facultyID << ") successfully deleted." << endl;
//    } else {
//        cout << "Faculty (" << facultyID << ") cannot be found!!!" << endl;
//    }
//}


void Database::displayOneStudentInfo(){
    int studentID;
    cout << "Student ID you want to search: " << endl;
    cin >> studentID;
    TreeNode<int, Student>* student_node = masterStudent.searchNode(studentID);
    if(student_node == NULL) {
        cout << "Student (" << studentID << ") cannot be found!!!" << endl;
    } else {
        cout << student_node->value.toString() << endl;
    }
}

void Database::displayOneFacultyInfo(){
    int facultyID;
    cout << "Faculty ID you want to search: " << endl;
    cin >> facultyID;
    TreeNode<int, Faculty>* faculty_node = masterFaculty.searchNode(facultyID);
    if(faculty_node == NULL) {
        cout << "Faculty (" << facultyID << ") cannot be found!!!" << endl;
    } else {
        cout << faculty_node->value.toString() << endl;
    }
}

void Database::printAdvisor(){
    int studentID;
    cout << "Student ID: ";
    cin >> studentID;
    TreeNode<int, Student>* student_node = masterStudent.searchNode(studentID);
    if(student_node == NULL) {
        cout << "Student (" << studentID << ") cannot be found!!!" << endl;
    } else {
        TreeNode<int, Faculty>* faculty_node = masterFaculty.searchNode(student_node->value.facultyID);
        cout << faculty_node->value.toString() << endl;
    }
}

void Database::printAdvisees(){
    int facultyID;
    cout << "Faculty ID: ";
    cin >> facultyID;
    TreeNode<int, Faculty>* faculty_node = masterFaculty.searchNode(facultyID);
    if(faculty_node == NULL) {
        cout << "Faculty (" << facultyID << ") cannot be found!!!" << endl;
    } else {
        for (vector<int>::iterator it=faculty_node->value.adviseeStudentIDs.begin(); it!=faculty_node->value.adviseeStudentIDs.end(); ++it) {
            int studentID = *it;
            TreeNode<int, Student>* student_node = masterStudent.searchNode(studentID);
            cout << student_node->value.toString() << endl;
        }
    }
}

void Database::changeStudentAdvisor(){
    int facultyID;
    int studentID;
    cout << "Student ID: ";
    cin >> studentID;
    cout << "Faculty ID: ";
    cin >> facultyID;
    TreeNode<int, Student>* student_node = masterStudent.searchNode(studentID);
    TreeNode<int, Faculty>* faculty_node = masterFaculty.searchNode(facultyID);
    if(student_node == NULL) {
        cout << "Student (" << studentID << ") cannot be found!!!" << endl;
    } else { // student_node != NULL
        // remove advisee ID in the older faculty object
        if(student_node->value.facultyID != -1) {
            TreeNode<int, Faculty>* older_faculty_node = masterFaculty.searchNode(student_node->value.facultyID);

            rollbackStack.push(RollbackCommand("CA",&student_node->value,&older_faculty_node->value));

            older_faculty_node->value.removeAdiseeID(studentID);
            student_node->value.facultyID = -1;
        }
        //  add new adviseeID
        if(faculty_node == NULL) {
            cout << "Faculty (" << facultyID << ") cannot be found!!!" << endl;
        } else{
            //        cout << student_node->value.toString() << endl;
            student_node->value.facultyID = facultyID;
            faculty_node->value.setAdviseeID(studentID);
            
            rollbackStack.push(RollbackCommand("CA",&student_node->value,NULL));
            
            cout << student_node->value.toString() << endl;
            cout << faculty_node->value.toString() << endl;
            cout << "Student (" << studentID << ") advisor is Faculty (" << facultyID << ")" << endl;
        }
    }
}

void Database::removeAdviseeFromFaculty(){
    int facultyID;
    int studentID;
    cout << "Student ID: ";
    cin >> studentID;
    cout << "Faculty ID: ";
    cin >> facultyID;
    TreeNode<int, Student>* student_node = masterStudent.searchNode(studentID);
    if(student_node == NULL) {
        cout << "Student (" << studentID << ") cannot be found!!!" << endl;
    } else { // student_node != NULL
        // remove advisee ID in the older faculty object
        if(student_node->value.facultyID != -1) {
            TreeNode<int, Faculty>* older_faculty_node = masterFaculty.searchNode(student_node->value.facultyID);
            
            rollbackStack.push(RollbackCommand("CA",&student_node->value,&older_faculty_node->value));
            
            older_faculty_node->value.removeAdiseeID(studentID);
            student_node->value.facultyID = -1;
            cout << student_node->value.toString() << endl;
            cout << older_faculty_node->value.toString() << endl;
        }
    }
}

void Database::rollback(){
    if(!rollbackStack.isEmpty()) {
        cout << rollbackStack.getSize() << " Rollbacks available" << endl;
        rollbackStack.print();
        RollbackCommand rollback = rollbackStack.pop();
        cout << rollbackStack.getSize() << " Rollbacks after pop" << endl;
        rollbackStack.print();
        if (rollback.command == "IF") {
            addFaculty(*rollback.faculty);
        } else if (rollback.command == "IS") {
            addStudent(*rollback.student);
        } else if (rollback.command == "DF") {
            deleteFaculty(rollback.faculty);
        } else if (rollback.command == "DS") {
            deleteStudent(rollback.student);
        } else if (rollback.command == "CA") {
            cout << "To be implemented" << endl;
        } else {
            cout << "******* Rollback Command not coded *******" << endl;
        }
    } else {
        cout << "Nothing to Rollback" << endl;
    }
    
    
    
}


void Database::menu(){
    while (true) //infinite loop
    {
        int option;
        cout << endl;
        cout << "+-------------------------------------------------------------------+" << endl;
        cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
        cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
        cout << "3. Find and display student information given the students id" << endl;
        cout << "4. Find and display faculty information given the faculty id" << endl;
        cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
        cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
        cout << "7. Add a new student" << endl;
        cout << "8. Delete a student given the id" << endl;
        cout << "9. Add a new faculty member" << endl;
        cout << "10. Delete a faculty member given the id." << endl;
        cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
        cout << "12. Remove an advisee from a faculty member given the ids" << endl;
        cout << "13. Rollback" << endl;
        cout << "14. Save to disk" << endl;
        cout << "15. Print all students and their information (DEBUG)" << endl;
        cout << "16. Print all faculty and their information (DEBUG)" << endl;
        cout << "17. Exit" << endl;
        cout << "+-------------------------------------------------------------------+" << endl;
        cout << "Option Selected: ";
        cin >> option;

        switch (option)
        {
            case 1:
                printStudentInfoAscendingOrder();
                break;
            case 2:
                printFacultyInfoAscendingOrder();
                break;
            case 3:
                displayOneStudentInfo();
                break;
            case 4:
                displayOneFacultyInfo();
                break;
            case 5:
                printAdvisor();
                break;
            case 6:
                printAdvisees();
                break;
            case 7:
                addStudent();
                break;
            case 8:
                deleteStudent();
                break;
            case 9:
                addFaculty();
                break;
            case 10:
                deleteFaculty();
                break;
            case 11:
                changeStudentAdvisor();
                break;
            case 12:
                removeAdviseeFromFaculty();
                break;
            case 13:
                rollback();
                break;
            case 14:
                save();
                break;
            case 15:
                printStudentInfo();
                break;
            case 16:
                printFacultyInfo();
                break;
            default:
                break;
        }
        if (option > 16) {//program will end if user inputs 'Q' or 'q'
            save();
            break;
        }
    }
}


//void Database::deleteStudent(){
//    int studentID;
//    cout << "Student ID: " << endl;
//    cin >> studentID;
//    std::fstream fileInputStream;
//    fileInputStream.open(facultyFileName, std::ios::in);
//    int lineCount = 0;
//    // Read the Data from the file
//    // as String Vector
//    vector<string> row;
//    string line;
//    while (std::getline(fileInputStream, line)) {
//        row.clear();
//        stringstream str_stream(line);
//        string col;
//        while (std::getline(str_stream, col, ',')) {
//            row.push_back(col);
//            cout << col << endl;
//        }
//        int facultyID = stoi(row[0]);
//        string name = row[1];
//        string level = row[2];
//        string department = row[3];
////        facultyID = stoi(row[5]);
//        Faculty faculty(facultyID, name, level, department);
//        masterFaculty.insertNode(facultyID, faculty);
//        lineCount++;
//    }
//    fileInputStream.close(); //close the file object.
//}


