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
#include<deque>

#include <boost/multiprecision/cpp_int.hpp>


class CPU {
public:
    Memory memory;
    Storage storage;
    std::deque<uint256_c> stack_register;

    bool _execute_ADD();
    bool _execute_MUL();;
    bool _execute_SUB();
    bool _execute_DIV();
    bool _execute_SDIV();
    bool _execute_MOD();
    bool _execute_SMOD();
    bool _execute_ADDMOD();
    bool _execute_MULMOD();
    bool _execute_EXP();
    bool _execute_SIGNEXTEND();
    bool _execute_LT();
    bool _execute_GT();
    bool _execute_SLT();
    bool _execute_SGT();
    bool _execute_EQ();
    bool _execute_ISZERO();
    bool _execute_AND();
    bool _execute_OR();
    bool _execute_XOR();
    bool _execute_NOT();
    bool _execute_BYTE();
    bool _execute_SHL();
    bool _execute_SHR();
    bool _execute_SAR();
    bool _execute_SHA3();
    bool _execute_ADDRESS();
    bool _execute_BALANCE();
    bool _execute_ORIGIN();
    bool _execute_CALLER();
    bool _execute_CALLVALUE();
    bool _execute_CALLDATALOAD();
    bool _execute_CALLDATASIZE();
    bool _execute_CALLDATACOPY();
    bool _execute_CODESIZE();
    bool _execute_CODECOPY();
    bool _execute_GASPRICE();
    bool _execute_EXTCODESIZE();
    bool _execute_EXTCODECOPY();
    bool _execute_RETURNDATASIZE();
    bool _execute_RETURNDATACOPY();
    bool _execute_EXTCODEHASH();
    bool _execute_BLOCKHASH();
    bool _execute_COINBASE();
    bool _execute_TIMESTAMP();
    bool _execute_NUMBER();
    bool _execute_DIFFICULTY();
    bool _execute_GASLIMIT();
    bool _execute_CHAINID();
    bool _execute_SELFBALANCE();
    bool _execute_BASEFEE();
    bool _execute_POP();
    bool _execute_MLOAD();
    bool _execute_MSTORE();
    bool _execute_MSTORE8();
    bool _execute_SLOAD();
    bool _execute_SSTORE();
    bool _execute_JUMP();
    bool _execute_JUMPI();
    bool _execute_PC();
    bool _execute_MSIZE();
    bool _execute_GAS();
    bool _execute_JUMPDEST();
    bool _execute_PUSH1(uint256_c push_value);
    bool _execute_PUSH2(uint256_c push_value);
    bool _execute_PUSH3(uint256_c push_value);
    bool _execute_PUSH4(uint256_c push_value);
    bool _execute_PUSH5(uint256_c push_value);
    bool _execute_PUSH6(uint256_c push_value);
    bool _execute_PUSH7(uint256_c push_value);
    bool _execute_PUSH8(uint256_c push_value);
    bool _execute_PUSH9(uint256_c push_value);
    bool _execute_PUSH10(uint256_c push_value);
    bool _execute_PUSH11(uint256_c push_value);
    bool _execute_PUSH12(uint256_c push_value);
    bool _execute_PUSH13(uint256_c push_value);
    bool _execute_PUSH14(uint256_c push_value);
    bool _execute_PUSH15(uint256_c push_value);
    bool _execute_PUSH16(uint256_c push_value);
    bool _execute_PUSH17(uint256_c push_value);
    bool _execute_PUSH18(uint256_c push_value);
    bool _execute_PUSH19(uint256_c push_value);
    bool _execute_PUSH20(uint256_c push_value);
    bool _execute_PUSH21(uint256_c push_value);
    bool _execute_PUSH22(uint256_c push_value);
    bool _execute_PUSH23(uint256_c push_value);
    bool _execute_PUSH24(uint256_c push_value);
    bool _execute_PUSH25(uint256_c push_value);
    bool _execute_PUSH26(uint256_c push_value);
    bool _execute_PUSH27(uint256_c push_value);
    bool _execute_PUSH28(uint256_c push_value);
    bool _execute_PUSH29(uint256_c push_value);
    bool _execute_PUSH30(uint256_c push_value);
    bool _execute_PUSH31(uint256_c push_value);
    bool _execute_PUSH32(uint256_c push_value);
    bool _execute_DUP1();
    bool _execute_DUP2();
    bool _execute_DUP3();
    bool _execute_DUP4();
    bool _execute_DUP5();
    bool _execute_DUP6();
    bool _execute_DUP7();
    bool _execute_DUP8();
    bool _execute_DUP9();
    bool _execute_DUP10();
    bool _execute_DUP11();
    bool _execute_DUP12();
    bool _execute_DUP13();
    bool _execute_DUP14();
    bool _execute_DUP15();
    bool _execute_DUP16();
    bool _execute_SWAP1();
    bool _execute_SWAP2();
    bool _execute_SWAP3();
    bool _execute_SWAP4();
    bool _execute_SWAP5();
    bool _execute_SWAP6();
    bool _execute_SWAP7();
    bool _execute_SWAP8();
    bool _execute_SWAP9();
    bool _execute_SWAP10();
    bool _execute_SWAP11();
    bool _execute_SWAP12();
    bool _execute_SWAP13();
    bool _execute_SWAP14();
    bool _execute_SWAP15();
    bool _execute_SWAP16();
    bool _execute_LOG0();
    bool _execute_LOG1();
    bool _execute_LOG2();
    bool _execute_LOG3();
    bool _execute_LOG4();
    bool _execute_CREATE();
    bool _execute_CALL();
    bool _execute_CALLCODE();
    bool _execute_RETURN();
    bool _execute_DELEGATECALL();
    bool _execute_CREATE2();
    bool _execute_STATICCALL();
    bool _execute_REVERT();
    bool _execute_INVALID();
    bool _execute_SELFDESTRUCT();



    uint256_c __extract_top(bool pop = true);
    uint256_c __extract_ith(int i);
public:
    CPU(){
        memory = Memory();
        storage = Storage();
        stack_register = std::deque<uint256_c>();
    }
    bool execute_instruction(Instruction instruction);
    void execute_instructions(std::vector<Instruction> instructions);

    bool __keccak256(const std::vector<uint8_c> &input);
};


#endif //ETHEREUM_CLIENT_SIMPLIFIED_CPU_H
