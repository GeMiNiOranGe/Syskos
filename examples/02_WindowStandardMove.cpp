#include <functional>
#include <iostream>

#include <syskos/syskos.hpp>

using namespace Syskos;

int main(int argc, char const * argv[]) {
    std::function<void()> operations[] = {
        []() { Window::MoveToTopLeft(false); },
        []() { Window::MoveToTop(false); },
        []() { Window::MoveToTopRight(false); },
        []() { Window::MoveToLeft(false); },
        []() { Window::MoveToCenter(false); },
        []() { Window::MoveToRight(false); },
        []() { Window::MoveToBottomLeft(false); },
        []() { Window::MoveToBottom(false); },
        []() { Window::MoveToBottomRight(false); },
    };

    for (const auto & op : operations) {
        op();
        system("pause");
    }

    return 0;
}
