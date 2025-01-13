#ifndef ADD_HPP
#define ADD_HPP

# include "interface_instranctions.hpp"


class Add : public IInstruction {

    public:
        Add(void) = default;
        Add(const Add& other) = default;
        Add& operator=(const Add& other) = default;
        virtual ~Add() = default;

        void execute() override;
};

#endif // 