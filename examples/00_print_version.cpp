#include <iostream>

#include <Syskos/config.hpp>

int main(int argc, char const * argv[]) {
    std::cout << "Syskos version: ";
    std::cout << SYSKOS_VERSION_MAJOR << '.';
    std::cout << SYSKOS_VERSION_MINOR << '.';
    std::cout << SYSKOS_VERSION_PATCH << '.';
    std::cout << SYSKOS_VERSION_TWEAK << '\n';
    std::cout << '\n';

    return 0;
}
