#include <Operands/operands.hpp>



Int32::Int32(std::string const & value): Operand(value, eOperandType::Int32) {

    try {
        int intValue = std::stoi(value);

        _value = static_cast<int32_t>(intValue);
        this->_stringValue = std::to_string(_value);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("ERROR: Invalid argument > Operand(Int32) ? Cannot convert [" + value + "] to integer.");
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("ERROR: Out of range > Operand(Int32) ? [" + value + "] is too large or too small for a Int32.");
    }
}

