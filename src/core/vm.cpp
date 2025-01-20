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

        line = trim(line);
        try {
            if (line == ";;")
                break;; // TODO: return if it's eq to exit
            if (not line.empty() and line[0] != ';')
                interpret(line);
        } catch (const std::exception& e) {
            InterpretationExept(e.what())._tracing_what(clines); //throw agin when msg not match InterpretationExept pattern
        }
    }

    InterpretationExept("ERROR: Terminate the execution of the current program appears exit instruction -> absvm(processLines)")
        ._tracing_what(clines); 
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

