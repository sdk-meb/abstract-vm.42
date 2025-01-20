#include <Operands/operands.hpp>



Float::Float(std::string const & value): Operand(value, eOperandType::Float) {

    _value = std::stof(value);
}

