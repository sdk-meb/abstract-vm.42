#ifndef SUB_HPP
#define SUB_HPP

#include "interface_instranctions.hpp"

class Sub : public IInstruction {
    public:
        Sub(void) = default;
        Sub(const Sub& other) = default;
        Sub& operator=(const Sub& other) = default;
        virtual ~Sub() = default;

        void execute(std::stack<eOperandType>& stack) override;
};

#endif // SUB_HPP