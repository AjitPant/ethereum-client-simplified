//
// Created by Ajit Pant on 09/03/24.
//

#ifndef ETHEREUM_CLIENT_SIMPLIFIED_INSTRUCTION_H
#define ETHEREUM_CLIENT_SIMPLIFIED_INSTRUCTION_H


#include "types.h"
#include "opcodes.h"

class Instruction {
public:
    Bytecodes opcode;
    uint256_c push_value;
};


#endif //ETHEREUM_CLIENT_SIMPLIFIED_INSTRUCTION_H
