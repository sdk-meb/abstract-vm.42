#include <vm.hpp>

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
            } catch (const std::exception &e) {
                throwgh ("absvm::interpret(push)") __ca_tch("exception")


                delete tmp_opetrand;
                throw InterpretationExept(e.what());
                std::cerr << e.what() << "dddddddddddddddd"<< std::endl;
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
            } catch (const std::logic_error &e) {
                throwgh ("absvm::interpret(assert)") __ca_tch("logic_error")

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
            } catch (const std::logic_error &e) {
                throwgh ("absvm::interpret(pop)") __ca_tch("logic_error")

                std::cerr << e.what() << std::endl;
                // TODO: tracing || stop
            }
        }},
        {"dump", [this](const std::string& unval) {
            if (not unval.empty())
                throw std::runtime_error("Error: Dump command takes no value");
            Dump(this->stack).execute(); //  TODO: implemetation
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
