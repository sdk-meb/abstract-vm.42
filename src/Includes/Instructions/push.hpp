#ifndef PUSH_HPP
#define PUSH_HPP

#include "interface_instranctions.hpp"

class Push : public IInstruction {
    public:
        Push(void) = default;
        Push(const Push& other) = default;

        Push(const std::string& val);
        Push& operator=(const Push& other) = default;
        virtual ~Push() = default;

        void execute() override;
};

#endif // PUSH_HPP