#include <functional>
#include <iostream>

#include <Syskos/Syskos.hpp>

int main(int argc, char const * argv[]) {
    std::function<void()> operations[] = {
        []() { Syskos::Window::MoveToTopLeft(false); },
        []() { Syskos::Window::MoveToTop(false); },
        []() { Syskos::Window::MoveToTopRight(false); },
        []() { Syskos::Window::MoveToLeft(false); },
        []() { Syskos::Window::MoveToCenter(false); },
        []() { Syskos::Window::MoveToRight(false); },
        []() { Syskos::Window::MoveToBottomLeft(false); },
        []() { Syskos::Window::MoveToBottom(false); },
        []() { Syskos::Window::MoveToBottomRight(false); },
    };

    for (const auto & op : operations) {
        op();
        system("pause");
    }

    return 0;
}
