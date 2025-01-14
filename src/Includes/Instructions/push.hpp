#ifndef PUSH_HPP
#define PUSH_HPP

#include "interface_instranctions.hpp"

class Push : public IInstruction {

    public:
        Push(std::stack<const IOperand*> & stack);

        Push(const std::string& val);
        void execute(const IOperand* val) ;

        void execute() {};
};

#endif // PUSH_HPP