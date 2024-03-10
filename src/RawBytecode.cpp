//
// Created by Ajit Pant on 10/03/24.
//

#include "RawBytecode.h"

std::vector<uint8_c> RawBytecode::convert_to_bytesequence(std::vector<Instruction> instructions) {
    std::vector<uint8_c> bytesequence;
    for (int i = 0; i < instructions.size(); i++) {
        std::vector<uint8_c> bytecode = instructions[i].get_bytecode();
        bytesequence.insert(bytesequence.end(), bytecode.begin(), bytecode.end());
    }
    return bytesequence;
}

std::vector<Instruction> RawBytecode::convert_to_instructions(std::vector<uint8_c> bytesequence) {
    std::vector<Instruction> instructions;

    for (int i = 0; i < bytesequence.size(); i++) {
        if (bytesequence[i] >= PUSH1 && bytesequence[i] <= PUSH32) {
            uint256_c push_value = 0;
            int diff = static_cast<int>(bytesequence[i] - PUSH1 + 1);
            for (int j = 1; j <= diff; j++) {
                push_value = push_value << 8;
                push_value = push_value | bytesequence[i + j];
            }
            instructions.push_back(Instruction(static_cast<Bytecodes>(bytesequence[i]), push_value));
            i += diff;
        } else {
            instructions.push_back(Instruction(static_cast<Bytecodes>(bytesequence[i]), 0));
        }
    }
    return instructions;
}
