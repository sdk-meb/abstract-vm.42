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
// #include <push.hpp>
// #include <assert.hpp>
// #include <pop.hpp>
// #include <dump.hpp>
// #include <add.hpp>
// #include <sub.hpp>
// #include <mul.hpp>
// #include <div.hpp>
// #include <mod.hpp>
// #include <print.hpp>
// #include <exit.hpp>


/**
 * @brief The main class for the abstract vm
 * 
 * @details
 * This class is responsible for the main functionality of the abstract vm
 * 
 */
class absvm {
    
        std::stack<std::string> stack;
        void shell();
        void processLines(std::istream& );
        void interpret(const std::string &);
        void interpretsource(const std::ifstream &);
    public:
        absvm();
        absvm(const std::string&);
        ~absvm() = default;
};


#endif // abs_vm
