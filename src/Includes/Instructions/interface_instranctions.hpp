#ifndef INTERFACE_INSTRUCTIONS_HPP
#define INTERFACE_INSTRUCTIONS_HPP

# include <Operands/_IOperand.hpp>
#include <string>
#include <stack>
#include <iostream>
# include <Utils/mode.hpp>

class IInstruction {

    protected:
        std::stack<const IOperand*> &__stack;

    public:
        IInstruction(std::stack<const IOperand*> &);
        // Canonical form
        IInstruction(void) = default;
        IInstruction(const IInstruction&) = default;
        IInstruction& operator=(const IInstruction&) = default;
        virtual ~IInstruction() = default;

        // Pure virtual function for execution
        virtual void execute(const IOperand*) = 0; // TODO: why the overrifing of this is required?
        virtual void execute() = 0;
};

#endif // INTERFACE_INSTRUCTIONS_HPP