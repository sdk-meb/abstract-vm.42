#ifndef PRINT_HPP
#define PRINT_HPP

#include "interface_instranctions.hpp"

class Print : public IInstruction {

    public:
        Print(std::stack<const IOperand*> & stack);
        Print(const Print& other) = default;

        Print(const std::string& val);
        Print& operator=(const Print& other) = default;
        virtual ~Print() = default;


        virtual void execute(const IOperand*);
        void execute() override;
};

#endif // PRINT_HPP