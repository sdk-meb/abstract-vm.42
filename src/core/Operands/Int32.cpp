#include <Operands/operands.hpp>



Int32::Int32(std::string const & value): Operand(value, eOperandType::Int32) {

    _value = std::stoi(value);
}

