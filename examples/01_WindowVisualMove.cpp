#include <functional>
#include <iostream>

#include <Syskos/Syskos.hpp>

int main(int argc, char const * argv[]) {
    std::function<void()> operations[] = {
        []() { Syskos::Window::MoveToTopLeft(); },
        []() { Syskos::Window::MoveToTop(); },
        []() { Syskos::Window::MoveToTopRight(); },
        []() { Syskos::Window::MoveToLeft(); },
        []() { Syskos::Window::MoveToCenter(); },
        []() { Syskos::Window::MoveToRight(); },
        []() { Syskos::Window::MoveToBottomLeft(); },
        []() { Syskos::Window::MoveToBottom(); },
        []() { Syskos::Window::MoveToBottomRight(); },
    };

    for (const auto & op : operations) {
        op();
        system("pause");
    }

    return 0;
}
