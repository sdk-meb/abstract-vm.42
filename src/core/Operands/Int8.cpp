#include <Operands/operands.hpp>



Int8::Int8(std::string const & value): Operand(value, eOperandType::Int8) {

    _value = static_cast<int8_t>(std::stoi(value));
}

