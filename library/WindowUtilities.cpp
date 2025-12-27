#include <Syskos/Detail/WindowUtilities.hpp>

namespace Syskos::Window::Detail::Utilities {

HWND GetHandleWindow() {
    static HWND hwnd = nullptr;

    if (!hwnd) {
        hwnd = GetConsoleWindow();
    }

    return hwnd;
}

}  // namespace Syskos::Window::Detail::Utilities
