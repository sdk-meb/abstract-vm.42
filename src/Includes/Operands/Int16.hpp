#ifndef INT16_HPP
#define INT16_HPP

#include "IOperand.hpp"

class Int16 : public IOperand {

    int16_t _value;
    std::string _stringValue;

    public:
    Int16(const std::string& value);
    virtual ~Int16(void);

    virtual int getPrecision(void) const;
    virtual eOperandType getType(void) const;
    virtual IOperand const* operator+(IOperand const& rhs) const;
    virtual IOperand const* operator-(IOperand const& rhs) const;
    virtual IOperand const* operator*(IOperand const& rhs) const;
    virtual IOperand const* operator/(IOperand const& rhs) const;
    virtual IOperand const* operator%(IOperand const& rhs) const;
    virtual std::string const& toString(void) const;
};

#endif // INT16_HPP