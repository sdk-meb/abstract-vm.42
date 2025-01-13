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
        Factory(void);
        Factory(Factory const &src);
        Factory &operator=(Factory const &rhs);
        ~Factory(void);

        IOperand const *createOperand(eOperandType type, std::string const &value) const;
};

#endif // FACTORY_HPP