#include <Instructions/sub.hpp>


Sub::Sub (std::stack<const IOperand*>& stack): IInstruction(stack) {}

/**
 * @brief Executes the subtraction operation on the top two values of the stack.
 * 
 * This method removes the top two elements from the stack, subtracts the second 
 * value (second from the top) from the first value (top of the stack), and pushes 
 * the result back onto the stack. The operation is performed using the overloaded 
 * subtraction operator for `IOperand` objects.
 * 
 * @exception Throw if the stack contains fewer than two elements 
 *            at the time of execution.
 * 
 * @note The method assumes ownership of the top two elements and ensures 
 *       proper memory management by deleting them after use.
 */
void Sub::execute() {

    if (this->__stack.size() < 2)
        throw InterpretationExept("ERROR: Not enough elements on the stack -> Instruction(Sub)");

    const IOperand* operand1 = this->__stack.top();
    this->__stack.pop();
    const IOperand* operand2 = this->__stack.top();
    this->__stack.pop();

    const IOperand* result = *operand2 - *operand1;

    this->__stack.push(result);

    delete operand1;
    delete operand2;
}
