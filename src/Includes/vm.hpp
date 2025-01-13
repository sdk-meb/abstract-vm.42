#if not defined(abs_vm)
#define abs_vm

#include <iostream>
#include <string>
#include <fstream>
#include <stack>

#include <functional>
#include <sstream>

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


/**
 * @brief The main class for the abstract vm
 * 
 * @details
 * This class is responsible for the main functionality of the abstract vm
 * 
 */
class absvm {
    
        std::stack<eOperandType> stack;
        void interpret(const std::string &);

    protected:
        void shell();
        void processLines(std::istream& );
        void interpretsource(const std::ifstream &);

    public:
        absvm();
        absvm(const std::string&);
        ~absvm() = default;
};


#endif // abs_vm
