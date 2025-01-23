#include <Operands/operands.hpp>



Float::Float(std::string const & value): Operand(value, eOperandType::Float) {

    try {
        _value = std::stof(value);
        this->_stringValue = std::to_string(_value);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("ERROR: Invalid argument > Operand(float) ? Cannot convert [" + value + "] to float.");
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("ERROR: Out of range > Operand(float) ? [" + value + "] is too large or too small for a float.");
    }
}

