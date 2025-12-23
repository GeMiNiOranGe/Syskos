#include <Syskos/Detail/WindowVisual.hpp>

namespace {

const SIZE WORK_AREA_SIZE = Syskos::Screen::Detail::GetWorkAreaSize();

}

namespace Syskos::Window::Detail::Visual {

void MoveToTopLeft() {
    int posX = 0;
    int posY = 0;
    MoveTo(posX, posY);
}

void MoveToTop() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int posX = WORK_AREA_SIZE.cx / 2 - (bounds.right - bounds.left) / 2;
    int posY = 0;
    MoveTo(posX, posY);
}

void MoveToTopRight() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int posX = WORK_AREA_SIZE.cx - (bounds.right - bounds.left);
    int posY = 0;
    MoveTo(posX, posY);
}

void MoveToLeft() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int posX = 0;
    int posY = WORK_AREA_SIZE.cy / 2 - (bounds.bottom - bounds.top) / 2;
    MoveTo(posX, posY);
}

void MoveToCenter() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int posX = WORK_AREA_SIZE.cx / 2 - (bounds.right - bounds.left) / 2;
    int posY = WORK_AREA_SIZE.cy / 2 - (bounds.bottom - bounds.top) / 2;
    MoveTo(posX, posY);
}

void MoveToRight() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int posX = WORK_AREA_SIZE.cx - (bounds.right - bounds.left);
    int posY = WORK_AREA_SIZE.cy / 2 - (bounds.bottom - bounds.top) / 2;
    MoveTo(posX, posY);
}

void MoveToBottomLeft() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int posX = 0;
    int posY = WORK_AREA_SIZE.cy - (bounds.bottom - bounds.top);
    MoveTo(posX, posY);
}

void MoveToBottom() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int posX = WORK_AREA_SIZE.cx / 2 - (bounds.right - bounds.left) / 2;
    int posY = WORK_AREA_SIZE.cy - (bounds.bottom - bounds.top);
    MoveTo(posX, posY);
}

void MoveToBottomRight() {
    RECT bounds;
    HWND hwnd = GetConsoleWindow();
    GetWindowRect(hwnd, &bounds);
    int posX = WORK_AREA_SIZE.cx - (bounds.right - bounds.left);
    int posY = WORK_AREA_SIZE.cy - (bounds.bottom - bounds.top);
    MoveTo(posX, posY);
}

void MoveTo(LONG xCoord, LONG yCoord) {
    HWND hwnd = GetConsoleWindow();

    RECT bounds, extended;
    GetWindowRect(hwnd, &bounds);
    DwmGetWindowAttribute(
        hwnd, DWMWA_EXTENDED_FRAME_BOUNDS, &extended, sizeof(extended)
    );

    LONG deltaX = extended.left - bounds.left;
    LONG deltaY = extended.top - bounds.top;

    LONG width = bounds.right - bounds.left;
    LONG height = bounds.bottom - bounds.top;

    LONG x = xCoord - deltaX;
    LONG y = yCoord - deltaY;

    MoveWindow(hwnd, x, y, width, height, TRUE);
}

}  // namespace Syskos::Window::Detail::Visual
