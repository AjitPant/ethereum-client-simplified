//
// Created by Ajit Pant on 10/03/24.
//

#ifndef ETHEREUM_CLIENT_SIMPLIFIED_RAWBYTECODE_H
#define ETHEREUM_CLIENT_SIMPLIFIED_RAWBYTECODE_H

#include "Instruction.h"
#include <vector>
class RawBytecode {
public:
    std::vector<Instruction> convert_to_instructions(std::vector<uint8_c> bytesequence);
    std::vector<uint8_c>  convert_to_bytesequence(std::vector<Instruction> instructions);
};


#endif //ETHEREUM_CLIENT_SIMPLIFIED_RAWBYTECODE_H
