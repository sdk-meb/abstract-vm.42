#include <Operands/operands.hpp>



Int8::Int8(std::string const & value): Operand(value, eOperandType::Int8) {

    try {
        int intValue = std::stoi(value);
        if (intValue < std::numeric_limits<int8_t>::min() or intValue > std::numeric_limits<int8_t>::max())
            throw std::out_of_range("ERROR: Out of range > Operand(Int8) ? [" + value + "] is too large or too small for a int_8.");

        _value = static_cast<int8_t>(intValue);
        this->_stringValue = std::to_string(_value);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("ERROR: Invalid argument > Operand(Int8) ? Cannot convert [" + value + "] to integer.");
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("ERROR: Out of range > Operand(Int8) ? [" + value + "] is too large or too small for a Int8.");
    }
}

