#include <Operands/operands.hpp>



Int16::Int16(std::string const & value): Operand(value, eOperandType::Int16) {

    _value = static_cast<int16_t>(std::stoi(value));
}

