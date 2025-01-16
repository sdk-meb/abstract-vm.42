#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "IOperand.hpp"

class Double : public IOperand {

    protected:
        double _value;

    public:
        Double(const std::string& value);
        virtual ~Double(void);

        virtual int getPrecision(void) const;
        virtual eOperandType getType(void) const;
        virtual IOperand const* operator+(IOperand const& rhs) const;
        virtual IOperand const* operator-(IOperand const& rhs) const;
        virtual IOperand const* operator*(IOperand const& rhs) const;
        virtual IOperand const* operator/(IOperand const& rhs) const;
        virtual IOperand const* operator%(IOperand const& rhs) const;
        virtual std::string const& toString(void) const;
};

#endif // DOUBLE_HPP