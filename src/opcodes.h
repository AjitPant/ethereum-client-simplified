//
// Created by Ajit Pant on 10/03/24.
//

#ifndef ETHEREUM_CLIENT_SIMPLIFIED_OPCODES_H
#define ETHEREUM_CLIENT_SIMPLIFIED_OPCODES_H

#include <string>
enum Bytecodes{
    STOP = 0x00,
    ADD = 0x01,
    MUL = 0x02,
    SUB = 0x03,
    DIV = 0x04,
    SDIV = 0x05,
    MOD = 0x06,
    SMOD = 0x07,
    ADDMOD = 0x08,
    MULMOD = 0x09,
    EXP = 0x0a,
    SIGNEXTEND = 0x0b,
    LT = 0x10,
    GT = 0x11,
    SLT = 0x12,
    SGT = 0x13,
    EQ = 0x14,
    ISZERO = 0x15,
    AND = 0x16,
    OR = 0x17,
    XOR = 0x18,
    NOT = 0x19,
    BYTE = 0x1a,
    SHL = 0x1b,
    SHR = 0x1c,
    SAR = 0x1d,
    SHA3 = 0x20,
    ADDRESS = 0x30,
    BALANCE = 0x31,
    ORIGIN = 0x32,
    CALLER = 0x33,
    CALLVALUE = 0x34,
    CALLDATALOAD = 0x35,
    CALLDATASIZE = 0x36,
    CALLDATACOPY = 0x37,
    CODESIZE = 0x38,
    CODECOPY = 0x39,
    GASPRICE = 0x3a,
    EXTCODESIZE = 0x3b,
    EXTCODECOPY = 0x3c,
    RETURNDATASIZE = 0x3d,
    RETURNDATACOPY = 0x3e,
    EXTCODEHASH = 0x3f,
    BLOCKHASH = 0x40,
    COINBASE = 0x41,
    TIMESTAMP = 0x42,
    NUMBER = 0x43,
    DIFFICULTY = 0x44,
    GASLIMIT = 0x45,
    CHAINID = 0x46,
    SELFBALANCE = 0x47,
    BASEFEE = 0x48,
    POP = 0x50,
    MLOAD = 0x51,
    MSTORE = 0x52,
    MSTORE8 = 0x53,
    SLOAD = 0x54,
    SSTORE = 0x55,
    JUMP = 0x56,
    JUMPI = 0x57,
    PC = 0x58,
    MSIZE = 0x59,
    GAS = 0x5a,
    JUMPDEST = 0x5b,
    PUSH1 = 0x60,
    PUSH2 = 0x61,
    PUSH3 = 0x62,
    PUSH4 = 0x63,
    PUSH5 = 0x64,
    PUSH6 = 0x65,
    PUSH7 = 0x66,
    PUSH8 = 0x67,
    PUSH9 = 0x68,
    PUSH10 = 0x69,
    PUSH11 = 0x6a,
    PUSH12 = 0x6b,
    PUSH13 = 0x6c,
    PUSH14 = 0x6d,
    PUSH15 = 0x6e,
    PUSH16 = 0x6f,
    PUSH17 = 0x70,
    PUSH18 = 0x71,
    PUSH19 = 0x72,
    PUSH20 = 0x73,
    PUSH21 = 0x74,
    PUSH22 = 0x75,
    PUSH23 = 0x76,
    PUSH24 = 0x77,
    PUSH25 = 0x78,
    PUSH26 = 0x79,
    PUSH27 = 0x7a,
    PUSH28 = 0x7b,
    PUSH29 = 0x7c,
    PUSH30 = 0x7d,
    PUSH31 = 0x7e,
    PUSH32 = 0x7f,
    DUP1 = 0x80,
    DUP2 = 0x81,
    DUP3 = 0x82,
    DUP4 = 0x83,
    DUP5 = 0x84,
    DUP6 = 0x85,
    DUP7 = 0x86,
    DUP8 = 0x87,
    DUP9 = 0x88,
    DUP10 = 0x89,
    DUP11 = 0x8a,
    DUP12 = 0x8b,
    DUP13 = 0x8c,
    DUP14 = 0x8d,
    DUP15 = 0x8e,
    DUP16 = 0x8f,
    SWAP1 = 0x90,
    SWAP2 = 0x91,
    SWAP3 = 0x92,
    SWAP4 = 0x93,
    SWAP5 = 0x94,
    SWAP6 = 0x95,
    SWAP7 = 0x96,
    SWAP8 = 0x97,
    SWAP9 = 0x98,
    SWAP10 = 0x99,
    SWAP11 = 0x9a,
    SWAP12 = 0x9b,
    SWAP13 = 0x9c,
    SWAP14 = 0x9d,
    SWAP15 = 0x9e,
    SWAP16 = 0x9f,
    LOG0 = 0xa0,
    LOG1 = 0xa1,
    LOG2 = 0xa2,
    LOG3 = 0xa3,
    LOG4 = 0xa4,
    CREATE = 0xf0,
    CALL = 0xf1,
    CALLCODE = 0xf2,
    RETURN = 0xf3,
    DELEGATECALL = 0xf4,
    CREATE2 = 0xf5,
    STATICCALL = 0xfa,
    REVERT = 0xfd,
    INVALID = 0xfe,
    SELFDESTRUCT = 0xff
};

static std::string opcode_name_in_string(Bytecodes b){
    switch(b) {
        case STOP:
            return "STOP";
        case ADD:
            return "ADD";
        case MUL:
            return "MUL";
        case SUB:
            return "SUB";
        case DIV:
            return "DIV";
        case SDIV:
            return "SDIV";
        case MOD:
            return "MOD";
        case SMOD:
            return "SMOD";
        case ADDMOD:
            return "ADDMOD";
        case MULMOD:
            return "MULMOD";
        case EXP:
            return "EXP";
        case SIGNEXTEND:
            return "SIGNEXTEND";
        case LT:
            return "LT";
        case GT:
            return "GT";
        case SLT:
            return "SLT";
        case SGT:
            return "SGT";
        case EQ:
            return "EQ";
        case ISZERO:
            return "ISZERO";
        case AND:
            return "AND";
        case OR:
            return "OR";
        case XOR:
            return "XOR";
        case NOT:
            return "NOT";
        case BYTE:
            return "BYTE";
        case SHL:
            return "SHL";
        case SHR:
            return "SHR";
        case SAR:
            return "SAR";
        case SHA3:
            return "SHA3";
        case ADDRESS:
            return "ADDRESS";
        case BALANCE:
            return "BALANCE";
        case ORIGIN:
            return "ORIGIN";
        case CALLER:
            return "CALLER";
        case CALLVALUE:
            return "CALLVALUE";
        case CALLDATALOAD:
            return "CALLDATALOAD";
        case CALLDATASIZE:
            return "CALLDATASIZE";
        case CALLDATACOPY:
            return "CALLDATACOPY";
        case CODESIZE:
            return "CODESIZE";
        case CODECOPY:
            return "CODECOPY";
        case GASPRICE:
            return "GASPRICE";
        case EXTCODESIZE:
            return "EXTCODESIZE";
        case EXTCODECOPY:
            return "EXTCODECOPY";
        case RETURNDATASIZE:
            return "RETURNDATASIZE";
        case RETURNDATACOPY:
            return "RETURNDATACOPY";
        case EXTCODEHASH:
            return "EXTCODEHASH";
        case BLOCKHASH:
            return "BLOCKHASH";
        case COINBASE:
            return "COINBASE";
        case TIMESTAMP:
            return "TIMESTAMP";
        case NUMBER:
            return "NUMBER";
        case DIFFICULTY:
            return "DIFFICULTY";
        case GASLIMIT:
            return "GASLIMIT";
        case CHAINID:
            return "CHAINID";
        case SELFBALANCE:
            return "SELFBALANCE";
        case BASEFEE:
            return "BASEFEE";
        case POP:
            return "POP";
        case MLOAD:
            return "MLOAD";
        case MSTORE:
            return "MSTORE";
        case MSTORE8:
            return "MSTORE8";
        case SLOAD:
            return "SLOAD";
        case SSTORE:
            return "SSTORE";
        case JUMP:
            return "JUMP";
        case JUMPI:
            return "JUMPI";
        case PC:
            return "PC";
        case MSIZE:
            return "MSIZE";
        case GAS:
            return "GAS";
        case JUMPDEST:
            return "JUMPDEST";
        case PUSH1:
            return "PUSH1";
        case PUSH2:
            return "PUSH2";
        case PUSH3:
            return "PUSH3";
        case PUSH4:
            return "PUSH4";
        case PUSH5:
            return "PUSH5";
        case PUSH6:
            return "PUSH6";
        case PUSH7:
            return "PUSH7";
        case PUSH8:
            return "PUSH8";
        case PUSH9:
            return "PUSH9";
        case PUSH10:
            return "PUSH10";
        case PUSH11:
            return "PUSH11";
        case PUSH12:
            return "PUSH12";
        case PUSH13:
            return "PUSH13";
        case PUSH14:
            return "PUSH14";
        case PUSH15:
            return "PUSH15";
        case PUSH16:
            return "PUSH16";
        case PUSH17:
            return "PUSH17";
        case PUSH18:
            return "PUSH18";
        case PUSH19:
            return "PUSH19";
        case PUSH20:
            return "PUSH20";
        case PUSH21:
            return "PUSH21";
        case PUSH22:
            return "PUSH22";
        case PUSH23:
            return "PUSH23";
        case PUSH24:
            return "PUSH24";
        case PUSH25:
            return "PUSH25";
        case PUSH26:
            return "PUSH26";
        case PUSH27:
            return "PUSH27";
        case PUSH28:
            return "PUSH28";
        case PUSH29:
            return "PUSH29";
        case PUSH30:
            return "PUSH30";
        case PUSH31:
            return "PUSH31";
        case PUSH32:
            return "PUSH32";
        case DUP1:
            return "DUP1";
        case DUP2:
            return "DUP2";
        case DUP3:
            return "DUP3";
        case DUP4:
            return "DUP4";
        case DUP5:
            return "DUP5";
        case DUP6:
            return "DUP6";
        case DUP7:
            return "DUP7";
        case DUP8:
            return "DUP8";
        case DUP9:
            return "DUP9";
        case DUP10:
            return "DUP10";
        case DUP11:
            return "DUP11";
        case DUP12:
            return "DUP12";
        case DUP13:
            return "DUP13";
        case DUP14:
            return "DUP14";
        case DUP15:
            return "DUP15";
        case DUP16:
            return "DUP16";
        case SWAP1:
            return "SWAP1";
        case SWAP2:
            return "SWAP2";
        case SWAP3:
            return "SWAP3";
        case SWAP4:
            return "SWAP4";
        case SWAP5:
            return "SWAP5";
        case SWAP6:
            return "SWAP6";
        case SWAP7:
            return "SWAP7";
        case SWAP8:
            return "SWAP8";
        case SWAP9:
            return "SWAP9";
        case SWAP10:
            return "SWAP10";
        case SWAP11:
            return "SWAP11";
        case SWAP12:
            return "SWAP12";
        case SWAP13:
            return "SWAP13";
        case SWAP14:
            return "SWAP14";
        case SWAP15:
            return "SWAP15";
        case SWAP16:
            return "SWAP16";
        case LOG0:
            return "LOG0";
        case LOG1:
            return "LOG1";
        case LOG2:
            return "LOG2";
        case LOG3:
            return "LOG3";
        case LOG4:
            return "LOG4";
        case CREATE:
            return "CREATE";
        case CALL:
            return "CALL";
        case CALLCODE:
            return "CALLCODE";
        case RETURN:
            return "RETURN";
        case DELEGATECALL:
            return "DELEGATECALL";
        case CREATE2:
            return "CREATE2";
        case STATICCALL:
            return "STATICCALL";
        case REVERT:
            return "REVERT";
        case INVALID:
            return "INVALID";
        case SELFDESTRUCT:
            return "SELFDESTRUCT";
        default:
            return "INVALID";
    }


}
#endif //ETHEREUM_CLIENT_SIMPLIFIED_OPCODES_H
