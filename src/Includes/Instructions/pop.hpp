#ifndef POP_HPP
#define POP_HPP

# include "interface_instranctions.hpp"


class Pop : public IInstruction {

    public:

        Pop(std::stack<const IOperand*> & stack);
        Pop(const Pop& other) = default;

        Pop(const std::string& val);
        Pop& operator=(const Pop& other) = default;
        virtual ~Pop() = default;

        virtual void execute(const IOperand*) {};
        void execute() override;
};

#endif // 