#include <Instructions/print.hpp>


Print::Print (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Print::execute(const IOperand*)  { }
/**
 * @brief Prints the character corresponding to the ASCII value at the top of the stack.
 * 
 * This method checks if the top value of the stack is an 8-bit integer. If the value 
 * is valid, it interprets it as an ASCII value and prints the corresponding character 
 * inside square brackets. If the character is non-printable, it adds the suffix "-Non-Printable".
 * If the value is not an 8-bit integer, the program halts with an error.
 * 
 * @exception Throw if the value at the top of the stack is not 
 *            an 8-bit integer.
 */
void Print::execute() {

    if (this->__stack.empty())
        __throw_traced std::length_error("ERROR: Stack is empty > Instruction(Print) ? no element to print");

    const IOperand* operand = this->__stack.top();


    if (operand->getType() not_eq eOperandType::Int8)
        __throw_traced std::logic_error("ERROR: Cannot print value > Instruction(Print) ? not an 8-bit integer");


    char asciiValue = std::stoi(operand->toString());

    std::cout << '[' << (asciiValue) << ']';
    if (not std::isprint(asciiValue))
        std::cout << "-Non-Printable";
    std::cout << std::endl;
}
