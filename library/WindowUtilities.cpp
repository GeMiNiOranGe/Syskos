#include <Syskos/Detail/WindowUtilities.hpp>

namespace Syskos::Detail::Window::Utilities {

HWND GetConsoleWindowHandle() {
    static HWND hwnd = nullptr;

    if (!hwnd) {
        hwnd = GetConsoleWindow();
    }

    return hwnd;
}

}  // namespace Syskos::Detail::Window::Utilities
