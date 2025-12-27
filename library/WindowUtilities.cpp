#include <Syskos/Detail/WindowUtilities.hpp>

namespace Syskos::Detail::Window::Utilities {

HWND GetHandleWindow() {
    static HWND hwnd = nullptr;

    if (!hwnd) {
        hwnd = GetConsoleWindow();
    }

    return hwnd;
}

}  // namespace Syskos::Detail::Window::Utilities
