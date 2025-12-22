#include <functional>
#include <iostream>

#include <syskos/syskos.hpp>

using namespace Syskos;

int main(int argc, char const * argv[]) {
    std::function<void()> operations[] = {
        []() { window::visual::move_to_top_left(); },
        []() { window::visual::move_to_top(); },
        []() { window::visual::move_to_top_right(); },
        []() { window::visual::move_to_left(); },
        []() { window::visual::move_to_center(); },
        []() { window::visual::move_to_right(); },
        []() { window::visual::move_to_bottom_left(); },
        []() { window::visual::move_to_bottom(); },
        []() { window::visual::move_to_bottom_right(); },
    };

    for (const auto & op : operations) {
        op();
        system("pause");
    }

    return 0;
}
