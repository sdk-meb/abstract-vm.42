#ifndef ADD_HPP
#define ADD_HPP

# include "interface_instranctions.hpp"


class Add : public IInstruction {

    public:

        Add(std::stack<const IOperand*> & stack);
        Add(const Add& other) = default;

        Add(const std::string& val);
        Add& operator=(const Add& other) = default;
        virtual ~Add() = default;

        virtual void execute(const IOperand*);
        void execute() override;
};

#endif // 