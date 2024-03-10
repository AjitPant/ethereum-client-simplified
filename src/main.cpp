#include <iostream>
#include <string>
#include "Instruction.h"
#include "CPU.h"
#include "opcodes.h"
#include "RawBytecode.h"

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

    for(Instruction instruction: instructions){
        cout << instruction.pretty_type() << endl;
    }
    assert(cpu.storage[0x0e] == 0x01);

}

int test_string_to_pretty_print()
{
    string input = "0x60806040526004361061013f575f3560e01c8063715018a6116100b3578063a9059cbb1161006d578063a9059cbb1461038c578063bf474bed146103ab578063c9567bf9146103c0578063d34628cc146103d4578063dd62ed3e146103f3578063ec1f3f6314610437575f80fd5b8063715018a6146102e8578063751039fc146102fc5780637d1db4a5146103105780638da5cb5b146103255780638f9a55c01461034b57806395d89b4114610360575f80fd5b806323b872dd1161010457806323b872dd14610210578063313ce5671461022f57806331c2d8471461024a5780633bbac5791461026957806351bc3c85146102a057806370a08231146102b4575f80fd5b806306fdde031461014a578063095ea7b3146101945780630faee56f146101c3578063109daa99146101e657806318160ddd146101fc575f80fd5b3661014657005b5f80fd5b348015610155575f80fd5b5060408051808201909152601081526f2832b832902a3432902832b733bab4b760811b60208201525b60405161018b9190611670565b60405180910390f35b34801561019f575f80fd5b506101b36101ae3660046116e3565b610456565b604051901515815260200161018b565b3480156101ce575f80fd5b506101d860125481565b60405190815260200161018b565b3480156101f1575f80fd5b506101fa61046c565b005b348015610207575f80fd5b506101d86104da565b34801561021b575f80fd5b506101b361022a36600461170d565b6104fb565b34801561023a575f80fd5b506040516009815260200161018b565b348015610255575f80fd5b506101fa61026436600461175f565b610562565b348015610274575f80fd5b506101b361028336600461181f565b6001600160a01b03165f9081526004602052604090205460ff1690565b3480156102ab575f80fd5b506101fa6105e9565b3480156102bf575f80fd5b506101d86102ce36600461181f565b6001600160a01b03165f9081526001602052604090205490565b3480156102f3575f80fd5b506101fa610636565b348015610307575f80fd5b506101fa6106a7565b34801561031b575f80fd5b506101d8600f5481565b348015610330575f80fd5b505f546040516001600160a01b03909116815260200161018b565b348015610356575f80fd5b506101d860105481565b34801561036b575f80fd5b50604080518082019091526004815263504f504f60e01b602082015261017e565b348015610397575f80fd5b506101b36103a63660046116e3565b610756565b3480156103b6575f80fd5b506101d860115481565b3480156103cb575f80fd5b506101fa610762565b3480156103df575f80fd5b506101fa6103ee36600461175f565b610b0c565b3480156103fe575f80fd5b506101d861040d36600461183a565b6001600160a01b039182165f90815260026020908152604080832093909416825291909152205490565b348015610442575f80fd5b506101fa610451366004611871565b610b90565b5f610462338484610bd5565b5060015b92915050565b5f546001600160a01b0316331461049e5760405162461bcd60e51b815260040161049590611888565b60405180910390fd5b5f600d8190556040519081527fe9b79e1a6c2dc43b4c0c6ff01ce9e3332d810e482270f464c0a21ad6c5fc6de3906020015b60405180910390a1565b5f6104e76009600a6119b1565b6104f6906461f313f8806119bf565b905090565b5f610507848484610cf8565b610558843361055385604051806060016040528060288152602001611b1e602891396001600160a01b038a165f90815260026020908152604080832033845290915290205491906112ec565b610bd5565b5060019392505050565b5f546001600160a01b0316331461058b5760405162461bcd60e51b815260040161049590611888565b5f5b81518110156105e5575f60045f8484815181106105ac576105ac6119d6565b6020908102919091018101516001600160a01b031682528101919091526040015f20805460ff191691151591909117905560010161058d565b5050565b6005546001600160a01b0316336001600160a01b031614610608575f80fd5b305f9081526001602052604090205480156106265761062681611324565b4780156105e5576105e581611494565b5f546001600160a01b0316331461065f5760405162461bcd60e51b815260040161049590611888565b5f80546040516001600160a01b03909116907f8be0079c531659141344cd1fd0a4f28419497f9722a3daafe3b4186f6b6457e0908390a35f80546001600160a01b0319169055565b5f546001600160a01b031633146106d05760405162461bcd60e51b815260040161049590611888565b6106dc6009600a6119b1565b6106eb906461f313f8806119bf565b600f556106fa6009600a6119b1565b610709906461f313f8806119bf565b6010557f947f344d56e1e8c70dc492fb94c4ddddd490c016aab685f5e7e47b2e85cb44cf6107396009600a6119b1565b610748906461f313f8806119bf565b6040519081526020016104d0565b5f610462338484610cf8565b5f546001600160a01b0316331461078b5760405162461bcd60e51b815260040161049590611888565b601454600160a01b900460ff16156107e55760405162461bcd60e51b815260206004820152601760248201527f74726164696e6720697320616c7265616479206f70656e0000000000000000006044820152606401610495565b601380546001600160a01b031916737a250d5630b4cf539739df2c5dacb4c659f2488d90811790915561082f9030906108206009600a6119b1565b610553906461f313f8806119bf565b60135f9054906101000a90046001600160a01b03166001600160a01b031663c45a01556040518163ffffffff1660e01b8152600401602060405180830381865afa15801561087f573d5f803e3d5ffd5b505050506040513d601f19601f820116820180604052508101906108a391906119ea565b6001600160a01b031663c9c653963060135f9054906101000a90046001600160a01b03166001600160a01b031663ad5c46486040518163ffffffff1660e01b8152600401602060405180830381865afa158015610902573d5f803e3d5ffd5b505050506040513d601f19601f8201168201806040525081019061092691906119ea565b6040516001600160e01b031960e085901b1681526001600160a01b039283166004820152911660248201526044016020604051808303815f875af1158015610970573d5f803e3d5ffd5b505050506040513d601f19601f8201168201806040525081019061099491906119ea565b601480546001600160a01b039283166001600160a01b03199091161790556013541663f305d71947306109db816001600160a01b03165f9081526001602052604090205490565b5f806109ee5f546001600160a01b031690565b60405160e088901b6001600160e01b03191681526001600160a01b03958616600482015260248101949094526044840192909252606483015290911660848201524260a482015260c40160606040518083038185885af1158015610a54573d5f803e3d5ffd5b50505050506040513d601f19601f82011682018060405250810190610a799190611a05565b505060145460135460405163095ea7b360e01b81526001600160a01b0391821660048201525f1960248201529116915063095ea7b3906044016020604051808303815f875af1158015610ace573d5f803e3d5ffd5b505050506040513d601f19601f82011682018060405250810190610af29190611a30565b506014805462ff00ff60a01b19166201000160a01b179055565b5f546001600160a01b03163314610b355760405162461bcd60e51b815260040161049590611888565b5f5b81518110156105e557600160045f848481518110610b5757610b576119d6565b6020908102919091018101516001600160a01b031682528101919091526040015f20805460ff1916911515919091179055600101610b37565b6005546001600160a01b0316336001600160a01b031614610baf575f80fd5b6008548111158015610bc357506009548111155b610bcb575f80fd5b6008819055600955565b6001600160a01b038316610c375760405162461bcd60e51b8152602060048201526024808201527f45524332303a20617070726f76652066726f6d20746865207a65726f206164646044820152637265737360e01b6064820152608401610495565b6001600160a01b038216610c985760405162461bcd60e51b815260206004820152602260248201527f45524332303a20617070726f766520746f20746865207a65726f206164647265604482015261737360f01b6064820152608401610495565b6001600160a01b038381165f8181526002602090815260408083209487168084529482529182902085905590518481527f8c5be1e5ebec7d5bd14f71427d1e84f3dd0314c0f7b2291e5b200ac8c7c3b925910160405180910390a3505050565b6001600160a01b038316610d5c5760405162461bcd60e51b815260206004820152602560248201527f45524332303a207472616e736665722066726f6d20746865207a65726f206164604482015264647265737360d81b6064820152608401610495565b6001600160a01b038216610dbe5760405162461bcd60e51b815260206004820152602360248201527f45524332303a207472616e7366657220746f20746865207a65726f206164647260448201526265737360e81b6064820152608401610495565b5f8111610e1f5760405162461bcd60e51b815260206004820152602960248201527f5472616e7366657220616d6f756e74206d7573742062652067726561746572206044820152687468616e207a65726f60b81b6064820152608401610495565b5f80546001600160a01b03858116911614801590610e4a57505f546001600160a01b03848116911614155b156111af576001600160a01b0384165f9081526004602052604090205460ff16158015610e8f57506001600160a01b0383165f9081526004602052604090205460ff16155b610e97575f80fd5b600e545f03610ecf57610ecc6064610ec6600a54600e5411610ebb57600654610ebf565b6008545b85906114cb565b90611550565b90505b600e5415610ef457610ef16064610ec6600d54856114cb90919063ffffffff16565b90505b6014546001600160a01b038581169116148015610f1f57506013546001600160a01b03848116911614155b8015610f4357506001600160a01b0383165f9081526003602052604090205460ff16155b1561104657600f54821115610f9a5760405162461bcd60e51b815260206004820152601960248201527f4578636565647320746865205f6d61785478416d6f756e742e000000000000006044820152606401610495565b60105482610fbc856001600160a01b03165f9081526001602052604090205490565b610fc69190611a4f565b11156110145760405162461bcd60e51b815260206004820152601a60248201527f4578636565647320746865206d617857616c6c657453697a652e0000000000006044820152606401610495565b61102f6064610ec6600a54600e5411610ebb57600654610ebf565b600e80549192505f61104083611a62565b91905055505b6014546001600160a01b03848116911614801561106c57506001600160a01b0384163014155b15611099576110966064610ec6600b54600e541161108c57600754610ebf565b60095485906114cb565b90505b305f90815260016020526040902054601454600160a81b900460ff161580156110cf57506014546001600160a01b038581169116145b80156110e45750601454600160b01b900460ff165b80156110f1575060115481115b80156111005750600c54600e54115b156111ad57601654431115611114575f6015555b6003601554106111665760405162461bcd60e51b815260206004820152601760248201527f4f6e6c7920332073656c6c732070657220626c6f636b210000000000000000006044820152606401610495565b61118361117e8461117984601254611591565b611591565b611324565b4780156111935761119347611494565b60158054905f6111a283611a62565b909155505043601655505b505b801561122757305f908152600160205260409020546111ce90826115a5565b305f81815260016020526040908190209290925590516001600160a01b038616907fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef9061121e9085815260200190565b60405180910390a35b6001600160a01b0384165f908152600160205260409020546112499083611603565b6001600160a01b0385165f9081526001602052604090205561128c61126e8383611603565b6001600160a01b0385165f90815260016020526040902054906115a5565b6001600160a01b038085165f8181526001602052604090209290925585167fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef6112d58585611603565b60405190815260200160405180910390a350505050565b5f818484111561130f5760405162461bcd60e51b81526004016104959190611670565b505f61131b8486611a7a565b95945050505050565b6014805460ff60a81b1916600160a81b1790556040805160028082526060820183525f9260208301908036833701905050905030815f8151811061136a5761136a6119d6565b6001600160a01b03928316602091820292909201810191909152601354604080516315ab88c960e31b81529051919093169263ad5c46489260048083019391928290030181865afa1580156113c1573d5f803e3d5ffd5b505050506040513d601f19601f820116820180604052508101906113e591906119ea565b816001815181106113f8576113f86119d6565b6001600160a01b03928316602091820292909201015260135461141e9130911684610bd5565b60135460405163791ac94760e01b81526001600160a01b039091169063791ac947906114569085905f90869030904290600401611a8d565b5f604051808303815f87803b15801561146d575f80fd5b505af115801561147f573d5f803e3d5ffd5b50506014805460ff60a81b1916905550505050565b6005546040516001600160a01b039091169082156108fc029083905f818181858888f193505050501580156105e5573d5f803e3d5ffd5b5f825f036114da57505f610466565b5f6114e583856119bf565b9050826114f28583611afe565b146115495760405162461bcd60e51b815260206004820152602160248201527f536166654d6174683a206d756c7469706c69636174696f6e206f766572666c6f6044820152607760f81b6064820152608401610495565b9392505050565b5f61154983836040518060400160405280601a81526020017f536166654d6174683a206469766973696f6e206279207a65726f000000000000815250611644565b5f81831161159f5782611549565b50919050565b5f806115b18385611a4f565b9050838110156115495760405162461bcd60e51b815260206004820152601b60248201527f536166654d6174683a206164646974696f6e206f766572666c6f7700000000006044820152606401610495565b5f61154983836040518060400160405280601e81526020017f536166654d6174683a207375627472616374696f6e206f766572666c6f7700008152506112ec565b5f81836116645760405162461bcd60e51b81526004016104959190611670565b505f61131b8486611afe565b5f602080835283518060208501525f5b8181101561169c57858101830151858201604001528201611680565b505f604082860101526040601f19601f8301168501019250505092915050565b6001600160a01b03811681146116d0575f80fd5b50565b80356116de816116bc565b919050565b5f80604083850312156116f4575f80fd5b82356116ff816116bc565b946020939093013593505050565b5f805f6060848603121561171f575f80fd5b833561172a816116bc565b9250602084013561173a816116bc565b929592945050506040919091013590565b634e487b7160e01b5f52604160045260245ffd5b5f6020808385031215611770575f80fd5b823567ffffffffffffffff80821115611787575f80fd5b818501915085601f83011261179a575f80fd5b8135818111156117ac576117ac61174b565b8060051b604051601f19603f830116810181811085821117156117d1576117d161174b565b6040529182528482019250838101850191888311156117ee575f80fd5b938501935b8285101561181357611804856116d3565b845293850193928501926117f3565b98975050505050505050565b5f6020828403121561182f575f80fd5b8135611549816116bc565b5f806040838503121561184b575f80fd5b8235611856816116bc565b91506020830135611866816116bc565b809150509250929050565b5f60208284031215611881575f80fd5b5035919050565b6020808252818101527f4f776e61626c653a2063616c6c6572206973206e6f7420746865206f776e6572604082015260600190565b634e487b7160e01b5f52601160045260245ffd5b600181815b8085111561190b57815f19048211156118f1576118f16118bd565b808516156118fe57918102915b93841c93908002906118d6565b509250929050565b5f8261192157506001610466565b8161192d57505f610466565b8160018114611943576002811461194d57611969565b6001915050610466565b60ff84111561195e5761195e6118bd565b50506001821b610466565b5060208310610133831016604e8410600b841016171561198c575081810a610466565b61199683836118d1565b805f19048211156119a9576119a96118bd565b029392505050565b5f61154960ff841683611913565b8082028115828204841417610466576104666118bd565b634e487b7160e01b5f52603260045260245ffd5b5f602082840312156119fa575f80fd5b8151611549816116bc565b5f805f60608486031215611a17575f80fd5b8351925060208401519150604084015190509250925092565b5f60208284031215611a40575f80fd5b81518015158114611549575f80fd5b80820180821115610466576104666118bd565b5f60018201611a7357611a736118bd565b5060010190565b81810381811115610466576104666118bd565b5f60a08201878352602087602085015260a0604085015281875180845260c0860191506020890193505f5b81811015611add5784516001600160a01b031683529383019391830191600101611ab8565b50506001600160a01b03969096166060850152505050608001529392505050565b5f82611b1857634e487b7160e01b5f52601260045260245ffd5b50049056fe45524332303a207472616e7366657220616d6f756e74206578636565647320616c6c6f77616e6365a26469706673582212207afeabb786ee1ccdcb96ffd06c1430fd2219455c316618b463eef085226745c164736f6c63430008170033";
    vector<uint8_c> bytesequence;
    for(int i = 2; i < input.size(); i+=2){
        string byte = input.substr(i, 2);
        uint8_c byte_value = static_cast<uint8_c>(strtol(byte.c_str(), nullptr, 16));
        bytesequence.push_back(byte_value);
    }
    vector<Instruction> instructions = RawBytecode().convert_to_instructions(bytesequence);
    for(Instruction instruction: instructions){
        cout << instruction.pretty_type() << endl;
    }
}
int main() {
//    base_test();
    test_string_to_pretty_print();

    return 0;
}
