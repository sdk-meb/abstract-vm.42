#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "Operands/IOperand.hpp"
#include <vm.hpp>

class Factory {

        IOperand const *createInt8(std::string const &value) const;
        IOperand const *createInt16(std::string const &value) const;
        IOperand const *createInt32(std::string const &value) const;
        IOperand const *createFloat(std::string const &value) const;
        IOperand const *createDouble(std::string const &value) const;

    public:
        Factory(void) = default;
        Factory(Factory const &src) = default;
        Factory &operator=(Factory const &rhs) = default;
        ~Factory(void) = default;

        IOperand const *createOperand(eOperandType type, std::string const &value) const;
};

#endif // FACTORY_HPP