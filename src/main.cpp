#include <vm.hpp>

int main(int argc, char **argv) {

    try {

        if  (argc > 2)
            throw std::invalid_argument("Error: too many arguments");
        else
            argc == 1 ? absvm() : absvm(argv[1]);
        return 0;
    } catch (const std::system_error& e) {
        throwgh ("main") __ca_tch("system_error")

        return e.code().value();
    } catch (const std::exception &e) {
        throwgh ("main") __ca_tch("exception")
        __throw_exception_again e;

        return 1;
    }
}
