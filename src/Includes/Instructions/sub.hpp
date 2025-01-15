#ifndef SUB_HPP
#define SUB_HPP

#include "interface_instranctions.hpp"

class Sub : public IInstruction {

    public:
        Sub(std::stack<const IOperand*> & stack);
        Sub(const Sub& other) = default;

        Sub(const std::string& val);
        Sub& operator=(const Sub& other) = default;
        virtual ~Sub() = default;

        virtual void execute(const IOperand*) {};
        void execute() override;
};

#endif // SUB_HPP