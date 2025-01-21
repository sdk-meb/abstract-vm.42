#include <Instructions/print.hpp>


Print::Print (std::stack<const IOperand*>& stack): IInstruction(stack) {}


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
        throw InterpretationExept("ERROR: Stack is empty -> Instruction(Print)");

    const IOperand* operand = this->__stack.top();


    if (operand->getType() not_eq eOperandType::Int8)
        throw InterpretationExept("ERROR: The value at the top of the stack is not an 8-bit integer -> Instruction(Print)");


    char asciiValue = std::stoi(operand->toString());

    std::cout << '[' << (asciiValue) << ']';
    if (not std::isprint(asciiValue))
        std::cout << "-Non-Printable";
    std::cout << std::endl;
}
