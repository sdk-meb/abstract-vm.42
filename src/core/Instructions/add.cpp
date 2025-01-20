#include <Instructions/add.hpp>


Add::Add (std::stack<const IOperand*>& stack): IInstruction(stack) {}

/**
 * @brief Executes the addition operation on the top two values of the stack.
 * 
 * This method removes the top two elements from the stack, adds their values, 
 * and pushes the result back onto the stack. The operation is performed using 
 * the overloaded addition operator for `IOperand` objects.
 * 
 * @exception Thrown if the stack contains fewer than two elements 
 *            at the time of execution.
 * 
 * @note The method assumes ownership of the top two elements and ensures 
 *       proper memory management by deleting them after use
 */
void Add::execute() {

    if (this->__stack.size() < 2)
        throw InterpretationExept("ERROR: Not enough elements on the stack -> Instruction(Add)");

    const IOperand* operand1 = this->__stack.top();
    this->__stack.pop();
    const IOperand* operand2 = this->__stack.top();
    this->__stack.pop();

    const IOperand* result = *operand2 + *operand1;

    this->__stack.push(result);

    delete operand1;
    delete operand2;
}
