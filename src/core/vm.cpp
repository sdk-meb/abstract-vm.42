#include <vm.hpp>
#include <regex>

absvm::absvm() { this->shell(); }

/** 
 * @note ... # TODO: std::stack<std::unique_ptr<IOperand>> stack; or std::shared_ptr
 */
absvm::~absvm() {}

absvm::absvm(const std::string &filename) {
    std::ifstream source;

    source.open(filename);
    if (not source.is_open()) 
        throw std::runtime_error("Error: Failed to open " + filename);

    interpretsource(source);
    source.close();
}

void absvm::processLines(std::istream& input) {

    static int clines;
    Logger::__init_();

    for (std::string line; std::getline(input, line); ++clines) {
        try {
            if (line == ";;")
                break;; // TODO: return if it's eq to exit
            if (not line.empty() and line[0] != ';')
                interpret(line);
        } catch (const InterpretationExept& Ie) {
            throwgh ("absvm::processLines") __ca_tch("InterpretationExept")

            Ie._tracing_what(clines);
        } catch (const std::exception& e) {
            throwgh ("absvm::processLines") __ca_tch("exception")

            InterpretationExept(e.what())._tracing_what(clines);
        }
    }
    std::__throw_system_error(42);
}

void absvm::shell() {
    processLines(std::cin);
}

void absvm::interpretsource(const std::ifstream &source) {
    processLines(const_cast<std::ifstream&>(source));
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

    std::regex pattern(R"(^\s*(int8|int16|int32|float|double)\((.*)\)\s*$)");
    std::smatch matches; // TODO: l  

    if (!std::regex_match(value_format, matches, pattern))
        throw InterpretationExept("Error: Invalid value format: " + value_format);

    static const std::array<std::string, types_count> types = {"int8", "int16", "int32", "float", "double"};

    for (size_t i = 0; i < types.size(); ++i)
        if (matches[1] == types[i])
            return {eOperandType( i), matches[2]};

    throw std::runtime_error("Error: Unknown type in: " + value_format);
}


