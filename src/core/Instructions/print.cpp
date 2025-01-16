#include <Instructions/print.hpp>


Print::Print (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Print::execute () {

    if (this->__stack.empty())
        std::__throw_underflow_error("Print failed: stack is empty."); // TODO: not sure or just ignore command

    const IOperand* topElement = this->__stack.top();
    if (topElement->getType() not_eq eOperandType::Int8)
        std::__throw_invalid_argument("Print failed: top of stack is not an 8-bit integer.");

    int asciiValue = std::stoi(topElement->toString()); // toascii
    // if (asciiValue < 0 || asciiValue > 255)  // not # TODO : this error must be tracked in parssing trac
        // throw std::out_of_range("Print failed: value out of range for an 8-bit integer."); 

    std::cout << '[' + static_cast<char>(asciiValue) + ']';
    if (not std::isprint(asciiValue))
        std::cout << "-Non-Printable" << std::endl;
}