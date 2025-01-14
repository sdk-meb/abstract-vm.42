#ifndef DIV_HPP
#define DIV_HPP

#include "interface_instranctions.hpp"

class Div : public IInstruction {

    public:
        Div(std::stack<IOperand> & stack);
        Div(const Div& other) = default;

        Div(const std::string& val);
        Div& operator=(const Div& other) = default;
        virtual ~Div() = default;

        virtual void execute(const IOperand*) {};
        void execute() override;
};

#endif // DIV_HPP