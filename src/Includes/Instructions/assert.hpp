#ifndef ASSERT_HPP
#define ASSERT_HPP

#include "interface_instranctions.hpp"

class Assert : public IInstruction {
    public:
        Assert(void) = default;
        Assert(const Assert& other) = default;

        Assert(const std::string& val);
        Assert& operator=(const Assert& other) = default;
        virtual ~Assert() = default;

        void execute(std::stack<OperandType>& stack) override;
};

#endif // ASSERT_HPP