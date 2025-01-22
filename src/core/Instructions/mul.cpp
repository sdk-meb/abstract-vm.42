#include <Instructions/mul.hpp>


Mul::Mul (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Mul::execute(const IOperand*) { }
/**
 * @brief Executes the multiplication operation on the top two values of the stack.
 * 
 * This method removes the top two elements from the stack, multiplies their values, 
 * and pushes the result back onto the stack. The operation is performed using the 
 * overloaded multiplication operator for `IOperand` objects.
 * 
 * @exception  Throw if the stack contains fewer than two elements 
 *            at the time of execution.
 * 
 * @note The method assumes ownership of the top two elements and ensures 
 *       proper memory management by deleting them after use.
 */
void Mul::execute() {

    if (this->__stack.size() < 2)
        __throw_traced std::length_error("ERROR: Not enough elements > Instruction(Mul) ? stack length");

    const IOperand* operand1 = this->__stack.top();
    this->__stack.pop();
    const IOperand* operand2 = this->__stack.top();
    this->__stack.pop();

    const IOperand* result = *operand2 * *operand1;

    this->__stack.push(result);

    delete operand1;
    delete operand2;
}
