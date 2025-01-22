#include <Instructions/interface_instranctions.hpp>

IInstruction::IInstruction(std::stack<const IOperand*> &stack): __stack(stack) {}