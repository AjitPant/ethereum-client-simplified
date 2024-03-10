//
// Created by Ajit Pant on 09/03/24.
//

#include "CPU.h"
uint256_c CPU::__extract_top(){
    if(stack_register.empty())
        throw std::runtime_error("Stack underflow");
    uint256_c a = stack_register.top();
    stack_register.pop();
    return a;
}

bool CPU::_execute_ADD() {
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    stack_register.push(a + b);
    return false;
}

bool CPU::_execute_MUL() {
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    stack_register.push(a * b);
    return false;
}

bool CPU::_execute_SUB() {
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    stack_register.push(a - b);
    return false;
}

bool CPU::_execute_DIV(){
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    uint256_c result;
    if(b == 0)
        result = 0;
    else
        result = a/b;
    stack_register.push(result);
    return false;

}

bool CPU::_execute_SDIV(){
    throw std::runtime_error("SDIV not implemented");
    return true;
}

bool CPU::_execute_MOD(){
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    uint256_c result;
    if(b == 0)
        result = 0;
    else
        result = a%b;
    stack_register.push(result);
    return false;
}

bool CPU::_execute_SMOD(){
    throw std::runtime_error("SMOD not implemented");
    return true;
}

bool CPU::_execute_ADDMOD(){
    uint512_c a = __extract_top();
    uint512_c b = __extract_top();
    uint512_c N = __extract_top();
    uint512_c result;
    if(N == 0)
        result = 0;
    else
        result = (a + b) % N;
    stack_register.push(static_cast<uint256_c>(result));
    return false;
}

bool CPU::_execute_MULMOD(){
    uint512_c a = __extract_top();
    uint512_c b = __extract_top();
    uint512_c N = __extract_top();
    uint512_c result;
    if(N == 0)
        result = 0;
    else
        result = (a * b) % N;
    stack_register.push(static_cast<uint256_c>(result));
    return false;

}

bool CPU::_execute_EXP(){
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    uint256_c result;
    if(b == 0)
        result = 1;
    else
        result = boost::multiprecision::pow(a, static_cast<unsigned long>(b)); // [TODO] Fix this for large power
    stack_register.push(result);
    return false;
}

bool CPU::_execute_SIGNEXTEND(){
    unsigned int b = static_cast<unsigned int>(__extract_top());
    uint256_c x = __extract_top();
    uint256_c result;
    // sign extends x from (b + 1) * 8 bits to 256 bits.
    if(b > 31)
        result = x;
    else{
        uint256_c mask = 0;
        for(int i = 0; i < b; i++){
            mask = (mask << 8) + 0xff;
        }
        uint256_c sign_bit = 0x80 << (b * 8);
        if(x & sign_bit){
            result = x | ~mask;
        } else{
            result = x & mask;
        }
    }
    return false;
}

bool CPU::_execute_LT(){
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    stack_register.push(a < b);
    return false;
}

bool CPU::_execute_GT(){
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    stack_register.push(a > b);
    return false;
}

bool CPU::_execute_SLT(){
    int256_c a = static_cast<int256_c>(__extract_top());
    int256_c b = static_cast<int256_c>(__extract_top());
    stack_register.push(a < b);
    return false;
}

bool CPU::_execute_SGT(){
    int256_c a = static_cast<int256_c>(__extract_top());
    int256_c b = static_cast<int256_c>(__extract_top());
    stack_register.push(a > b);
    return false;
}

bool CPU::_execute_EQ(){
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    stack_register.push(a == b);
    return false;
}
bool CPU::_execute_ISZERO(){
    uint256_c a = __extract_top();
    stack_register.push(a == 0);
    return false;
}

bool CPU::_execute_AND(){
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    stack_register.push(a & b);
    return false;
}

bool CPU::_execute_OR(){
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    stack_register.push(a | b);
    return false;
}

bool CPU::_execute_XOR(){
    uint256_c a = __extract_top();
    uint256_c b = __extract_top();
    stack_register.push(a ^ b);
    return false;
}

bool CPU::_execute_NOT(){
    uint256_c a = __extract_top();
    stack_register.push(~a);
    return false;
}

bool CPU::_execute_BYTE(){
    unsigned int i = static_cast<unsigned int>(__extract_top());
    uint256_c x = __extract_top();
    if(i > 31)
        stack_register.push(0);
    else
        stack_register.push((x >> (256 - 8 * i)) & 0xff);
    return false;
}

bool CPU::_execute_SHL(){
    uint256_c a = __extract_top();
    unsigned int b = static_cast<unsigned int>(__extract_top());
    stack_register.push(a << b);
    return false;
}

bool CPU::_execute_SHR(){
    uint256_c a = __extract_top();
    unsigned int b = static_cast<unsigned int>(__extract_top());
    stack_register.push(a >> b);
    return false;
}

bool CPU::_execute_SAR(){
    int256_c a = static_cast<int256_c>(__extract_top());
    int b = static_cast<int>(__extract_top());
    stack_register.push(static_cast<uint256_c>(a >> b));
    return false;
}
bool CPU::__keccak256(const std::vector<uint8_c>& input){
    throw std::runtime_error("SHA3 not implemented");
    return false;
}
bool CPU::_execute_SHA3(){
    uint256_c offset = __extract_top();
    uint256_c length = __extract_top();
    std::vector<uint8_c> data;
    for(uint256_c i = 0; i < length; i++){
        data.push_back(memory[offset + i]);
    }
    std::vector<uint8_c> hash = __keccak256(data);
    uint256_c result = 0;
    for(int i = 0; i < 32; i++){
        result = (result << 8) + hash[i];
    }
    stack_register.push(result);
    return false;
}

bool CPU::_execute_ADDRESS(){
    throw std::runtime_error("ADDRESS not implemented");
    return false;
}

bool CPU::_execute_BALANCE(){
    throw std::runtime_error("BALANCE not implemented");
    return false;
}

bool CPU::_execute_ORIGIN(){
    throw std::runtime_error("ORIGIN not implemented");
    return false;
}

bool CPU::_execute_CALLER(){
    throw std::runtime_error("CALLER not implemented");
    return false;
}

bool CPU::_execute_CALLVALUE(){
    throw std::runtime_error("CALLVALUE not implemented");
    return false;
}

bool CPU::_execute_CALLDATALOAD(){
    throw std::runtime_error("CALLDATALOAD not implemented");
    return false;
}

bool CPU::_execute_CALLDATASIZE(){
    throw std::runtime_error("CALLDATASIZE not implemented");
    return false;
}

bool CPU::_execute_CALLDATACOPY(){
    throw std::runtime_error("CALLDATACOPY not implemented");
    return false;
}

bool CPU::_execute_CODESIZE(){
    throw std::runtime_error("CODESIZE not implemented");
    return false;
}

bool CPU::_execute_CODECOPY(){
    throw std::runtime_error("CODECOPY not implemented");
    return false;
}

bool CPU::_execute_GASPRICE(){
    throw std::runtime_error("GASPRICE not implemented");
    return false;
}

bool CPU::_execute_EXTCODESIZE(){
    throw std::runtime_error("EXTCODESIZE not implemented");
    return false;
}

bool CPU::_execute_EXTCODECOPY(){
    throw std::runtime_error("EXTCODECOPY not implemented");
    return false;
}

bool CPU::_execute_RETURNDATASIZE(){
    throw std::runtime_error("RETURNDATASIZE not implemented");
    return false;
}

bool CPU::_execute_RETURNDATACOPY(){
    throw std::runtime_error("RETURNDATACOPY not implemented");
    return false;
}

bool CPU::_execute_EXTCODEHASH(){
    throw std::runtime_error("EXTCODEHASH not implemented");
    return false;
}

bool CPU::_execute_BLOCKHASH(){
    throw std::runtime_error("BLOCKHASH not implemented");
    return false;
}

bool CPU::_execute_COINBASE(){
    throw std::runtime_error("COINBASE not implemented");
    return false;
}

bool CPU::_execute_TIMESTAMP(){
    throw std::runtime_error("TIMESTAMP not implemented");
    return false;
}

bool CPU::_execute_NUMBER(){
    throw std::runtime_error("NUMBER not implemented");
    return false;
}

bool CPU::_execute_DIFFICULTY(){
    throw std::runtime_error("DIFFICULTY not implemented");
    return false;
}

bool CPU::_execute_GASLIMIT(){
    throw std::runtime_error("GASLIMIT not implemented");
    return false;
}

bool CPU::_execute_CHAINID(){
    throw std::runtime_error("CHAINID not implemented");
    return false;
}

bool CPU::_execute_SELFBALANCE(){
    throw std::runtime_error("SELFBALANCE not implemented");
    return false;
}

bool CPU::_execute_POP(){
    throw std::runtime_error("POP not implemented");
    return false;
}

bool CPU::_execute_MLOAD(){
    throw std::runtime_error("MLOAD not implemented");
    return false;
}

bool CPU::_execute_MSTORE(){
    throw std::runtime_error("MSTORE not implemented");
    return false;
}

bool CPU::_execute_MSTORE8(){
    throw std::runtime_error("MSTORE8 not implemented");
    return false;
}

bool CPU::_execute_SLOAD(){
    throw std::runtime_error("SLOAD not implemented");
    return false;
}

bool CPU::_execute_SSTORE(){
    throw std::runtime_error("SSTORE not implemented");
    return false;
}

bool CPU::_execute_JUMP(){
    throw std::runtime_error("JUMP not implemented");
    return false;
}

bool CPU::_execute_JUMPI(){
    throw std::runtime_error("JUMPI not implemented");
    return false;
}

bool CPU::_execute_PC(){
    throw std::runtime_error("PC not implemented");
    return false;
}

bool CPU::_execute_MSIZE(){
    throw std::runtime_error("MSIZE not implemented");
    return false;
}

bool CPU::_execute_GAS(){
    throw std::runtime_error("GAS not implemented");
    return false;
}

bool CPU::_execute_JUMPDEST(){
    throw std::runtime_error("JUMPDEST not implemented");
    return false;
}

bool CPU::_execute_PUSH1(){
    throw std::runtime_error("PUSH1 not implemented");
    return false;
}

bool CPU::_execute_PUSH2(){
    throw std::runtime_error("PUSH2 not implemented");
    return false;
}

bool CPU::_execute_PUSH3(){
    throw std::runtime_error("PUSH3 not implemented");
    return false;
}

bool CPU::_execute_PUSH4(){
    throw std::runtime_error("PUSH4 not implemented");
    return false;
}

bool CPU::_execute_PUSH5(){
    throw std::runtime_error("PUSH5 not implemented");
    return false;
}

bool CPU::_execute_PUSH6(){
    throw std::runtime_error("PUSH6 not implemented");
    return false;
}

bool CPU::_execute_PUSH7(){
    throw std::runtime_error("PUSH7 not implemented");
    return false;
}

bool CPU::_execute_PUSH8(){
    throw std::runtime_error("PUSH8 not implemented");
    return false;
}

bool CPU::_execute_PUSH9(){
    throw std::runtime_error("PUSH9 not implemented");
    return false;
}

bool CPU::_execute_PUSH10(){
    throw std::runtime_error("PUSH10 not implemented");
    return false;
}

bool CPU::_execute_PUSH11(){
    throw std::runtime_error("PUSH11 not implemented");
    return false;
}

bool CPU::_execute_PUSH12(){
    throw std::runtime_error("PUSH12 not implemented");
    return false;
}

bool CPU::_execute_PUSH13(){
    throw std::runtime_error("PUSH13 not implemented");
    return false;
}

bool CPU::_execute_PUSH14(){
    throw std::runtime_error("PUSH14 not implemented");
    return false;
}

bool CPU::_execute_PUSH15(){
    throw std::runtime_error("PUSH15 not implemented");
    return false;
}

bool CPU::_execute_PUSH16(){
    throw std::runtime_error("PUSH16 not implemented");
    return false;
}

bool CPU::_execute_PUSH17(){
    throw std::runtime_error("PUSH17 not implemented");
    return false;
}

bool CPU::_execute_PUSH18(){
    throw std::runtime_error("PUSH18 not implemented");
    return false;
}

bool CPU::_execute_PUSH19(){
    throw std::runtime_error("PUSH19 not implemented");
    return false;
}

bool CPU::_execute_PUSH20(){
    throw std::runtime_error("PUSH20 not implemented");
    return false;
}

bool CPU::_execute_PUSH21(){
    throw std::runtime_error("PUSH21 not implemented");
    return false;
}

bool CPU::_execute_PUSH22(){
    throw std::runtime_error("PUSH22 not implemented");
    return false;
}

bool CPU::_execute_PUSH23(){
    throw std::runtime_error("PUSH23 not implemented");
    return false;
}

bool CPU::_execute_PUSH24(){
    throw std::runtime_error("PUSH24 not implemented");
    return false;
}

bool CPU::_execute_PUSH25(){
    throw std::runtime_error("PUSH25 not implemented");
    return false;
}

bool CPU::_execute_PUSH26(){
    throw std::runtime_error("PUSH26 not implemented");
    return false;
}

bool CPU::_execute_PUSH27(){
    throw std::runtime_error("PUSH27 not implemented");
    return false;
}

bool CPU::_execute_PUSH28(){
    throw std::runtime_error("PUSH28 not implemented");
    return false;
}

bool CPU::_execute_PUSH29(){
    throw std::runtime_error("PUSH29 not implemented");
    return false;
}

bool CPU::_execute_PUSH30(){
    throw std::runtime_error("PUSH30 not implemented");
    return false;
}

bool CPU::_execute_PUSH31(){
    throw std::runtime_error("PUSH31 not implemented");
    return false;
}

bool CPU::_execute_PUSH32(){
    throw std::runtime_error("PUSH32 not implemented");
    return false;
}

bool CPU::_execute_DUP1(){
    throw std::runtime_error("DUP1 not implemented");
    return false;
}

bool CPU::_execute_DUP2(){
    throw std::runtime_error("DUP2 not implemented");
    return false;
}

bool CPU::_execute_DUP3(){
    throw std::runtime_error("DUP3 not implemented");
    return false;
}

bool CPU::_execute_DUP4(){
    throw std::runtime_error("DUP4 not implemented");
    return false;
}

bool CPU::_execute_DUP5(){
    throw std::runtime_error("DUP5 not implemented");
    return false;
}

bool CPU::_execute_DUP6(){
    throw std::runtime_error("DUP6 not implemented");
    return false;
}

bool CPU::_execute_DUP7(){
    throw std::runtime_error("DUP7 not implemented");
    return false;
}

bool CPU::_execute_DUP8(){
    throw std::runtime_error("DUP8 not implemented");
    return false;
}

bool CPU::_execute_DUP9(){
    throw std::runtime_error("DUP9 not implemented");
    return false;
}

bool CPU::_execute_DUP10(){
    throw std::runtime_error("DUP10 not implemented");
    return false;
}

bool CPU::_execute_DUP11(){
    throw std::runtime_error("DUP11 not implemented");
    return false;
}

bool CPU::_execute_DUP12(){
    throw std::runtime_error("DUP12 not implemented");
    return false;
}

bool CPU::_execute_DUP13(){
    throw std::runtime_error("DUP13 not implemented");
    return false;
}

bool CPU::_execute_DUP14(){
    throw std::runtime_error("DUP14 not implemented");
    return false;
}

bool CPU::_execute_DUP15(){
    throw std::runtime_error("DUP15 not implemented");
    return false;
}

bool CPU::_execute_DUP16(){
    throw std::runtime_error("DUP16 not implemented");
    return false;
}

bool CPU::_execute_SWAP1(){
    throw std::runtime_error("SWAP1 not implemented");
    return false;
}

bool CPU::_execute_SWAP2(){
    throw std::runtime_error("SWAP2 not implemented");
    return false;
}

bool CPU::_execute_SWAP3(){
    throw std::runtime_error("SWAP3 not implemented");
    return false;
}

bool CPU::_execute_SWAP4(){
    throw std::runtime_error("SWAP4 not implemented");
    return false;
}

bool CPU::_execute_SWAP5(){
    throw std::runtime_error("SWAP5 not implemented");
    return false;
}

bool CPU::_execute_SWAP6(){
    throw std::runtime_error("SWAP6 not implemented");
    return false;
}

bool CPU::_execute_SWAP7(){
    throw std::runtime_error("SWAP7 not implemented");
    return false;
}

bool CPU::_execute_SWAP8(){
    throw std::runtime_error("SWAP8 not implemented");
    return false;
}

bool CPU::_execute_SWAP9(){
    throw std::runtime_error("SWAP9 not implemented");
    return false;
}

bool CPU::_execute_SWAP10(){
    throw std::runtime_error("SWAP10 not implemented");
    return false;
}

bool CPU::_execute_SWAP11(){
    throw std::runtime_error("SWAP11 not implemented");
    return false;
}

bool CPU::_execute_SWAP12(){
    throw std::runtime_error("SWAP12 not implemented");
    return false;
}

bool CPU::_execute_SWAP13(){
    throw std::runtime_error("SWAP13 not implemented");
    return false;
}

bool CPU::_execute_SWAP14(){
    throw std::runtime_error("SWAP14 not implemented");
    return false;
}

bool CPU::_execute_SWAP15(){
    throw std::runtime_error("SWAP15 not implemented");
    return false;
}

bool CPU::_execute_SWAP16(){
    throw std::runtime_error("SWAP16 not implemented");
    return false;
}

bool CPU::_execute_LOG0(){
    throw std::runtime_error("LOG0 not implemented");
    return false;
}

bool CPU::_execute_LOG1(){
    throw std::runtime_error("LOG1 not implemented");
    return false;
}

bool CPU::_execute_LOG2(){
    throw std::runtime_error("LOG2 not implemented");
    return false;
}

bool CPU::_execute_LOG3(){
    throw std::runtime_error("LOG3 not implemented");
    return false;
}

bool CPU::_execute_LOG4(){
    throw std::runtime_error("LOG4 not implemented");
    return false;
}

bool CPU::_execute_CREATE(){
    throw std::runtime_error("CREATE not implemented");
    return false;
}

bool CPU::_execute_CALL(){
    throw std::runtime_error("CALL not implemented");
    return false;
}

bool CPU::_execute_CALLCODE(){
    throw std::runtime_error("CALLCODE not implemented");
    return false;
}

bool CPU::_execute_RETURN(){
    throw std::runtime_error("RETURN not implemented");
    return false;
}

bool CPU::_execute_DELEGATECALL(){
    throw std::runtime_error("DELEGATECALL not implemented");
    return false;
}

bool CPU::_execute_CREATE2(){
    throw std::runtime_error("CREATE2 not implemented");
    return false;
}

bool CPU::_execute_STATICCALL(){
    throw std::runtime_error("STATICCALL not implemented");
    return false;
}

bool CPU::_execute_REVERT(){
    throw std::runtime_error("REVERT not implemented");
    return false;
}

bool CPU::_execute_INVALID(){
    throw std::runtime_error("INVALID not implemented");
    return false;
}

bool CPU::_execute_SELFDESTRUCT(){
    throw std::runtime_error("SELFDESTRUCT not implemented");
    return false;
}






bool CPU::execute_instruction(Instruction instruction) {
    Bytecodes opcode = instruction.opcode;
    uint256_c push_value = instruction.push_value;

    switch(opcode){
        case STOP:
            // Stop and discontinue execution
            return true;
            break;
        case ADD:
            _execute_ADD();
            break;
        case MUL:
            _execute_MUL();;
            break;
        case SUB:
            _execute_SUB();
            break;
        case DIV:
            _execute_DIV();
            break;
        case SDIV:
            _execute_SDIV();
            break;
        case MOD:
            _execute_MOD();
            break;
        case SMOD:
            _execute_SMOD();
            break;
        case ADDMOD:
            _execute_ADDMOD();
            break;
        case MULMOD:
            _execute_MULMOD();
            break;
        case EXP:
            _execute_EXP();
            break;
        case SIGNEXTEND:
            _execute_SIGNEXTEND();
            break;
        case LT:
            _execute_LT();
            break;
        case GT:
            _execute_GT();
            break;
        case SLT:
            _execute_SLT();
            break;
        case SGT:
            _execute_SGT();
            break;
        case EQ:
            _execute_EQ();
            break;
        case ISZERO:
            _execute_ISZERO();
            break;
        case AND:
            _execute_AND();
            break;
        case OR:
            _execute_OR();
            break;
        case XOR:
            _execute_XOR();
            break;
        case NOT:
            _execute_NOT();
            break;
        case BYTE:
            _execute_BYTE();
            break;
        case SHL:
            _execute_SHL();
            break;
        case SHR:
            _execute_SHR();
            break;
        case SAR:
            _execute_SAR();
            break;
        case SHA3:
            _execute_SHA3();
            break;
        case ADDRESS:
            _execute_ADDRESS();
            break;
        case BALANCE:
            _execute_BALANCE();
            break;
        case ORIGIN:
            _execute_ORIGIN();
            break;
        case CALLER:
            _execute_CALLER();
            break;
        case CALLVALUE:
            _execute_CALLVALUE();
            break;
        case CALLDATALOAD:
            _execute_CALLDATALOAD();
            break;
        case CALLDATASIZE:
            _execute_CALLDATASIZE();
            break;
        case CALLDATACOPY:
            _execute_CALLDATACOPY();
            break;
        case CODESIZE:
            _execute_CODESIZE();
            break;
        case CODECOPY:
            _execute_CODECOPY();
            break;
        case GASPRICE:
            _execute_GASPRICE();
            break;
        case EXTCODESIZE:
            _execute_EXTCODESIZE();
            break;
        case EXTCODECOPY:
            _execute_EXTCODECOPY();
            break;
        case RETURNDATASIZE:
            _execute_RETURNDATASIZE();
            break;
        case RETURNDATACOPY:
            _execute_RETURNDATACOPY();
            break;
        case EXTCODEHASH:
            _execute_EXTCODEHASH();
            break;
        case BLOCKHASH:
            _execute_BLOCKHASH();
            break;
        case COINBASE:
            _execute_COINBASE();
            break;
        case TIMESTAMP:
            _execute_TIMESTAMP();
            break;
        case NUMBER:
            _execute_NUMBER();
            break;
        case DIFFICULTY:
            _execute_DIFFICULTY();
            break;
        case GASLIMIT:
            _execute_GASLIMIT();
            break;
        case CHAINID:
            _execute_CHAINID();
            break;
        case SELFBALANCE:
            _execute_SELFBALANCE();
            break;
        case BASEFEE:
            _execute_BASEFEE();
            break;
        case POP:
            _execute_POP();
            break;
        case MLOAD:
            _execute_MLOAD();
            break;
        case MSTORE:
            _execute_MSTORE();
            break;
        case MSTORE8:
            _execute_MSTORE8();
            break;
        case SLOAD:
            _execute_SLOAD();
            break;
        case SSTORE:
            _execute_SSTORE();
            break;
        case JUMP:
            _execute_JUMP();
            break;
        case JUMPI:
            _execute_JUMPI();
            break;
        case PC:
            _execute_PC();
            break;
        case MSIZE:
            _execute_MSIZE();
            break;
        case GAS:
            _execute_GAS();
            break;
        case JUMPDEST:
            _execute_JUMPDEST();
            break;
        case PUSH1:
            _execute_PUSH1();
            break;
        case PUSH2:
            _execute_PUSH2();
            break;
        case PUSH3:
            _execute_PUSH3();
            break;
        case PUSH4:
            _execute_PUSH4();
            break;
        case PUSH5:
            _execute_PUSH5();
            break;
        case PUSH6:
            _execute_PUSH6();
            break;
        case PUSH7:
            _execute_PUSH7();
            break;
        case PUSH8:
            _execute_PUSH8();
            break;
        case PUSH9:
            _execute_PUSH9();
            break;
        case PUSH10:
            _execute_PUSH10();
            break;
        case PUSH11:
            _execute_PUSH11();
            break;
        case PUSH12:
            _execute_PUSH12();
            break;
        case PUSH13:
            _execute_PUSH13();
            break;
        case PUSH14:
            _execute_PUSH14();
            break;
        case PUSH15:
            _execute_PUSH15();
            break;
        case PUSH16:
            _execute_PUSH16();
            break;
        case PUSH17:
            _execute_PUSH17();
            break;
        case PUSH18:
            _execute_PUSH18();
            break;
        case PUSH19:
            _execute_PUSH19();
            break;
        case PUSH20:
            _execute_PUSH20();
            break;
        case PUSH21:
            _execute_PUSH21();
            break;
        case PUSH22:
            _execute_PUSH22();
            break;
        case PUSH23:
            _execute_PUSH23();
            break;
        case PUSH24:
            _execute_PUSH24();
            break;
        case PUSH25:
            _execute_PUSH25();
            break;
        case PUSH26:
            _execute_PUSH26();
            break;
        case PUSH27:
            _execute_PUSH27();
            break;
        case PUSH28:
            _execute_PUSH28();
            break;
        case PUSH29:
            _execute_PUSH29();
            break;
        case PUSH30:
            _execute_PUSH30();
            break;
        case PUSH31:
            _execute_PUSH31();
            break;
        case PUSH32:
            _execute_PUSH32();
            break;
        case DUP1:
            _execute_DUP1();
            break;
        case DUP2:
            _execute_DUP2();
            break;
        case DUP3:
            _execute_DUP3();
            break;
        case DUP4:
            _execute_DUP4();
            break;
        case DUP5:
            _execute_DUP5();
            break;
        case DUP6:
            _execute_DUP6();
            break;
        case DUP7:
            _execute_DUP7();
            break;
        case DUP8:
            _execute_DUP8();
            break;
        case DUP9:
            _execute_DUP9();
            break;
        case DUP10:
            _execute_DUP10();
            break;
        case DUP11:
            _execute_DUP11();
            break;
        case DUP12:
            _execute_DUP12();
            break;
        case DUP13:
            _execute_DUP13();
            break;
        case DUP14:
            _execute_DUP14();
            break;
        case DUP15:
            _execute_DUP15();
            break;
        case DUP16:
            _execute_DUP16();
            break;
        case SWAP1:
            _execute_SWAP1();
            break;
        case SWAP2:
            _execute_SWAP2();
            break;
        case SWAP3:
            _execute_SWAP3();
            break;
        case SWAP4:
            _execute_SWAP4();
            break;
        case SWAP5:
            _execute_SWAP5();
            break;
        case SWAP6:
            _execute_SWAP6();
            break;
        case SWAP7:
            _execute_SWAP7();
            break;
        case SWAP8:
            _execute_SWAP8();
            break;
        case SWAP9:
            _execute_SWAP9();
            break;
        case SWAP10:
            _execute_SWAP10();
            break;
        case SWAP11:
            _execute_SWAP11();
            break;
        case SWAP12:
            _execute_SWAP12();
            break;
        case SWAP13:
            _execute_SWAP13();
            break;
        case SWAP14:
            _execute_SWAP14();
            break;
        case SWAP15:
            _execute_SWAP15();
            break;
        case SWAP16:
            _execute_SWAP16();
            break;
        case LOG0:
            _execute_LOG0();
            break;
        case LOG1:
            _execute_LOG1();
            break;
        case LOG2:
            _execute_LOG2();
            break;
        case LOG3:
            _execute_LOG3();
            break;
        case LOG4:
            _execute_LOG4();
            break;
        case CREATE:
            _execute_CREATE();
            break;
        case CALL:
            _execute_CALL();
            break;
        case CALLCODE:
            _execute_CALLCODE();
            break;
        case RETURN:
            _execute_RETURN();
            break;
        case DELEGATECALL:
            _execute_DELEGATECALL();
            break;
        case CREATE2:
            _execute_CREATE2();
            break;
        case STATICCALL:
            _execute_STATICCALL();
            break;
        case REVERT:
            _execute_REVERT();
            break;
        case INVALID:
            _execute_INVALID();
            break;
        case SELFDESTRUCT:
            _execute_SELFDESTRUCT();
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