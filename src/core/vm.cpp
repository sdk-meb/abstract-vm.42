#include <vm.hpp>

absvm::absvm() { this->shell(); }

absvm::absvm(const std::string &filename) {
    std::ifstream source;

    source.open(filename);
    if (not source.is_open()) 
        throw std::runtime_error("Error: Failed to open file");

    interpretsource(source);
    source.close();
}

void absvm::processLines(std::istream& input) {
    std::string line;
    while (std::getline(input, line)) {
        if (line == ";;")
            break;
        if (not line.empty() and line[0] != ';')
            interpret(line);
    }
}

void absvm::shell() {
    processLines(std::cin);
}

void absvm::interpretsource(const std::ifstream &source) {
    processLines(const_cast<std::ifstream&>(source));
}

void absvm::interpret(const std::string &line) {

    static const std::unordered_map<std::string, std::function<void(const std::string&)>> commands = {
        {"push", [this](const std::string& val) {
            if (val.empty()) throw std::runtime_error("Error: Value required for push");
            Push(val).execute();
        }},
        {"assert", [this](const std::string& val) {
            if (val.empty()) throw std::runtime_error("Error: Value required for assert");
            Assert(val).execute();
        }},
        {"pop", [this](const std::string& unval) {
            if (not unval.empty()) throw std::runtime_error("Error: Pop command takes no value");
            Pop().execute();
        }},
        {"dump", [this](const std::string& unval) {
            if (not unval.empty()) throw std::runtime_error("Error: Dump command takes no value");
            Dump().execute();
        }},
        {"add", [this](const std::string& unval) {
            if (not unval.empty()) throw std::runtime_error("Error: Add command takes no value");
            Add().execute();
        }},
        {"sub", [this](const std::string& unval) {
            if (not unval.empty()) throw std::runtime_error("Error: Sub command takes no value");
            Sub().execute();
        }},
        {"mul", [this](const std::string& unval) {
            if (not unval.empty()) throw std::runtime_error("Error: Mul command takes no value");
            Mul().execute();
        }},
        {"div", [this](const std::string& unval) {
            if (not unval.empty()) throw std::runtime_error("Error: Div command takes no value");
            Div().execute();
        }},
        {"mod", [this](const std::string& unval) {
            if (not unval.empty()) throw std::runtime_error("Error: Mod command takes no value");
            Mod().execute();
        }},
        {"print", [this](const std::string& unval) {
            if (not unval.empty()) throw std::runtime_error("Error: Print command takes no value");
            Print().execute();
        }},
        {"exit", [](const std::string&) { 
            Exit();
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

    auto it = commands.find(command);
    if (it == commands.end())
        throw std::runtime_error("Error:" + command + " Unknown command");

    it->second(value);
}

// absvm::~absvm() {}
