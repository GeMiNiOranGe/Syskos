#include <functional>
#include <iostream>

#include <syskos/syskos.hpp>

using namespace Syskos::Window::Detail;

int main(int argc, char const * argv[]) {
    std::function<void()> operations[] = {
        []() { Visual::MoveToTopLeft(); },
        []() { Visual::MoveToTop(); },
        []() { Visual::MoveToTopRight(); },
        []() { Visual::MoveToLeft(); },
        []() { Visual::MoveToCenter(); },
        []() { Visual::MoveToRight(); },
        []() { Visual::MoveToBottomLeft(); },
        []() { Visual::MoveToBottom(); },
        []() { Visual::MoveToBottomRight(); },
    };

    for (const auto & op : operations) {
        op();
        system("pause");
    }

    return 0;
}
