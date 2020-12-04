//
//  RollbackCommand.hpp
//  FirstCPP
//
//  Created by iMan on 12/3/20.
//  Copyright © 2020 iMan. All rights reserved.
//

#ifndef RollbackCommand_hpp
#define RollbackCommand_hpp

#include "Faculty.hpp"
#include "Student.hpp"
#include <string>

class RollbackCommand {
public:
    string command;
    Student* student;
    Faculty* faculty;
    
    RollbackCommand();
    RollbackCommand(string command, Student* s, Faculty* f);
    
    string toString();
};
#endif /* RollbackCommand_hpp */
