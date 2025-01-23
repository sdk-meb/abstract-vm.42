#include <Operands/operands.hpp>



Double::Double(std::string const & value): Operand(value, eOperandType::Double) {

        try {
            _value = std::stod(value);
            this->_stringValue = std::to_string(_value);
        } catch (const std::invalid_argument& e) {
            throw std::invalid_argument("ERROR: Invalid argument > Operand(double) ? Cannot convert [" + value + "] to double.");
        } catch (const std::out_of_range& e) {
            throw std::out_of_range("ERROR: Out of range > Operand(double) ? [" + value + "] is too large or too small for a double.");
        }
}

