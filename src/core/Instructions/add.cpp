
#include <Instructions/add.hpp>
// #include "../Factory/Factory.hpp"
#include <stdexcept>

void Add::execute(std::stack<OperandType>& stack) {
    (void)stack;
    // if (Factory::getInstance().getStack().size() < 2) {
    //     throw std::runtime_error("Error: Not enough operands for add operation");
    // }

    // IOperand const* val1 = Factory::getInstance().getStack().top();
    // Factory::getInstance().getStack().pop();
    // IOperand const* val2 = Factory::getInstance().getStack().top();
    // Factory::getInstance().getStack().pop();

    // IOperand const* result = *val2 + *val1;
    // Factory::getInstance().getStack().push(result);

    // delete val1;
    // delete val2;
}