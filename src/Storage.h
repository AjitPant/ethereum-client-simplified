//
// Created by Ajit Pant on 09/03/24.
//

#ifndef ETHEREUM_CLIENT_SIMPLIFIED_STORAGE_H
#define ETHEREUM_CLIENT_SIMPLIFIED_STORAGE_H

#include "types.h"
#include <map>
class Storage {
    std::map<uint256_c, uint256_c> storage;
public:
    uint256_c& operator[](uint256_c index) {
        // Perform bounds checking if needed
        return storage[index];
    }
};


#endif //ETHEREUM_CLIENT_SIMPLIFIED_STORAGE_H
