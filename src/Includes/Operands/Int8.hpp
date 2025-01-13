#ifndef INT8_HPP
#define INT8_HPP

#include "IOperand.hpp"

class Int8 : public IOperand {

        std::string _stringValue;

    protected:
        __int8_t    _value;

    public:
        Int8(const std::string&);
        virtual ~Int8();

        virtual int getPrecision() const;
        virtual OperandType getType() const;

        virtual IOperand const* operator+(IOperand const&) const;
        virtual IOperand const* operator-(IOperand const&) const;
        virtual IOperand const* operator*(IOperand const&) const;
        virtual IOperand const* operator/(IOperand const&) const;
        virtual IOperand const* operator%(IOperand const&) const;

        virtual std::string const& toString() const;
};

#endif // INT8_HPP