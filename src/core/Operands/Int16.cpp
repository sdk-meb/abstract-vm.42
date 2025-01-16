#include <Operands/Int16.hpp>



Int16::Int16(const std::string& value) {

    this->type = eOperandType::Int16;
    this->_stringValue = value;
    _value = static_cast<int16_t>(std::stoi(value));
}

Int16::~Int16(void) {}

int Int16::getPrecision(void) const {

    return -1; // TODO: Find out what the precision of a IOperand is
}

eOperandType Int16::getType(void) const {
    return  this->type;
}

IOperand const* Int16::operator+(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int16::operator-(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int16::operator*(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int16::operator/(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int16::operator%(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

std::string const& Int16::toString(void) const {
    return _stringValue;
}