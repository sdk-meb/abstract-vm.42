#ifndef PRINT_HPP
#define PRINT_HPP

#include "interface_instranctions.hpp"

class Print : public IInstruction {
    public:
        Print(void) = default;
        Print(const Print& other) = default;
        Print& operator=(const Print& other) = default;
        virtual ~Print() = default;

        void execute() override;
};

#endif // PRINT_HPP