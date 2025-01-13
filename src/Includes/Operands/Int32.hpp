#ifndef INT32_HPP
#define INT32_HPP

#include "IOperand.hpp"

class Int32 : public IOperand {

    int32_t _value;
    std::string _stringValue;

    public:
    Int32(const std::string& value);
    virtual ~Int32(void);

    virtual int getPrecision(void) const;
    virtual eOperandType getType(void) const;
    virtual IOperand const* operator+(IOperand const& rhs) const;
    virtual IOperand const* operator-(IOperand const& rhs) const;
    virtual IOperand const* operator*(IOperand const& rhs) const;
    virtual IOperand const* operator/(IOperand const& rhs) const;
    virtual IOperand const* operator%(IOperand const& rhs) const;
    virtual std::string const& toString(void) const;
};

#endif // INT32_HPP