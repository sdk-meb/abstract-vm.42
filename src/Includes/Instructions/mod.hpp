#ifndef MOD_HPP
#define MOD_HPP

#include "interface_instranctions.hpp"

class Mod : public IInstruction {
    public:
        Mod(void) = default;
        Mod(const Mod& other) = default;
        Mod& operator=(const Mod& other) = default;
        virtual ~Mod() = default;

        void execute(std::stack<OperandType>& stack) override;
};

#endif // MOD_HPP