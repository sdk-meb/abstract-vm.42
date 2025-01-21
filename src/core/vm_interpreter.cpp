#include <vm.hpp>

auto absvm::commands(const std::string& commnad) {

    static const std::unordered_map<std::string, std::function<void(const std::pair<eOperandType, std::string> &)>> s_commands = {
        {"push", [this](auto __pair) {

            auto operand = Factory().createOperand(__pair.first, __pair.second);
            try {
                Push(this->stack).execute(operand);
            } catch (const std::exception &e) {
                delete operand;
                throw InterpretationExept(e.what());
            }
        }},
        {"assert", [this](auto __pair) {

            auto tmp_operand = Factory().createOperand(__pair.first, __pair.second);
            try {
                Assert(this->stack).execute(tmp_operand);
                delete tmp_operand;
            } catch (const std::exception &e) {
                delete tmp_operand;
                throw InterpretationExept(e.what());
            }
        }},
        {"pop", [this](auto) {
            try {
                if (not this->stack.empty())
                    delete this->stack.top();
                Pop(this->stack).execute();
            } catch (const std::logic_error &e) {
                throw InterpretationExept(e.what());
            }
        }},
        {"dump", [this](auto) {
            Dump(this->stack).execute();
        }},
        {"add", [this](auto) {
            Add(this->stack).execute();
        }},
        {"sub", [this](auto) {
            Sub(this->stack).execute();
        }},
        {"mul", [this](auto) {
            Mul(this->stack).execute();
        }},
        {"div", [this](auto) {
            Div(this->stack).execute();
        }},
        {"mod", [this](auto) {
            Mod(this->stack).execute();
        }},
        {"print", [this](auto) {
            Print(this->stack).execute();
        }},
        {"exit", [this](auto) {
            Exit(this->stack).execute();
        }},
    };

    return s_commands.find(commnad);
}


std::smatch extract_instr(const std::string &line) {
    std::regex instrRegex(R"(^\s*(pop|dump|push|assert|add|sub|mul|div|mod|print|exit)\s*(\s.*)?$)");
    std::smatch match;

    if (not std::regex_match(line, match, instrRegex))
        throw InterpretationExept("Error: Unknown instruction -> VMinterpreter(extract_instr)");
    
    return match;
}

std::smatch extract_valueforma(const std::string& reset_line) {
    std::regex valueformatRegex(R"(^\s*(int8|int16|int32|float|double)\s*\(\s*([-+]?\d*\.?\d+)\s*\)\s*(\s.*)?$)");
    std::smatch match;

    if (not std::regex_match(reset_line, match, valueformatRegex))
        throw InterpretationExept("Error: value format invalide -> VMinterpreter(extract_valueforma)");

    return match;
}

void absvm::interpret(const std::string &line) {

    std::string trimmed = trim(line);
    if (trimmed.empty())
        return; // empty line

    std::string command;
    std::string reset;
    std::string type;
    std::string value;
    bool need_value;
    {
        std::smatch match;
        match = extract_instr(line);
        command = match[1];
        reset = match[2].str();
        static std::unordered_set<std::string> commands_need_value = {"assert", "push"};
        need_value = commands_need_value.find(command) not_eq commands_need_value.end();
    }
    if (need_value) {
        std::smatch match;

        match = extract_valueforma(reset);
        type = match[1];
        value = match[2];
        reset = match[3];
    } 
    if (reset.size())
        throw InterpretationExept("Error: Too many arguments. -> VMinterpreter(interpret)");

    auto exce_command = commands(command);

    static const std::array<std::string, types_count> types = {"int8", "int16", "int32", "float", "double"};

    if (not need_value)
        exce_command->second({eOperandType::Double, ""});
    else {
        for (size_t i = 0; i < types.size(); ++i)
            if (type == types[i])
                exce_command->second({eOperandType(i), value});
    }
}
