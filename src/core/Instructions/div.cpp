#include <Instructions/div.hpp>

Div::Div (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Div::execute(const IOperand*) {}
/**
 * @brief Executes the division operation on the top two values of the stack.
 * 
 * This method removes the top two elements from the stack, divides the second 
 * value (second from the top) by the first value (top of the stack), and pushes 
 * the result back onto the stack. The operation is performed using the overloaded 
 * division operator for `IOperand` objects.
 * 
 * @exception Throw if the stack contains fewer than two elements 
 *            or if the divisor (top of the stack) is equal to zero.
 * 
 * @note Handles potential issues with floating-point division (e.g., division by a very 
 *       small value may result in large errors). It is important to carefully design 
 *       `IOperand` for precise floating-point arithmetic handling.
 */
void Div::execute() {

    if (this->__stack.size() < 2)
        __throw_traced std::length_error("ERROR: Not enough elements > Instruction(Div) ? stack size");


    if (this->__stack.top()->toString() == "0") 
        __throw_traced std::domain_error("ERROR: Division by zero > Instruction(Div) ? Undefined Behavior");

    const IOperand* operand1 = this->__stack.top();
    this->__stack.pop();
    const IOperand* operand2 = this->__stack.top();
    this->__stack.pop();


    const IOperand* result = *operand2 / *operand1;

    this->__stack.push(result);

    delete operand1;
    delete operand2;
}
