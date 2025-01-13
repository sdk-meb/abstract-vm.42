#include <Operands/Int32.hpp>

Int32::Int32(const std::string& value) : _stringValue(value) {
    _value = std::stoi(value);
}

Int32::~Int32(void) {}

int Int32::getPrecision(void) const {

    return -1; // TODO: Find out what the precision of a IOperand is
}

eOperandType Int32::getType(void) const {
    return eOperandType::Int32;
}

IOperand const* Int32::operator+(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int32::operator-(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int32::operator*(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int32::operator/(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int32::operator%(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

std::string const& Int32::toString(void) const {
    return _stringValue;
}