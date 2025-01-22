#ifndef __DIAGNO_HPP
# define __DIAGNO_HPP

#include <stdexcept>
#include <string>
#include <logger.hpp>
#include <regex>
# include <Utils/mode.hpp>

// exception possibly traced
#define __throw_traced throw

// helper for interpreter throw 
#define __throw_interpreter(__e, _l) InterpretationExept(__e)._tracing_what(_l);
class InterpretationExept : public std::logic_error {

    public:
        InterpretationExept(const std::string& message);
        const char*  _tracing_what(const int& line_number) const;

};

#endif
