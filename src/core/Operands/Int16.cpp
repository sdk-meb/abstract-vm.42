#include <Operands/operands.hpp>



Int16::Int16(std::string const & value): Operand(value, eOperandType::Int16) {

    try {
        int intValue = std::stoi(value);
        if (intValue < std::numeric_limits<int16_t>::min() or intValue > std::numeric_limits<int16_t>::max())
            throw std::out_of_range("ERROR: Out of range > Operand(Int16) ? [" + value + "] is too large or too small for a int_16.");

        _value = static_cast<int16_t>(intValue);
        this->_stringValue = std::to_string(_value);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("ERROR: Invalid argument > Operand(Int16) ? Cannot convert [" + value + "] to integer.");
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("ERROR: Out of range > Operand(Int16) ? [" + value + "] is too large or too small for a Int16.");
    }
}

