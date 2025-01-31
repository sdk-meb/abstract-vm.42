#include <Instructions/assert.hpp>

Assert::Assert(std::stack<const IOperand *> &stack) : IInstruction(stack) {}

void Assert::execute() {}
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
        __throw_traced std::length_error("ERROR: Stack length > Instruction(Assert) ? stack empty");

    const IOperand* top = this->__stack.top();

    if (top->getType() not_eq val->getType())
        __throw_traced std::domain_error("WARNING: Incompatible types > Instruction(Assert) ? " + eOperandstoString(top->getType()) + " is not " + eOperandstoString(val->getType()));

    const double v_top = stod(top->toString());
    const double v_val = stod(val->toString());

    if (v_top not_eq v_val)
        __throw_traced std::domain_error("WARNING: Incompatible values > Instruction(Assert) ? " + top->toString() + " not eq " + val->toString());

}