#ifndef DIV_HPP
#define DIV_HPP

#include "interface_instranctions.hpp"

class Div : public IInstruction {
    public:
        Div(void) = default;
        Div(const Div& other) = default;
        Div& operator=(const Div& other) = default;
        virtual ~Div() = default;

        void execute(std::stack<eOperandType>& stack) override;
};

#endif // DIV_HPP