#include <Instructions/pop.hpp>

Pop::Pop (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Pop::execute () {

}