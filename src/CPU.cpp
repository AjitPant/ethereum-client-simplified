//
// Created by Ajit Pant on 09/03/24.
//

#include "CPU.h"

bool CPU::execute_instruction(Instruction instruction) {
    Bytecodes opcode = instruction.opcode;
    uint256_c push_value = instruction.push_value;

    uint256_c a;
    uint256_c b;
    uint256_c N;

    switch(opcode){
        case STOP:
            // Stop and discontinue execution
            return true;
            break;
        case ADD:
            if(stack_register.size() < 2)
                throw std::runtime_error("Stack underflow");
            a = stack_register.top();
            stack_register.pop();
            b = stack_register.top();
            stack_register.pop();
            stack_register.push(a + b);
            break;
        case MUL:
            throw std::runtime_error("MUL opcode not implemented");
            break;
        case SUB:
            throw std::runtime_error("SUB opcode not implemented");
            break;
        case DIV:
            throw std::runtime_error("DIV opcode not implemented");
            break;
        case SDIV:
            throw std::runtime_error("SDIV opcode not implemented");
            break;
        case MOD:
            throw std::runtime_error("MOD opcode not implemented");
            break;
        case SMOD:
            throw std::runtime_error("SMOD opcode not implemented");
            break;
        case ADDMOD:
            throw std::runtime_error("ADDMOD opcode not implemented");
            break;
        case MULMOD:
            throw std::runtime_error("MULMOD opcode not implemented");
            break;
        case EXP:
            throw std::runtime_error("EXP opcode not implemented");
            break;
        case SIGNEXTEND:
            throw std::runtime_error("SIGNEXTEND opcode not implemented");
            break;
        case LT:
            throw std::runtime_error("LT opcode not implemented");
            break;
        case GT:
            throw std::runtime_error("GT opcode not implemented");
            break;
        case SLT:
            throw std::runtime_error("SLT opcode not implemented");
            break;
        case SGT:
            throw std::runtime_error("SGT opcode not implemented");
            break;
        case EQ:
            throw std::runtime_error("EQ opcode not implemented");
            break;
        case ISZERO:
            throw std::runtime_error("ISZERO opcode not implemented");
            break;
        case AND:
            throw std::runtime_error("AND opcode not implemented");
            break;
        case OR:
            throw std::runtime_error("OR opcode not implemented");
            break;
        case XOR:
            throw std::runtime_error("XOR opcode not implemented");
            break;
        case NOT:
            throw std::runtime_error("NOT opcode not implemented");
            break;
        case BYTE:
            throw std::runtime_error("BYTE opcode not implemented");
            break;
        case SHL:
            throw std::runtime_error("SHL opcode not implemented");
            break;
        case SHR:
            throw std::runtime_error("SHR opcode not implemented");
            break;
        case SAR:
            throw std::runtime_error("SAR opcode not implemented");
            break;
        case SHA3:
            throw std::runtime_error("SHA3 opcode not implemented");
            break;
        case ADDRESS:
            throw std::runtime_error("ADDRESS opcode not implemented");
            break;
        case BALANCE:
            throw std::runtime_error("BALANCE opcode not implemented");
            break;
        case ORIGIN:
            throw std::runtime_error("ORIGIN opcode not implemented");
            break;
        case CALLER:
            throw std::runtime_error("CALLER opcode not implemented");
            break;
        case CALLVALUE:
            throw std::runtime_error("CALLVALUE opcode not implemented");
            break;
        case CALLDATALOAD:
            throw std::runtime_error("CALLDATALOAD opcode not implemented");
            break;
        case CALLDATASIZE:
            throw std::runtime_error("CALLDATASIZE opcode not implemented");
            break;
        case CALLDATACOPY:
            throw std::runtime_error("CALLDATACOPY opcode not implemented");
            break;
        case CODESIZE:
            throw std::runtime_error("CODESIZE opcode not implemented");
            break;
        case CODECOPY:
            throw std::runtime_error("CODECOPY opcode not implemented");
            break;
        case GASPRICE:
            throw std::runtime_error("GASPRICE opcode not implemented");
            break;
        case EXTCODESIZE:
            throw std::runtime_error("EXTCODESIZE opcode not implemented");
            break;
        case EXTCODECOPY:
            throw std::runtime_error("EXTCODECOPY opcode not implemented");
            break;
        case RETURNDATASIZE:
            throw std::runtime_error("RETURNDATASIZE opcode not implemented");
            break;
        case RETURNDATACOPY:
            throw std::runtime_error("RETURNDATACOPY opcode not implemented");
            break;
        case EXTCODEHASH:
            throw std::runtime_error("EXTCODEHASH opcode not implemented");
            break;
        case BLOCKHASH:
            throw std::runtime_error("BLOCKHASH opcode not implemented");
            break;
        case COINBASE:
            throw std::runtime_error("COINBASE opcode not implemented");
            break;
        case TIMESTAMP:
            throw std::runtime_error("TIMESTAMP opcode not implemented");
            break;
        case NUMBER:
            throw std::runtime_error("NUMBER opcode not implemented");
            break;
        case DIFFICULTY:
            throw std::runtime_error("DIFFICULTY opcode not implemented");
            break;
        case GASLIMIT:
            throw std::runtime_error("GASLIMIT opcode not implemented");
            break;
        case CHAINID:
            throw std::runtime_error("CHAINID opcode not implemented");
            break;
        case SELFBALANCE:
            throw std::runtime_error("SELFBALANCE opcode not implemented");
            break;
        case BASEFEE:
            throw std::runtime_error("BASEFEE opcode not implemented");
            break;
        case POP:
            throw std::runtime_error("POP opcode not implemented");
            break;
        case MLOAD:
            throw std::runtime_error("MLOAD opcode not implemented");
            break;
        case MSTORE:
            throw std::runtime_error("MSTORE opcode not implemented");
            break;
        case MSTORE8:
            throw std::runtime_error("MSTORE8 opcode not implemented");
            break;
        case SLOAD:
            throw std::runtime_error("SLOAD opcode not implemented");
            break;
        case SSTORE:
            if(stack_register.size() < 2)
                throw std::runtime_error("Stack underflow");
            a = stack_register.top();
            stack_register.pop();
            b = stack_register.top();
            stack_register.pop();
            storage[a] = b;
            break;
        case JUMP:
            throw std::runtime_error("JUMP opcode not implemented");
            break;
        case JUMPI:
            throw std::runtime_error("JUMPI opcode not implemented");
            break;
        case PC:
            throw std::runtime_error("PC opcode not implemented");
            break;
        case MSIZE:
            throw std::runtime_error("MSIZE opcode not implemented");
            break;
        case GAS:
            throw std::runtime_error("GAS opcode not implemented");
            break;
        case JUMPDEST:
            throw std::runtime_error("JUMPDEST opcode not implemented");
            break;
        case PUSH1:
            stack_register.push(push_value);
            break;
        case PUSH2:
            throw std::runtime_error("PUSH2 opcode not implemented");
            break;
        case PUSH3:
            throw std::runtime_error("PUSH3 opcode not implemented");
            break;
        case PUSH4:
            throw std::runtime_error("PUSH4 opcode not implemented");
            break;
        case PUSH5:
            throw std::runtime_error("PUSH5 opcode not implemented");
            break;
        case PUSH6:
            throw std::runtime_error("PUSH6 opcode not implemented");
            break;
        case PUSH7:
            throw std::runtime_error("PUSH7 opcode not implemented");
            break;
        case PUSH8:
            throw std::runtime_error("PUSH8 opcode not implemented");
            break;
        case PUSH9:
            throw std::runtime_error("PUSH9 opcode not implemented");
            break;
        case PUSH10:
            throw std::runtime_error("PUSH10 opcode not implemented");
            break;
        case PUSH11:
            throw std::runtime_error("PUSH11 opcode not implemented");
            break;
        case PUSH12:
            throw std::runtime_error("PUSH12 opcode not implemented");
            break;
        case PUSH13:
            throw std::runtime_error("PUSH13 opcode not implemented");
            break;
        case PUSH14:
            throw std::runtime_error("PUSH14 opcode not implemented");
            break;
        case PUSH15:
            throw std::runtime_error("PUSH15 opcode not implemented");
            break;
        case PUSH16:
            throw std::runtime_error("PUSH16 opcode not implemented");
            break;
        case PUSH17:
            throw std::runtime_error("PUSH17 opcode not implemented");
            break;
        case PUSH18:
            throw std::runtime_error("PUSH18 opcode not implemented");
            break;
        case PUSH19:
            throw std::runtime_error("PUSH19 opcode not implemented");
            break;
        case PUSH20:
            throw std::runtime_error("PUSH20 opcode not implemented");
            break;
        case PUSH21:
            throw std::runtime_error("PUSH21 opcode not implemented");
            break;
        case PUSH22:
            throw std::runtime_error("PUSH22 opcode not implemented");
            break;
        case PUSH23:
            throw std::runtime_error("PUSH23 opcode not implemented");
            break;
        case PUSH24:
            throw std::runtime_error("PUSH24 opcode not implemented");
            break;
        case PUSH25:
            throw std::runtime_error("PUSH25 opcode not implemented");
            break;
        case PUSH26:
            throw std::runtime_error("PUSH26 opcode not implemented");
            break;
        case PUSH27:
            throw std::runtime_error("PUSH27 opcode not implemented");
            break;
        case PUSH28:
            throw std::runtime_error("PUSH28 opcode not implemented");
            break;
        case PUSH29:
            throw std::runtime_error("PUSH29 opcode not implemented");
            break;
        case PUSH30:
            throw std::runtime_error("PUSH30 opcode not implemented");
            break;
        case PUSH31:
            throw std::runtime_error("PUSH31 opcode not implemented");
            break;
        case PUSH32:
            throw std::runtime_error("PUSH32 opcode not implemented");
            break;
        case DUP1:
            throw std::runtime_error("DUP1 opcode not implemented");
            break;
        case DUP2:
            throw std::runtime_error("DUP2 opcode not implemented");
            break;
        case DUP3:
            throw std::runtime_error("DUP3 opcode not implemented");
            break;
        case DUP4:
            throw std::runtime_error("DUP4 opcode not implemented");
            break;
        case DUP5:
            throw std::runtime_error("DUP5 opcode not implemented");
            break;
        case DUP6:
            throw std::runtime_error("DUP6 opcode not implemented");
            break;
        case DUP7:
            throw std::runtime_error("DUP7 opcode not implemented");
            break;
        case DUP8:
            throw std::runtime_error("DUP8 opcode not implemented");
            break;
        case DUP9:
            throw std::runtime_error("DUP9 opcode not implemented");
            break;
        case DUP10:
            throw std::runtime_error("DUP10 opcode not implemented");
            break;
        case DUP11:
            throw std::runtime_error("DUP11 opcode not implemented");
            break;
        case DUP12:
            throw std::runtime_error("DUP12 opcode not implemented");
            break;
        case DUP13:
            throw std::runtime_error("DUP13 opcode not implemented");
            break;
        case DUP14:
            throw std::runtime_error("DUP14 opcode not implemented");
            break;
        case DUP15:
            throw std::runtime_error("DUP15 opcode not implemented");
            break;
        case DUP16:
            throw std::runtime_error("DUP16 opcode not implemented");
            break;
        case SWAP1:
            throw std::runtime_error("SWAP1 opcode not implemented");
            break;
        case SWAP2:
            throw std::runtime_error("SWAP2 opcode not implemented");
            break;
        case SWAP3:
            throw std::runtime_error("SWAP3 opcode not implemented");
            break;
        case SWAP4:
            throw std::runtime_error("SWAP4 opcode not implemented");
            break;
        case SWAP5:
            throw std::runtime_error("SWAP5 opcode not implemented");
            break;
        case SWAP6:
            throw std::runtime_error("SWAP6 opcode not implemented");
            break;
        case SWAP7:
            throw std::runtime_error("SWAP7 opcode not implemented");
            break;
        case SWAP8:
            throw std::runtime_error("SWAP8 opcode not implemented");
            break;
        case SWAP9:
            throw std::runtime_error("SWAP9 opcode not implemented");
            break;
        case SWAP10:
            throw std::runtime_error("SWAP10 opcode not implemented");
            break;
        case SWAP11:
            throw std::runtime_error("SWAP11 opcode not implemented");
            break;
        case SWAP12:
            throw std::runtime_error("SWAP12 opcode not implemented");
            break;
        case SWAP13:
            throw std::runtime_error("SWAP13 opcode not implemented");
            break;
        case SWAP14:
            throw std::runtime_error("SWAP14 opcode not implemented");
            break;
        case SWAP15:
            throw std::runtime_error("SWAP15 opcode not implemented");
            break;
        case SWAP16:
            throw std::runtime_error("SWAP16 opcode not implemented");
            break;
        case LOG0:
            throw std::runtime_error("LOG0 opcode not implemented");
            break;
        case LOG1:
            throw std::runtime_error("LOG1 opcode not implemented");
            break;
        case LOG2:
            throw std::runtime_error("LOG2 opcode not implemented");
            break;
        case LOG3:
            throw std::runtime_error("LOG3 opcode not implemented");
            break;
        case LOG4:
            throw std::runtime_error("LOG4 opcode not implemented");
            break;
        case CREATE:
            throw std::runtime_error("CREATE opcode not implemented");
            break;
        case CALL:
            throw std::runtime_error("CALL opcode not implemented");
            break;
        case CALLCODE:
            throw std::runtime_error("CALLCODE opcode not implemented");
            break;
        case RETURN:
            throw std::runtime_error("RETURN opcode not implemented");
            break;
        case DELEGATECALL:
            throw std::runtime_error("DELEGATECALL opcode not implemented");
            break;
        case CREATE2:
            throw std::runtime_error("CREATE2 opcode not implemented");
            break;
        case STATICCALL:
            throw std::runtime_error("STATICCALL opcode not implemented");
            break;
        case REVERT:
            throw std::runtime_error("REVERT opcode not implemented");
            break;
        case INVALID:
            throw std::runtime_error("INVALID opcode not implemented");
            break;
        case SELFDESTRUCT:
            throw std::runtime_error("SELFDESTRUCT opcode not implemented");
            break;

    }
    return false;

}

void CPU::execute_instructions(std::vector<Instruction> instructions) {

    for (auto &instruction : instructions) {
        // Execute the instruction
        bool was_halted = execute_instruction(instruction);
        if(was_halted)
            return;
    }
}