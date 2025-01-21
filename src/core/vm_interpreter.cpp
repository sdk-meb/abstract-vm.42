#include <vm.hpp>

auto absvm::commands() {

    static const std::unordered_map<std::string, std::function<void(const std::pair<eOperandType, std::string> &)>> s_commands = {
        {"push", [this](const std::pair<eOperandType, std::string> &__pair) {

            auto operand = Factory().createOperand(__pair.first, __pair.second);
            try {
                Push(this->stack).execute(operand);
            } catch (const std::exception &e) {
                delete operand;
                throw InterpretationExept(e.what());
            }
        }},
        {"assert", [this](const std::pair<eOperandType, std::string> &__pair) {

            auto tmp_operand = Factory().createOperand(__pair.first, __pair.second);
            try {
                Assert(this->stack).execute(tmp_operand);
                delete tmp_operand;
            } catch (const std::exception &e) {
                delete tmp_operand;
                throw InterpretationExept(e.what());
            }
        }},
        {"pop", [this](const std::pair<eOperandType, std::string> &) {
            try {
                if (not this->stack.empty())
                    delete this->stack.top();
                Pop(this->stack).execute();
            } catch (const std::logic_error &e) {
                throw InterpretationExept(e.what());
            }
        }},
        {"dump", [this](const std::pair<eOperandType, std::string> &) {
            Dump(this->stack).execute();
        }},
        {"add", [this](const std::pair<eOperandType, std::string> &) {
            Add(this->stack).execute();
        }},
        {"sub", [this](const std::pair<eOperandType, std::string> &) {
            Sub(this->stack).execute();
        }},
        {"mul", [this](const std::pair<eOperandType, std::string> &) {
            Mul(this->stack).execute();
        }},
        {"div", [this](const std::pair<eOperandType, std::string> &) {
            Div(this->stack).execute();
        }},
        {"mod", [this](const std::pair<eOperandType, std::string> &) {
            Mod(this->stack).execute();
        }},
        {"print", [this](const std::pair<eOperandType, std::string> &) {
            Print(this->stack).execute();
        }},
        {"exit", [this](const std::pair<eOperandType, std::string> &) {
            Exit(this->stack).execute();
        }},
    };

    return s_commands;
}


void absvm::interpret(const std::string &line) {

    std::string trimmed = trim(line);
    if (trimmed.empty())
        return; // empty line

    //  INSTR ("pop|dump|push|assert|add|sub|mul|div|mod|print|exit");
    //  TYPES ("int8|int16|int32|float|double");
    const auto pattern = R"(^\s*(pop|dump|push|assert|add|sub|mul|div|mod|print|exit)\s+(int8|int16|int32|float|double)?\(\s*([-+]?\d*\.?\d+)\s*\)?\s*$)";
    std::regex regex(pattern, std::regex::icase);
    std::regex instrRegex(R"(^\s*(pop|dump|push|assert|add|sub|mul|div|mod|print|exit)\b)", std::regex::icase);
    std::regex typeRegex(R"(\b(int8|int16|int32|float|double)\b)", std::regex::icase);
    std::regex valueRegex(R"(\(\s*([-+]?\d*\.?\d+)\s*\))");
    std::smatch match;

    std::smatch global_match;

    if (not std::regex_search(trimmed, global_match, instrRegex))
        throw InterpretationExept("Error: Unknown instruction -> VMinterpreter(interpret)");
    std::string command = global_match[1];
    bool need_value = not not std::unordered_set<std::string>({"assert", "push"}).find(command)->size();

    if (need_value and not std::regex_search(trimmed, global_match, typeRegex))
        throw InterpretationExept("Error: Unknown value type -> VMinterpreter(interpret)");
    std::string type = global_match[1];

    if (need_value and std::regex_search(trimmed, global_match, valueRegex))
        throw InterpretationExept("Error: Unknown value type -> VMinterpreter(interpret)");
    std::string value = global_match[1].str();

    if (not std::regex_match(trimmed, regex))
        throw InterpretationExept("Error: Too many arguments or invalid format. -> VMinterpreter(interpret)");

    auto it = commands().find(command);
    if (it == commands().end())
        throw std::runtime_error("Error: regex_match Unknown command"); // never

    static const std::array<std::string, types_count> types = {"int8", "int16", "int32", "float", "double"};

    if (not need_value)
        it->second({eOperandType(-1), ""});
    else
    {
        for (size_t i = 0; i < types.size(); ++i)
            if (type == types[i])
                it->second({eOperandType(i), value});
    }
}
