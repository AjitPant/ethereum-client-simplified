//
// Created by Ajit Pant on 09/03/24.
//

#ifndef ETHEREUM_CLIENT_SIMPLIFIED_MEMORY_H
#define ETHEREUM_CLIENT_SIMPLIFIED_MEMORY_H

#include "types.h"
#include <map>
class Memory {
    std::map<uint256_c, uint8_c> memory;
public:

    uint8_c& operator[](uint256_c index) {
        // Perform bounds checking if needed
        return memory[index];
    }
};


#endif //ETHEREUM_CLIENT_SIMPLIFIED_MEMORY_H
