#include <Operands/Int8.hpp>


Int8::Int8(const std::string& value) : _stringValue(value) {
    _value = static_cast<int8_t>(std::stoi(value));
}

Int8::~Int8(void) {}

int Int8::getPrecision(void) const {
    return 0;
}

OperandType Int8::getType(void) const {
    return OperandType(0);
}

IOperand const* Int8::operator+(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int8::operator-(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int8::operator*(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int8::operator/(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

IOperand const* Int8::operator%(IOperand const& rhs) const {
    (void) rhs;
    return this;
}

std::string const& Int8::toString(void) const {
    return _stringValue;
}