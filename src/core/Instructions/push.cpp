#include <Instructions/push.hpp>

Push::Push (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Push::execute (const IOperand* val) {
    this->__stack.push(val);
}