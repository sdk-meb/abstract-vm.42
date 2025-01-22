#ifndef DUMP_HPP
#define DUMP_HPP

#include "interface_instranctions.hpp"

class Dump : public IInstruction {

    public:

        Dump(std::stack<const IOperand*> & stack);
        Dump(const Dump& other) = default;

        Dump(const std::string& val);
        Dump& operator=(const Dump& other) = default;
        virtual ~Dump() = default;

        virtual void execute(const IOperand*);
        void execute() override;
};

#endif // DUMP_HPP