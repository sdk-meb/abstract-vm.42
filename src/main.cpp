#include <vm.hpp>

int main(int argc, char **argv) {

    try {

        if  (argc > 2)
            throw std::runtime_error("Error: too many arguments");
        else
            argc == 1 ? absvm() : absvm(argv[1]);
        return 0;
    }
    catch (const std::exception &e) {

        std::cerr << e.what() << std::endl;
        return 1;
    }
}