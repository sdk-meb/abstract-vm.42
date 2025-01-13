#include <Operands/Double.hpp>

Double::Double(const std::string& value): _stringValue (value) {
    _value = std::stod(value);
}

Double::~Double(void) {}

int Double::getPrecision(void) const {
    return -1; // TODO: Find out what the precision of a IOperand is
}

OperandType Double::getType(void) const {
    return OperandType::Double;
}

IOperand const* Double::operator+(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Double::operator-(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Double::operator*(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Double::operator/(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Double::operator%(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

std::string const& Double::toString(void) const {
    return _stringValue;
}