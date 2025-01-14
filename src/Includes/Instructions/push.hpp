#ifndef PUSH_HPP
#define PUSH_HPP

#include "interface_instranctions.hpp"

class Push : public IInstruction {

    public:
        Push(std::stack<IOperand> & stack);
        Push(const Push& other) = default;

        Push(const std::string& val);
        Push& operator=(const Push& other) = default;
        virtual ~Push() = default;

        void execute(const IOperand* val) override;
};

#endif // PUSH_HPP