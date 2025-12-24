#include <Syskos/Detail/WindowVisual.hpp>

namespace {

// Get the real visual bounds size of the console window
SIZE GetVisualBoundsSize(HWND hwnd) {
    RECT extended{};
    DwmGetWindowAttribute(
        hwnd, DWMWA_EXTENDED_FRAME_BOUNDS, &extended, sizeof(extended)
    );
    LONG cx = extended.right - extended.left;
    LONG cy = extended.bottom - extended.top;
    return {cx, cy};
}

// Get the real visual bounds of the console window
RECT GetVisualBounds(HWND hwnd) {
    RECT extended{};
    DwmGetWindowAttribute(
        hwnd, DWMWA_EXTENDED_FRAME_BOUNDS, &extended, sizeof(extended)
    );
    return extended;
}

}  // namespace

namespace Syskos::Window::Detail::Visual {

void MoveToTopLeft() {
    LONG posX = 0;
    LONG posY = 0;
    MoveTo(posX, posY);
}

void MoveToTop() {
    HWND hwnd = GetConsoleWindow();
    SIZE boundsSize = GetVisualBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG posX = (workAreaSize.cx - boundsSize.cx) / 2;
    LONG posY = 0;

    MoveTo(posX, posY);
}

void MoveToTopRight() {
    HWND hwnd = GetConsoleWindow();
    SIZE boundsSize = GetVisualBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG posX = workAreaSize.cx - boundsSize.cx;
    LONG posY = 0;

    MoveTo(posX, posY);
}

void MoveToLeft() {
    HWND hwnd = GetConsoleWindow();
    SIZE boundsSize = GetVisualBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG posX = 0;
    LONG posY = (workAreaSize.cy - boundsSize.cy) / 2;

    MoveTo(posX, posY);
}

void MoveToCenter() {
    HWND hwnd = GetConsoleWindow();
    SIZE boundsSize = GetVisualBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG posX = (workAreaSize.cx - boundsSize.cx) / 2;
    LONG posY = (workAreaSize.cy - boundsSize.cy) / 2;

    MoveTo(posX, posY);
}

void MoveToRight() {
    HWND hwnd = GetConsoleWindow();
    SIZE boundsSize = GetVisualBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG posX = workAreaSize.cx - boundsSize.cx;
    LONG posY = (workAreaSize.cy - boundsSize.cy) / 2;

    MoveTo(posX, posY);
}

void MoveToBottomLeft() {
    HWND hwnd = GetConsoleWindow();
    SIZE boundsSize = GetVisualBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG posX = 0;
    LONG posY = workAreaSize.cy - boundsSize.cy;

    MoveTo(posX, posY);
}

void MoveToBottom() {
    HWND hwnd = GetConsoleWindow();
    SIZE boundsSize = GetVisualBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG posX = (workAreaSize.cx - boundsSize.cx) / 2;
    LONG posY = workAreaSize.cy - boundsSize.cy;

    MoveTo(posX, posY);
}

void MoveToBottomRight() {
    HWND hwnd = GetConsoleWindow();
    SIZE boundsSize = GetVisualBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG posX = workAreaSize.cx - boundsSize.cx;
    LONG posY = workAreaSize.cy - boundsSize.cy;

    MoveTo(posX, posY);
}

void MoveTo(LONG xCoord, LONG yCoord) {
    HWND hwnd = GetConsoleWindow();

    RECT extended = GetVisualBounds(hwnd);
    RECT bounds;
    GetWindowRect(hwnd, &bounds);

    LONG deltaX = extended.left - bounds.left;
    LONG deltaY = extended.top - bounds.top;

    LONG width = bounds.right - bounds.left;
    LONG height = bounds.bottom - bounds.top;

    LONG x = xCoord - deltaX;
    LONG y = yCoord - deltaY;

    MoveWindow(hwnd, x, y, width, height, TRUE);
}

}  // namespace Syskos::Window::Detail::Visual
