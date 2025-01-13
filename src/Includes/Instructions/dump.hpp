#ifndef DUMP_HPP
#define DUMP_HPP

#include "interface_instranctions.hpp"

class Dump : public IInstruction {
    public:
        Dump(void) = default;
        Dump(const Dump& other) = default;
        Dump& operator=(const Dump& other) = default;
        virtual ~Dump() = default;

        void execute(std::stack<eOperandType>& stack) override;
};

#endif // DUMP_HPP