#include <Instructions/dump.hpp>

Dump::Dump (std::stack<const IOperand*>& stack): IInstruction(stack) {}

void Dump::execute(const IOperand*) {}
/**
 * @brief Dumps the contents of the stack from the most recent to the oldest.
 *        It prints each element's type and value, without modifying the stack.
 * 
 *  its string representation (value) in the format: `type(value)`.
 * 
 * 
 * @bug No known bugs. Ensure that `toString()` and `getType()` methods in `IOperand`
 *       are implemented correctly.
 * 
 */
void Dump::execute() {

    std::stack<const IOperand*> tempStack = this->__stack;

    while (not tempStack.empty()) {
        const IOperand* topElement = tempStack.top();
        auto type = "Unknown";
        switch (topElement->getType()) {
            case eOperandType::Int8: type = "Int8" ; break;;
            case eOperandType::Int16: type = "Int16"; break;;
            case eOperandType::Int32: type = "Int32"; break;;
            case eOperandType::Float: type = "Float"; break;;
            case eOperandType::Double: type = "Double"; break;;
        }
        std::cout << type << "(" << topElement->toString() << ")" << std::endl;
        tempStack.pop();
    }
}