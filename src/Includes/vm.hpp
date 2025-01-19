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
 * @include Operands
 */
#include <Operands/Int8.hpp>
#include <Operands/Int16.hpp>
#include <Operands/Int32.hpp>
#include <Operands/Float.hpp>
#include <Operands/Double.hpp>
#include <factory.hpp>


/**
 *  @include diagnostics
 */
#include <diagnostics.hpp>

/**
 * @include utils
 */
#include <Utils/mode.hpp>


/**
 * @brief The main class for the abstract vm
 * 
 * @details
 * This class is responsible for the main functionality of the abstract vm
 * 
 */
class absvm {
    
        std::stack<const IOperand*> stack;
        void interpret(const std::string &);
        std::pair<eOperandType, std::string> interpretValueFormat(const std::string& value_format); // Fix declaration

    protected:
        void shell();
        void processLines(std::istream& );
        void interpretsource(const std::ifstream &);
        void delete_stack();

    public:
        absvm();
        absvm(const std::string&);
        ~absvm();
};


#endif // abs_vm
