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

    if (this->__stack.empty())
        throw InterpretationExept("ERROR: stack is empty -> Instruction(Pop)");
    this->__stack.pop();
}