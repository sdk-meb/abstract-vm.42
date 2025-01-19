#include <vm.hpp>


absvm::absvm() { this->shell(); }

/** 
 * @note ... # TODO: std::stack<std::unique_ptr<IOperand>> stack; or std::shared_ptr
 */
absvm::~absvm() { delete_stack(); }

void absvm::delete_stack() {

    while (not this->stack.empty()) {
        delete stack.top();
        stack.pop();
    }
}

absvm::absvm(const std::string &filename) {
    std::ifstream source;

    source.open(filename);
    if (not source.is_open()) {

        std::cerr <<  "Error: Failed to open " << filename << std::endl;
        std::__throw_system_error(errno);
    }
    try {
        interpretsource(source);
    } catch(const std::exception& e) {
        source.close();
        __throw_exception_again e;
    }
    source.close();
}

void absvm::processLines(std::istream& input) {

    int clines = 1;
    Logger::__init_();

    for (std::string line; std::getline(input, line); ++clines) {
        try {
            if (line == ";;")
                break;; // TODO: return if it's eq to exit
            if (not line.empty() and line[0] != ';')
                interpret(line);
        } catch (const std::exception& e) {
            throwgh ("absvm::processLines") __ca_tch("exception")
            InterpretationExept(e.what())._tracing_what(clines); //throw agin when msg not match InterpretationExept pattern
        }
    }
    std::__throw_system_error(42);
}

void absvm::shell() {

    try {
        processLines(std::cin);
    } catch(const std::system_error& se) {
        delete_stack();
        __throw_exception_again se;
    } catch(const std::exception& e) {
        delete_stack();
        __throw_exception_again e;
    }
}

void absvm::interpretsource(const std::ifstream &source) {

    try {
        processLines(const_cast<std::ifstream&>(source));
    } catch(const std::system_error& se) {
        delete_stack();
        __throw_exception_again se;
    } catch(const std::exception& e) {
        delete_stack();
        __throw_exception_again e;
    }
}


/**
 * @brief Interpret a value format 
 * 
 * @return
 *  pair of eOperandType and value as string
 * 
 * @param value_format
 * The value value_format must have one of the following form:
 *  ◦ int8(n) : Creates an 8-bit integer with value n.
 *  ◦ int16(n) : Creates a 16-bit integer with value n.
 *  ◦ int32(n) : Creates a 32-bit integer with value n.
 *  ◦ float(z) : Creates a float with value z.
 *  ◦ double(z) : Creates a double with value z
 */
std::pair<eOperandType, std::string> absvm::interpretValueFormat(const std::string& value_format) {

    std::regex pattern(R"(^\s*(int8|int16|int32|float|double)\((-?\d+(\.\d+)?(e[+-]?\d+)?)\)\s*$)");
    std::smatch matches;

    if (not std::regex_match(value_format, matches, pattern))
        throw InterpretationExept("Error: Invalid value format -> VMinterpreter(interpretValueFormat) ? " + value_format);

    static const std::array<std::string, types_count> types = {"int8", "int16", "int32", "float", "double"};

    for (size_t i = 0; i < types.size(); ++i)
        if (matches[1] == types[i])
            return {eOperandType( i), matches[2]};

    throw InterpretationExept("Error: Unknown type -> VMinterpreter(interpretValueFormat) ? " + matches[2].str());
}


