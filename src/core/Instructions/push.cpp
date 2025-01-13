#include <Instructions/push.hpp>

Push::Push(const std::string &val)
{
    (void)(val);
}

void Push::execute(std::stack<eOperandType>& stack) {
    (void)stack;
}