//
//  RollbackCommand.cpp
//  FirstCPP
//
//  Created by iMan on 12/3/20.
//  Copyright © 2020 iMan. All rights reserved.
//

#include "RollbackCommand.hpp"
#include <string>

RollbackCommand::RollbackCommand(string command, Student* s, Faculty* f){
    this->command = command;
    this->student = s;
    this->faculty = f;
}

RollbackCommand::RollbackCommand(){
    this->command = "NA";
    this->student = NULL;
    this->faculty = NULL;
}

string RollbackCommand::toString() {
    return "command:" + this->command + ", Student:" +(this->student?to_string(this->student->studentID):"")
            + ", Faculty:" +(this->faculty?to_string(this->faculty->facultyID):"");
}
