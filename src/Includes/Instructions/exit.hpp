#ifndef EXIT_HPP
#define EXIT_HPP

#include "interface_instranctions.hpp"

class Exit : public IInstruction {
    public:
        Exit(void) = default;
        Exit(const Exit& other) = default;
        Exit& operator=(const Exit& other) = default;

        void execute(std::stack<__OperandType>& stack) override;
        ~Exit() { std::exit(0);};
};

#endif // EXIT_HPP