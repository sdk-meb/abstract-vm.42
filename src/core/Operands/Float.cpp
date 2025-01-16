#include <Operands/Float.hpp>

Float::Float(const std::string& value) {

    this->type = eOperandType::Float;
    this->_stringValue = value;
    _value = std::stof(value);
}

Float::~Float(void) {}

int Float::getPrecision(void) const {
    return -1; // TODO: Find out what the precision of a float is
}

eOperandType Float::getType(void) const {
    return  this->type;
}

IOperand const* Float::operator+(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Float::operator-(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Float::operator*(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Float::operator/(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Float::operator%(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

std::string const& Float::toString(void) const {
    return _stringValue;
}
