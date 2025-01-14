#ifndef EXIT_HPP
#define EXIT_HPP

#include "interface_instranctions.hpp"

class Exit : public IInstruction {

    public:
        Exit(std::stack<const IOperand*> & stack);
        Exit(const Exit& other) = default;

        Exit& operator=(const Exit& other) = default;

        ~Exit() override;

        virtual void execute(const IOperand*) {};
        void execute() override;
};

#endif // EXIT_HPP