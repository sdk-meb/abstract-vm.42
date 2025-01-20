#include <Instructions/assert.hpp>

Assert::Assert(std::stack<const IOperand *> &stack) : IInstruction(stack) {}

/**
 * @brief Asserts that the value at the top of the stack is equal to the one passed 
 * as a parameter to this instruction. If the assertion fails, the program execution 
 * is halted with an error. The value `v` must have the same form as those passed 
 * to the `push` instruction.
 * 
 * @param 
 *  val Pointer to an instance of the IOperand class representing the value 
 *  to compare against the top of the stack.
 * 
 * @exception main gol logic_error Thrown
 *  - The stack is empty. (__throw_out_of_range)
 *  - The value at the top of the stack does not match the specified value `val` 
 *    in both type and value.
 * 
 */
void Assert::execute(const IOperand* val) {

    if (this->__stack.empty())
        InterpretationExept("Failed: stack is empty -> Instruction(Assert)");

    const IOperand* top = this->__stack.top();
    if (top->toString() not_eq val->toString())
        InterpretationExept("Worning: incompatible values -> Instruction(Assert)");
    if (top->getType() not_eq val->getType())
        InterpretationExept("Worning: incompatible types -> Instruction(Assert)");

}