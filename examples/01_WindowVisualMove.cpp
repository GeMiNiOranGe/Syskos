#include <functional>
#include <iostream>

#include <syskos/syskos.hpp>

using namespace Syskos;

int main(int argc, char const * argv[]) {
    std::function<void()> operations[] = {
        []() { Window::MoveToTopLeft(); },
        []() { Window::MoveToTop(); },
        []() { Window::MoveToTopRight(); },
        []() { Window::MoveToLeft(); },
        []() { Window::MoveToCenter(); },
        []() { Window::MoveToRight(); },
        []() { Window::MoveToBottomLeft(); },
        []() { Window::MoveToBottom(); },
        []() { Window::MoveToBottomRight(); },
    };

    for (const auto & op : operations) {
        op();
        system("pause");
    }

    return 0;
}
