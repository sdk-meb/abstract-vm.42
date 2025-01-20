#ifndef __DIAGNO_HPP
# define __DIAGNO_HPP

#include <stdexcept>
#include <string>
#include <logger.hpp>
#include <regex>
# include <Utils/mode.hpp>

class InterpretationExept : public std::logic_error {

    public:
        InterpretationExept(const std::string& message);
        const char*  _tracing_what(const int& line_number) const;

};

#endif
