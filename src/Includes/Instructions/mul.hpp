#ifndef MUL_HPP
#define MUL_HPP

#include "interface_instranctions.hpp"

class Mul : public IInstruction {
    public:
        Mul(void) = default;
        Mul(const Mul& other) = default;
        Mul& operator=(const Mul& other) = default;
        virtual ~Mul() = default;

        void execute(std::stack<eOperandType>& stack) override;
};

#endif // MUL_HPP