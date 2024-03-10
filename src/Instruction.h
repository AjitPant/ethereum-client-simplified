//
// Created by Ajit Pant on 09/03/24.
//

#ifndef ETHEREUM_CLIENT_SIMPLIFIED_INSTRUCTION_H
#define ETHEREUM_CLIENT_SIMPLIFIED_INSTRUCTION_H


#include "types.h"
#include "opcodes.h"

#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>

class Instruction {
public:
    Bytecodes opcode;
    uint256_c push_value;

    Instruction(Bytecodes opcode, uint256_c push_value){
        this->opcode = opcode;
        this->push_value = push_value;
    }

    std::vector<uint8_c> get_bytecode(){
        std::vector<uint8_c> bytecode;
        bytecode.push_back(opcode);
        if(opcode >= PUSH1 && opcode <= PUSH32){
            int diff = opcode - PUSH1 + 1;
            for(int i = 1; i <= diff; i++){
                bytecode.push_back(static_cast<uint8_c>(push_value >> (8 * (diff - i)) & 0xff));
            }
        }
        return bytecode;
    }

    std::string pretty_type(){
        std::string name = opcode_name_in_string(opcode);
        if(opcode >= PUSH1 && opcode <= PUSH32){
            name += " " + boost::lexical_cast<std::string>(push_value);
        }
        return name;


    }
};


#endif //ETHEREUM_CLIENT_SIMPLIFIED_INSTRUCTION_H
