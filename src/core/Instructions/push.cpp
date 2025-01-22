#include <Instructions/push.hpp>

Push::Push (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Push::execute(const IOperand* val) {
    if (not val)
        std::__throw_underflow_error("Push failed: null operand provided"); // never , other ways parseer error

    this->__stack.push(val);
}
