#ifndef ASSERT_HPP
#define ASSERT_HPP

#include "interface_instranctions.hpp"

class Assert : public IInstruction {

    public:
        Assert(std::stack<IOperand> & stack);
        Assert(const Assert& other) = default;

        Assert(const std::string& val);
        Assert& operator=(const Assert& other) = default;
        virtual ~Assert() = default;

        void execute(const IOperand*) override;
};

#endif // ASSERT_HPP