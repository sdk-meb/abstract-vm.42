#include <vm.hpp>


void absvm::interpret(const std::string &line) {

    static const std::unordered_map<std::string, std::function<void(const std::string&)>> commands = { // TODO: l unordered_map function
        {"push", [this](const std::string& val) { // TODO: l [this] (...) {}
            if (val.empty())
                throw InterpretationExept("Error: Push Value required -> VMinterpreter(interpret) ? empty val");
            const std::pair<eOperandType, std::string>& __pair =  this->interpretValueFormat(val);
            auto operand =  Factory().createOperand(__pair.first, __pair.second);
            try {
                Push(this->stack).execute(operand);
            } catch (const std::exception &e) {
                throwgh ("absvm::interpret(push)") __ca_tch("exception")

                delete operand;
                throw InterpretationExept(e.what());
            }
        }},
        {"assert", [this](const std::string& val) {
            if (val.empty())
                throw InterpretationExept("Error: Assert Value required -> VMinterpreter(interpret) ? empty val");
            const std::pair<eOperandType, std::string>& __pair =  this->interpretValueFormat(val);
            auto tmp_operand =  Factory().createOperand(__pair.first, __pair.second);
            try {
                Assert(this->stack).execute(tmp_operand);
                delete tmp_operand;
            } catch (const std::exception &e) {
                throwgh ("absvm::interpret(assert)") __ca_tch("exception")

                delete tmp_operand;
                throw InterpretationExept(e.what());
            }
        }},
        {"pop", [this](const std::string& unval) {
            if (not unval.empty())
                throw InterpretationExept("Error: pop Value unrequired -> VMinterpreter(interpret) ? " + unval);
            try {
                if (not this->stack.empty())
                    delete this->stack.top();
                Pop(this->stack).execute();
            } catch (const std::logic_error &e) {
                throwgh ("absvm::interpret(pop)") __ca_tch("logic_error")

                throw InterpretationExept(e.what());
            }
        }},
        {"dump", [this](const std::string& unval) {
            if (not unval.empty())
                throw InterpretationExept("WORNING: dump Value unrequired -> VMinterpreter(interpret) ? " + unval);
            Dump(this->stack).execute();
        }},
        {"add", [this](const std::string& unval) {
            if (not unval.empty())
                throw InterpretationExept("WORNING: add Value unrequired -> VMinterpreter(interpret) ? " + unval);
            Add(this->stack).execute();
        }},
        {"sub", [this](const std::string& unval) {
            if (not unval.empty())
                throw InterpretationExept("WORNING: sub Value unrequired -> VMinterpreter(interpret) ? " + unval);
            Sub(this->stack).execute();
        }},
        {"mul", [this](const std::string& unval) {
            if (not unval.empty())
                throw InterpretationExept("WORNING: mul Value unrequired -> VMinterpreter(interpret) ? " + unval);
            Mul(this->stack).execute();
        }},
        {"div", [this](const std::string& unval) {
            if (not unval.empty())
                throw InterpretationExept("WORNING: div Value unrequired -> VMinterpreter(interpret) ? " + unval);
            Div(this->stack).execute();
        }},
        {"mod", [this](const std::string& unval) {
            if (not unval.empty())
                throw InterpretationExept("WORNING: mod Value unrequired -> VMinterpreter(interpret) ? " + unval);
            Mod(this->stack).execute();
        }},
        {"print", [this](const std::string& unval) {
            if (not unval.empty())
                throw InterpretationExept("WORNING: print Value unrequired -> VMinterpreter(interpret) ? " + unval);
            Print(this->stack).execute();
        }},
        {"exit", [this](const std::string& unval) { 
            if (not unval.empty())
                throw InterpretationExept("WORNING: exit Value unrequired -> VMinterpreter(interpret) ? " + unval);
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
