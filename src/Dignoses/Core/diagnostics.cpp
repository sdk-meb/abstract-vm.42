#include <diagnostics.hpp>



InterpretationExept::InterpretationExept(const std::string &message)
    : std::logic_error(message) { }

/**
 * @throw
 *   - no DIAGNOSING define
 * @throw
 *   - unmatched pattern <loglevel>\: <msg> -> <funtype>(<funname>) ? <cause>
 */
const char* InterpretationExept::_tracing_what(const int& line_number) const {

#ifndef DIAGNOSING
        std::cerr << "INFO: No DIAGNOSING define, read more about the abs-vm interpreter!" << std::endl;
        __throw_exception_again std::logic_error(this->what());
#endif
        std::regex pattern(R"(\s*(ERROR|WARNING):\s+(.+?)\s+>\s+(\w+)\((\w+)\)\s*\?\s*(.+)$)");
        std::smatch matches;

        const std::string ex_what = this->what(); 

        if (not std::regex_match(ex_what , matches, pattern)) {

                /**
                 * @attention make sure all abs-vm @exception match the pattern above 
                 */
                __throw_exception_again std::underflow_error(this->what()); // TODO: if it no matched format means the catched exeption is from system not from abs-vm
        }

        Logger::loghandler(line_number, matches);
        return this->what();
}
