#include <vm.hpp>


absvm::absvm() { 
    try {
        processLines(std::cin);
    } catch(const std::logic_error& e) {
        delete_stack();
        __throw_exception_again e;
    }
}

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
    if (not source.is_open())
        std::__throw_system_error(errno);

    try {
        processLines(source);
    } catch(const std::logic_error& e) {
        delete_stack();
        __throw_exception_again e;
    }
}

void absvm::processLines(std::istream& input) {

    int clines = 1;
    Logger::__init_();

    for (std::string line; std::getline(input, line); ++clines) {

        line = trim(line);
        try {
            if (line == ";;")
                return;
            if (not line.empty() and line[0] not_eq ';')
                interpret(line);
        } catch (const std::logic_error& e) {

            __throw_interpreter(e.what(), clines);  //throw agin when msg not match InterpretationExept pattern
        }
    }
}

void absvm::processLines(std::ifstream& input) {

    int clines = 1;
    Logger::__init_();

    for (std::string line; std::getline(input, line); ++clines) {

        line = trim(line);
        try {
            if (not line.empty() and line[0] not_eq ';')
                interpret(line);
        } catch (const std::logic_error& e) {

            __throw_interpreter(e.what(), clines); //throw agin when msg not match InterpretationExept pattern
        }
    }

    __throw_interpreter("ERROR: Terminate the execution > lexer(processLines) ? program appears exit instruction", clines);
    std::__throw_system_error(42);
}

