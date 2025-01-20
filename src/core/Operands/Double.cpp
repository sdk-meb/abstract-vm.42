#include <Operands/operands.hpp>



Double::Double(std::string const & value): Operand(value, eOperandType::Double) {

    _value = std::stod(value);
}

