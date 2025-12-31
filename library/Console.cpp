#include <Syskos/Detail/Console.hpp>

namespace Syskos::Detail::Console {

std::optional<COORD> GetCursorPosition() {
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (!GetConsoleScreenBufferInfo(outputHandle, &csbi)) {
        return std::nullopt;
    }

    return csbi.dwCursorPosition;
}

void SetCursorPosition(SHORT x, SHORT y) {
    COORD pos = {x, y};
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(outputHandle, pos);
}

}  // namespace Syskos::Detail::Console
