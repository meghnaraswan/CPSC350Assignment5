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
