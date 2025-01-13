#ifndef FLOAT_HPP
#define FLOAT_HPP

#include "IOperand.hpp"

class Float : public IOperand {
    private:
        float _value;
        std::string _stringValue;

    public:
        Float(const std::string& value);
        virtual ~Float(void);

        virtual int getPrecision(void) const;
        virtual eOperandType getType(void) const;
        virtual IOperand const* operator+(IOperand const& rhs) const;
        virtual IOperand const* operator-(IOperand const& rhs) const;
        virtual IOperand const* operator*(IOperand const& rhs) const;
        virtual IOperand const* operator/(IOperand const& rhs) const;
        virtual IOperand const* operator%(IOperand const& rhs) const;
        virtual std::string const& toString(void) const;
};

#endif // FLOAT_HPP