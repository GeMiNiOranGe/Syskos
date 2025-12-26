#include <conio.h>
#include <functional>
#include <iostream>

#include <Syskos/Syskos.hpp>

void ExecuteMove(int key, bool isVisualMode);

int main(int argc, char const * argv[]) {
    Syskos::Window::MoveToCenter();

    bool isVisualMode = true;
    int key, lastKey = 0;

    do {
        system("cls");
        std::cout << "[Esc] Exit" << '\n';
        std::cout << "[Tab] Toggle Move Mode (Current: "
                  << (isVisualMode ? "Visual" : "Standard") << ")" << '\n';
        std::cout << "Use QWE/ASD/ZXC or numpad to move the window:" << '\n';
        std::cout << "Qq Ww Ee  |  7 8 9" << '\n';
        std::cout << "Aa Ss Dd  |  4 5 6" << '\n';
        std::cout << "Zz Xx Cc  |  1 2 3" << '\n';

        key = _getch();

        if (key == 9) {
            isVisualMode = !isVisualMode;
            if (lastKey != 0) {
                ExecuteMove(lastKey, isVisualMode);
            }
            continue;
        } else {
            lastKey = key;
        }

        ExecuteMove(key, isVisualMode);
    } while (key != 27);

    return 0;
}

void ExecuteMove(int key, bool isVisualMode) {
    switch (key) {
        case '7':
        case 'Q':
        case 'q': {
            Syskos::Window::MoveToTopLeft(isVisualMode);
            break;
        }
        case '8':
        case 'W':
        case 'w': {
            Syskos::Window::MoveToTop(isVisualMode);
            break;
        }
        case '9':
        case 'E':
        case 'e': {
            Syskos::Window::MoveToTopRight(isVisualMode);
            break;
        }
        case '4':
        case 'A':
        case 'a': {
            Syskos::Window::MoveToLeft(isVisualMode);
            break;
        }
        case '5':
        case 'S':
        case 's': {
            Syskos::Window::MoveToCenter(isVisualMode);
            break;
        }
        case '6':
        case 'D':
        case 'd': {
            Syskos::Window::MoveToRight(isVisualMode);
            break;
        }
        case '1':
        case 'Z':
        case 'z': {
            Syskos::Window::MoveToBottomLeft(isVisualMode);
            break;
        }
        case '2':
        case 'X':
        case 'x': {
            Syskos::Window::MoveToBottom(isVisualMode);
            break;
        }
        case '3':
        case 'C':
        case 'c': {
            Syskos::Window::MoveToBottomRight(isVisualMode);
            break;
        }
        default: {
            break;
        }
    }
}
