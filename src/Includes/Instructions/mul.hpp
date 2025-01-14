#ifndef MUL_HPP
#define MUL_HPP

#include "interface_instranctions.hpp"

class Mul : public IInstruction {

    public:
        Mul(std::stack<const IOperand*> & stack);
        Mul(const Mul& other) = default;

        Mul(const std::string& val);
        Mul& operator=(const Mul& other) = default;
        virtual ~Mul() = default;


        virtual void execute(const IOperand*);
        void execute() override;
};

#endif // MUL_HPP