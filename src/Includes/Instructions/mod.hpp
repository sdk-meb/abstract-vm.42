#ifndef MOD_HPP
#define MOD_HPP

#include "interface_instranctions.hpp"

class Mod : public IInstruction {

    public:
        Mod(std::stack<const IOperand*> & stack);
        Mod(const Mod& other) = default;

        Mod(const std::string& val);
        Mod& operator=(const Mod& other) = default;
        virtual ~Mod() = default;

        virtual void execute(const IOperand*);
        void execute() override;
};

#endif // MOD_HPP