#include <iostream>
#include <string>
#include "Instruction.h"
#include "CPU.h"
#include "opcodes.h"

using namespace std;

int base_test(){
    CPU cpu;
    vector<Instruction> instructions;
    instructions.push_back({Bytecodes::PUSH1, 0x01});
    instructions.push_back({Bytecodes::PUSH1, 0x02});
    instructions.push_back({Bytecodes::PUSH1, 0x03});
    instructions.push_back({Bytecodes::PUSH1, 0x04});
    instructions.push_back({Bytecodes::PUSH1, 0x05});
    instructions.push_back({Bytecodes::ADD, 0x00});
    instructions.push_back({Bytecodes::ADD, 0x00});
    instructions.push_back({Bytecodes::ADD, 0x00});
    instructions.push_back({Bytecodes::SSTORE, 0x0});

    cpu.execute_instructions(instructions);
    assert(cpu.storage[0x0e] == 0x01);

}
int main() {
    base_test();



    return 0;
}
