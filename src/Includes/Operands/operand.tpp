#ifndef __OPEARNAD_TPP
#define __OPEARNAD_TPP

#include <Operands/_IOperand.hpp>

template <typename _OP>
    class Operand : public IOperand {

        protected:
            _OP _value;

        public:
            Operand(std::string const &, eOperandType);
            Operand(_OP const &, eOperandType);

            int getPrecision() const override ;
            eOperandType getType() const override ;
            std::string const& toString() const override;

            IOperand const* operator+(IOperand const& rhs) const override;
            IOperand const* operator-(IOperand const& rhs) const override;
            IOperand const* operator*(IOperand const& rhs) const override;
            IOperand const* operator/(IOperand const& rhs) const override;
            IOperand const* operator%(IOperand const& rhs) const override;
};

// #include <factory.hpp>
// #include <Operands/operand.tpp>
// #include <Operands/operands.hpp>

#include <factory.hpp>
// #include "operand_impl.tpp"

#endif // __OPEARNAD_TPP
