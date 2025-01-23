#if not defined(__OPEARNAD_IMPL_TPP)
#define __OPEARNAD_IMPL_TPP

#include <Operands/operands.hpp>
#include <Operands/operand.tpp>
#include <factory.hpp>


template <typename _OP>
    Operand<_OP>::Operand(std::string const & value, eOperandType type){
        this->_stringValue = (value);
        this->_type = (type);
    }

template <typename _OP>
    Operand<_OP>::Operand(_OP const & value, eOperandType type): _value(value) {
        this->_stringValue = std::to_string(value);
        this->_type = (type);
    }

template <typename _OP>
    int Operand<_OP>::getPrecision() const {
        return static_cast<int>(this->_type);
    }

template <typename _OP>
    eOperandType Operand<_OP>::getType() const {
        return this->_type;
    }

template <typename _OP>
    std::string const& Operand<_OP>::toString() const {
        return this->_stringValue;
    }

template <typename _OP>
    IOperand const* Operand<_OP>::operator+(IOperand const& rhs) const {
        eOperandType resultType = static_cast<eOperandType>(
            std::max(this->getPrecision(), rhs.getPrecision()));

        double result = static_cast<double>(this->_value) + std::stod(rhs.toString());
        return Factory().createOperand(resultType, std::to_string(result));
    }

template <typename _OP>
    IOperand const* Operand<_OP>::operator-(IOperand const& rhs) const {
        eOperandType resultType = static_cast<eOperandType>(
            std::max(this->getPrecision(), rhs.getPrecision()));

        double result = this->_value - std::stod(rhs.toString());
        return Factory().createOperand(resultType, std::to_string(result));
    }

template <typename _OP>
    IOperand const* Operand<_OP>::operator*(IOperand const& rhs) const {
        eOperandType resultType = static_cast<eOperandType>(
            std::max(this->getPrecision(), rhs.getPrecision()));

        double result = this->_value * std::stod(rhs.toString());
        return Factory().createOperand(resultType, std::to_string(result));
    }

template <typename _OP>
    IOperand const* Operand<_OP>::operator/(IOperand const& rhs) const {
        if (std::stod(rhs.toString()) == 0)
            __throw_traced std::domain_error("WARNING: Division by zero > O_operator(o_div) ? Undefined Behavior");

        eOperandType resultType = static_cast<eOperandType>(
            std::max(this->getPrecision(), rhs.getPrecision()));

        double result = this->_value / std::stod(rhs.toString());
        return Factory().createOperand(resultType, std::to_string(result));
    }

template <typename _OP>
    IOperand const* Operand<_OP>::operator%(IOperand const& rhs) const {
        if (std::stod(rhs.toString()) == 0)
            __throw_traced std::domain_error("WARNING: Modulo by zero > O_operator(o_mod) ? Undefined Behavior");

        __int32_t result = static_cast<__int32_t> (this->_value) % std::stoi(rhs.toString());
        return new Operand(result, eOperandType::Int32);
    }

#endif
