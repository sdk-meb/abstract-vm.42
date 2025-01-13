#ifndef POP_HPP
#define POP_HPP

# include "interface_instranctions.hpp"


class Pop : public IInstruction {

    public:
        Pop(void) = default;
        Pop(const Pop& other) = default;
        Pop& operator=(const Pop& other) = default;
        virtual ~Pop() = default;

        void execute(std::stack<__OperandType>& stack) override;
};

#endif // 