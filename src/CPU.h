//
// Created by Ajit Pant on 09/03/24.
//

#ifndef ETHEREUM_CLIENT_SIMPLIFIED_CPU_H
#define ETHEREUM_CLIENT_SIMPLIFIED_CPU_H

#include "Memory.h"
#include "Storage.h"
#include "Instruction.h"
#include "opcodes.h"
#include "types.h"
#include<vector>
#include<stack>

#include <boost/multiprecision/cpp_int.hpp>


class CPU {
public:
    Memory memory;
    Storage storage;
    std::stack<uint256_c> stack_register;
public:
    CPU(){
        memory = Memory();
        storage = Storage();
        stack_register = std::stack<uint256_c>();
    }
    bool execute_instruction(Instruction instruction);
    void execute_instructions(std::vector<Instruction> instructions);

};


#endif //ETHEREUM_CLIENT_SIMPLIFIED_CPU_H
