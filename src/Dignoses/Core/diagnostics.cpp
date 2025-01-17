#include <diagnostics.hpp>



InterpretationExept::InterpretationExept(const std::string &message)
    : std::logic_error(message) {

    }


const char* InterpretationExept::_tracing_what(const int& line_number) const {
#ifndef DIAGNOSING
        std::__throw_logic_error(what());
#endif
        std::regex pattern(R"((\w+):\s*(.+)\s+(\w+)\s+(\w+))"); 
        std::smatch matches;

        const std::string ex_what = this->what(); 

        if (not std::regex_match(ex_what , matches, pattern)) {
                throwgh ("_tracing_what") __ca_tch("noexept: Invalid value format: " + ex_what)
                /**
                 * @attention make sure all abs-vm @exception match the pattern above 
                 */
                __throw_exception_again std::underflow_error(this->what()); // TODO: if it no matched format means the catched exeption is from system not from abs-vm
        }

        Logger::loghandler(line_number, matches);
        return this->what();
}
