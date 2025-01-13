#ifndef INTERFACE_INSTRUCTIONS_HPP
#define INTERFACE_INSTRUCTIONS_HPP

#include <string>
#include <stack>

typedef int OperandType; // TODO temporary
class IInstruction {
    public:
        // Canonical form
        IInstruction(void) = default;
        IInstruction(const IInstruction& other) = default;
        IInstruction& operator=(const IInstruction& other) = default;
        virtual ~IInstruction() = default;

        // Pure virtual function for execution
        virtual void execute(std::stack<OperandType> & stack) = 0;
};

#endif // INTERFACE_INSTRUCTIONS_HPP