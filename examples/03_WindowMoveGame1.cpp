#include <conio.h>
#include <functional>
#include <iostream>

#include <Syskos/Syskos.hpp>

static const std::unordered_map<int, std::function<void(bool)>> keyMap = {
    {'7', Syskos::Window::MoveToTopLeft},
    {'Q', Syskos::Window::MoveToTopLeft},
    {'q', Syskos::Window::MoveToTopLeft},
    {'8', Syskos::Window::MoveToTop},
    {'W', Syskos::Window::MoveToTop},
    {'w', Syskos::Window::MoveToTop},
    {'9', Syskos::Window::MoveToTopRight},
    {'E', Syskos::Window::MoveToTopRight},
    {'e', Syskos::Window::MoveToTopRight},
    {'4', Syskos::Window::MoveToLeft},
    {'A', Syskos::Window::MoveToLeft},
    {'a', Syskos::Window::MoveToLeft},
    {'5', Syskos::Window::MoveToCenter},
    {'S', Syskos::Window::MoveToCenter},
    {'s', Syskos::Window::MoveToCenter},
    {'6', Syskos::Window::MoveToRight},
    {'D', Syskos::Window::MoveToRight},
    {'d', Syskos::Window::MoveToRight},
    {'1', Syskos::Window::MoveToBottomLeft},
    {'Z', Syskos::Window::MoveToBottomLeft},
    {'z', Syskos::Window::MoveToBottomLeft},
    {'2', Syskos::Window::MoveToBottom},
    {'X', Syskos::Window::MoveToBottom},
    {'x', Syskos::Window::MoveToBottom},
    {'3', Syskos::Window::MoveToBottomRight},
    {'C', Syskos::Window::MoveToBottomRight},
    {'c', Syskos::Window::MoveToBottomRight},
};

void ExecuteMove(int key, bool isVisualMode);

int main(int argc, char const * argv[]) {
    constexpr int KEY_ESC = 27;
    constexpr int KEY_MODE = 'm';

    Syskos::Window::MoveToCenter();

    bool isVisualMode = true;
    int key, lastKey = 0;

    std::cout << "[Esc] Exit" << '\n';
    std::cout << "[M]   Toggle Move Mode (Default: Visual)" << "\n\n";

    std::cout << "Use QWE/ASD/ZXC or the numpad to move the window:" << '\n';
    std::cout << "Qq Ww Ee  |  7 8 9" << '\n';
    std::cout << "Aa Ss Dd  |  4 5 6" << '\n';
    std::cout << "Zz Xx Cc  |  1 2 3" << "\n\n";

    do {
        key = _getch();

        if (key == KEY_MODE) {
            isVisualMode = !isVisualMode;

            std::string mode = isVisualMode ? "Visual" : "Standard";
            std::cout << "Current move mode: " << mode << '\n';

            if (lastKey != 0) {
                ExecuteMove(lastKey, isVisualMode);
            }
            continue;
        } else {
            lastKey = key;
        }

        ExecuteMove(key, isVisualMode);
    } while (key != KEY_ESC);

    return 0;
}

void ExecuteMove(int key, bool isVisualMode) {
    if (auto it = keyMap.find(key); it != keyMap.end()) {
        it->second(isVisualMode);
    }
}
