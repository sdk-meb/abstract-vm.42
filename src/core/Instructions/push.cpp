#include <Instructions/push.hpp>

Push::Push (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Push::execute(const IOperand* val) {
    if (not val)
        std::__throw_invalid_argument("Push failed: null operand provided.");

    try { this->__stack.push(val);
    } catch (const std::exception&) {
        std::__throw_bad_alloc();
    }
}
