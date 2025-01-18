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
void Assert::execute(const IOperand *val) {

    if (this->__stack.empty())
        std::__throw_out_of_range("Assertion failed: stack is empty.");

    const IOperand *top = this->__stack.top(); // TODO: smatch pattern of logger
    if (top->toString() != val->toString() || top->getType() != val->getType())
        std::__throw_logic_error(("Assertion failed: expected " +
                                  std::to_string(static_cast<int>(val->getType())) +
                                  "/bit with value " + val->toString() +
                                  ", but got " +
                                  std::to_string(static_cast<int>(top->getType())) +
                                  "/bit with value " + top->toString())
                                     .c_str());
}