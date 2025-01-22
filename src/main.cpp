#include <vm.hpp>

int main(int argc, char **argv) {

    try {
        if  (argc > 2)
            std::__throw_invalid_argument("Error: too many arguments");
        else
            argc == 1 ? absvm() : absvm(argv[1]);
        return 0;
    } catch (const std::system_error& e) {

        return e.code().value();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        // __throw_exception_again e;

        return 1;
    }
}
