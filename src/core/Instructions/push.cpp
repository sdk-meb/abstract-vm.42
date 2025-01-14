#include <Instructions/push.hpp>

Push::Push (std::stack<IOperand>& stack): IInstruction(stack) {}

void Push::execute (const IOperand* val) {

    (void) val;
    // this->__stack.push(*val);
}