#include <Syskos/Detail/WindowLegacy.hpp>

namespace Syskos::Detail::Window::Legacy {

std::optional<RECT> GetRect(HWND hwnd) {
    RECT window{};
    if (!GetWindowRect(hwnd, &window)) {
        return std::nullopt;
    }

    return window;
}

void MoveTo(HWND hwnd, LONG targetX, LONG targetY) {
    std::optional<RECT> window = GetRect(hwnd);

    if (!window) {
        return;
    }

    int width = window.value().right - window.value().left;
    int height = window.value().bottom - window.value().top;

    MoveWindow(hwnd, targetX, targetY, width, height, TRUE);
}

}  // namespace Syskos::Detail::Window::Legacy
