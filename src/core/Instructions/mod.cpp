#include <Instructions/mod.hpp>



Mod::Mod (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Mod::execute(const IOperand*)  { }
/**
 * @brief Executes the modulus operation on the top two values of the stack.
 * 
 * This method removes the top two elements from the stack, calculates the modulus 
 * of the second value (second from the top) by the first value (top of the stack), 
 * and pushes the result back onto the stack. The operation is performed using the 
 * overloaded modulus operator for `IOperand` objects.
 * 
 * @exception Throw if the stack contains fewer than two elements 
 *            or if the divisor (top of the stack) is equal to zero.
 * 
 * @note Similar to division, the modulus operation may encounter issues with floating-point 
 *       values. Specifically, modulus by a very small number or zero can lead to undefined 
 *       behavior. Ensure that `IOperand` is designed to handle such cases robustly.
 */
void Mod::execute() {

    if (this->__stack.size() < 2)
        throw InterpretationExept("ERROR: Not enough elements on the stack -> Instruction(Mod)");


    if (this->__stack.top()->toString() == "0")
        throw InterpretationExept("ERROR: Modulus by zero -> Instruction(Mod)");

    const IOperand* operand1 = this->__stack.top();
    this->__stack.pop();
    const IOperand* operand2 = this->__stack.top();
    this->__stack.pop();

    const IOperand* result = *operand2 % *operand1;

    this->__stack.push(result);

    delete operand1;
    delete operand2;
}
