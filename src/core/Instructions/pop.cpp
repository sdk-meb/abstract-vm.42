#include <Instructions/pop.hpp>

Pop::Pop (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Pop::execute(const IOperand*)  { }
/**
 * @attention
 * Calling pop without deleting the top element can cause a memory leak.
 * Ensure that the top element is properly deleted if it was dynamically allocated.
 * 
 * @exception
 *  see `stack` pop throw
 */
void Pop::execute () { 

    if (this->__stack.empty())
        __throw_traced std::length_error("ERROR: Stack is empty > Instruction(Pop) ? msg");

    this->__stack.pop();
}