#include <Instructions/pop.hpp>

Pop::Pop (std::stack<const IOperand*>& stack): IInstruction(stack) {}

/**
 * @attention
 * Calling pop without deleting the top element can cause a memory leak.
 * Ensure that the top element is properly deleted if it was dynamically allocated.
 * 
 * @exception
 *  see `stack` pop throw
 */
void Pop::execute () { 

    // if (this->__stack.empty())
    //     std::__throw_underflow_error("Pop failed: stack is empty.");
    this->__stack.pop();
}