#include <Instructions/assert.hpp>

Assert::Assert (std::stack<const IOperand*>& stack): IInstruction(stack) {}


void Assert::execute (const IOperand* val) {
    (void) val;
    // this->__stack.push(*val);
}