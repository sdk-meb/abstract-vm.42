#include <Instructions/mul.hpp>


Mul::Mul (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Mul::execute(const IOperand*) {};

void Mul::execute () {

}