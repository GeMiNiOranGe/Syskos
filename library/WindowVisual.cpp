#include <Syskos/Detail/WindowVisual.hpp>

namespace {

RECT GetExtendedFrameBoundsRect(HWND hwnd) {
    RECT attribute{};
    DwmGetWindowAttribute(
        hwnd, DWMWA_EXTENDED_FRAME_BOUNDS, &attribute, sizeof(attribute)
    );
    return attribute;
}

SIZE GetExtendedFrameBoundsSize(HWND hwnd) {
    RECT attribute = GetExtendedFrameBoundsRect(hwnd);
    LONG cx = attribute.right - attribute.left;
    LONG cy = attribute.bottom - attribute.top;
    return {cx, cy};
}

}  // namespace

namespace Syskos::Window::Detail::Visual {

void MoveToTopLeft() {
    LONG targetX = 0;
    LONG targetY = 0;
    MoveTo(targetX, targetY);
}

void MoveToTop() {
    HWND hwnd = GetConsoleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG targetX = (workAreaSize.cx - extendedFrameBoundsSize.cx) / 2;
    LONG targetY = 0;

    MoveTo(targetX, targetY);
}

void MoveToTopRight() {
    HWND hwnd = GetConsoleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG targetX = workAreaSize.cx - extendedFrameBoundsSize.cx;
    LONG targetY = 0;

    MoveTo(targetX, targetY);
}

void MoveToLeft() {
    HWND hwnd = GetConsoleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG targetX = 0;
    LONG targetY = (workAreaSize.cy - extendedFrameBoundsSize.cy) / 2;

    MoveTo(targetX, targetY);
}

void MoveToCenter() {
    HWND hwnd = GetConsoleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG targetX = (workAreaSize.cx - extendedFrameBoundsSize.cx) / 2;
    LONG targetY = (workAreaSize.cy - extendedFrameBoundsSize.cy) / 2;

    MoveTo(targetX, targetY);
}

void MoveToRight() {
    HWND hwnd = GetConsoleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG targetX = workAreaSize.cx - extendedFrameBoundsSize.cx;
    LONG targetY = (workAreaSize.cy - extendedFrameBoundsSize.cy) / 2;

    MoveTo(targetX, targetY);
}

void MoveToBottomLeft() {
    HWND hwnd = GetConsoleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG targetX = 0;
    LONG targetY = workAreaSize.cy - extendedFrameBoundsSize.cy;

    MoveTo(targetX, targetY);
}

void MoveToBottom() {
    HWND hwnd = GetConsoleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG targetX = (workAreaSize.cx - extendedFrameBoundsSize.cx) / 2;
    LONG targetY = workAreaSize.cy - extendedFrameBoundsSize.cy;

    MoveTo(targetX, targetY);
}

void MoveToBottomRight() {
    HWND hwnd = GetConsoleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG targetX = workAreaSize.cx - extendedFrameBoundsSize.cx;
    LONG targetY = workAreaSize.cy - extendedFrameBoundsSize.cy;

    MoveTo(targetX, targetY);
}

void MoveTo(LONG targetX, LONG targetY) {
    HWND hwnd = GetConsoleWindow();

    RECT extendedFrameBounds = GetExtendedFrameBoundsRect(hwnd);
    RECT window{};
    GetWindowRect(hwnd, &window);

    LONG offsetX = extendedFrameBounds.left - window.left;
    LONG offsetY = extendedFrameBounds.top - window.top;

    LONG width = window.right - window.left;
    LONG height = window.bottom - window.top;

    LONG adjustedX = targetX - offsetX;
    LONG adjustedY = targetY - offsetY;

    MoveWindow(hwnd, adjustedX, adjustedY, width, height, TRUE);
}

}  // namespace Syskos::Window::Detail::Visual
