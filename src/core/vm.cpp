#include <vm.hpp>
#include <regex>

absvm::absvm() { this->shell(); }

/** 
 * @note ... # TODO: std::stack<std::unique_ptr<IOperand>> stack; or std::shared_ptr
 */
absvm::~absvm() {
    for (; not this->stack.empty(); this->stack.pop()) {
        delete this->stack.top();
    }
}

absvm::absvm(const std::string &filename) {
    std::ifstream source;

    source.open(filename);
    if (not source.is_open()) 
        throw std::runtime_error("Error: Failed to open " + filename);

    interpretsource(source);
    source.close();
}

void absvm::processLines(std::istream& input) {

    std::string line;

    while (std::getline(input, line)) {
        if (line == ";;") // end of program
            break;
        if (not line.empty() and line[0] != ';')
            interpret(line);
        // TODO tarcking lines for debugging here
    }
    // TODO: no exit found , throw error
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
        throw std::runtime_error("Error: Invalid value format: " + value_format);

    static const std::array<std::string, types_count> types = {"int8", "int16", "int32", "float", "double"};

    for (size_t i = 0; i < types.size(); ++i)
        if (matches[1] == types[i])
            return {eOperandType( i), matches[2]};

    throw std::runtime_error("Error: Unknown type in: " + value_format);
}



void absvm::interpret(const std::string &line) {

    static const std::unordered_map<std::string, std::function<void(const std::string&)>> commands = { // TODO: l unordered_map function
        {"push", [this](const std::string& val) { // TODO: l [this] (...) {}
            if (val.empty())
                throw std::runtime_error("Error: Value required for push");
            const std::pair<eOperandType, std::string>& __pair =  this->interpretValueFormat(val);
            auto tmp_opetrand =  Factory().createOperand(__pair.first, __pair.second);
            try {
                Push(this->stack).execute(tmp_opetrand);
                delete tmp_opetrand;
            }
            catch (const std::logic_error &e) {
                delete tmp_opetrand;
                std::cerr << e.what() << std::endl;
                // TODO: tracing
            }
        }},
        {"assert", [this](const std::string& val) {
            if (val.empty())
                throw std::runtime_error("Error: Value required for assert");
            const std::pair<eOperandType, std::string>& __pair =  this->interpretValueFormat(val);
            auto tmp_opetrand =  Factory().createOperand(__pair.first, __pair.second);
            try {
                Assert(this->stack).execute(tmp_opetrand);
                delete tmp_opetrand;
                // TODO: tracing succesed
            }
            catch (const std::logic_error &e) {
                delete tmp_opetrand;
                std::cerr << e.what() << std::endl;
                // TODO: tracing || stop
            }
        }},
        {"pop", [this](const std::string& unval) {
            if (not unval.empty())
                throw std::runtime_error("Error: Pop command takes no value");
            try {
                Pop(this->stack).execute();
            }
            catch (const std::logic_error &e) {
                std::cerr << e.what() << std::endl;
                // TODO: tracing || stop
            }
        }},
        {"dump", [this](const std::string& unval) {
            if (not unval.empty())
                throw std::runtime_error("Error: Dump command takes no value");
            Dump(this->stack).execute();
        }},
        {"add", [this](const std::string& unval) {
            if (not unval.empty())
                throw std::runtime_error("Error: Add command takes no value");
            Add(this->stack).execute(); //  TODO: implemetation
        }},
        {"sub", [this](const std::string& unval) {
            if (not unval.empty())
                throw std::runtime_error("Error: Sub command takes no value");
            Sub(this->stack).execute();//  TODO: implemetation
        }},
        {"mul", [this](const std::string& unval) {
            if (not unval.empty())
                throw std::runtime_error("Error: Mul command takes no value");
            Mul(this->stack).execute();//  TODO: implemetation
        }},
        {"div", [this](const std::string& unval) {
            if (not unval.empty())
                throw std::runtime_error("Error: Div command takes no value");
            Div(this->stack).execute();//  TODO: implemetation
        }},
        {"mod", [this](const std::string& unval) {
            if (not unval.empty())
                throw std::runtime_error("Error: Mod command takes no value");
            Mod(this->stack).execute();//  TODO: implemetation
        }},
        {"print", [this](const std::string& unval) {
            if (not unval.empty())
                throw std::runtime_error("Error: Print command takes no value");
            Print(this->stack).execute();
        }},
        {"exit", [this](const std::string& unval) { 
            if (not unval.empty())
                throw std::runtime_error("Error: Exit command takes no value");
            Exit(this->stack).execute();
        }},
    };

    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token)
        tokens.push_back(token);

    if (tokens.empty())
        return; // empty line

    if (tokens.size() > 2)
        throw std::runtime_error("Error: Too many arguments");

    std::string command = tokens[0];
    std::string value = tokens.size() == 2 ? tokens[1] : "";

    auto it = commands.find(command); // TODO: l auto
    if (it == commands.end())
        throw std::runtime_error("Error:" + command + " Unknown command");

    it->second(value);
}

// absvm::~absvm() {}
