#if not defined(abs_vm)
#define abs_vm

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <functional>
#include <sstream>
#include <unordered_set>


/**
 * @include Instructions
 */
#include <Instructions/push.hpp>
#include <Instructions/assert.hpp>
#include <Instructions/pop.hpp>
#include <Instructions/dump.hpp>
#include <Instructions/add.hpp>
#include <Instructions/sub.hpp>
#include <Instructions/mul.hpp>
#include <Instructions/div.hpp>
#include <Instructions/mod.hpp>
#include <Instructions/print.hpp>
#include <Instructions/exit.hpp>


#include <factory.hpp>


/**
 *  @include diagnostics
 */
#include <diagnostics.hpp>

/**
 * @include utils
 */
#include <Utils/parsser.hpp>


/**
 * @brief The main class for the abstract vm
 * 
 * @details
 * This class is responsible for the main functionality of the abstract vm
 * 
 */
class absvm {
    
        std::stack<const IOperand*> stack;
        void interpret(const std::string&);
        auto commands(const std::string&);

    protected:
        void processLines(std::ifstream&);
        void processLines(std::istream&);
        void delete_stack();

    public:
        absvm();
        absvm(const std::string&);
        ~absvm();
};


#endif // abs_vm
