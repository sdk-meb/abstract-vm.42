#include <Instructions/exit.hpp>

Exit::Exit(std::stack<IOperand> &stack) : IInstruction(stack) {}

Exit::~Exit() { std::exit(0); }

void Exit::execute()  { }

