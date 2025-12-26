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

HWND GetHandleWindow() {
    static HWND hwnd = nullptr;

    if (!hwnd) {
        hwnd = GetConsoleWindow();
    }

    return hwnd;
}

void MoveToImpl(HWND hwnd, LONG targetX, LONG targetY) {
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

}  // namespace

namespace Syskos::Window::Detail::Visual {

HRESULT GetWindowGeometry(WindowGeometry & geometry) {
    HWND hwnd = GetHandleWindow();

    RECT rect{};
    HRESULT result = DwmGetWindowAttribute(
        hwnd, DWMWA_EXTENDED_FRAME_BOUNDS, &rect, sizeof(rect)
    );

    if (FAILED(result)) {
        return result;
    }

    geometry.point.x = rect.left;
    geometry.point.y = rect.top;
    geometry.size.cx = rect.right - rect.left;
    geometry.size.cy = rect.bottom - rect.top;

    return S_OK;
}

void MoveToTopLeft() {
    MoveTo(WindowAnchor::TopLeft);
}

void MoveToTop() {
    MoveTo(WindowAnchor::Top);
}

void MoveToTopRight() {
    MoveTo(WindowAnchor::TopRight);
}

void MoveToLeft() {
    MoveTo(WindowAnchor::Left);
}

void MoveToCenter() {
    MoveTo(WindowAnchor::Center);
}

void MoveToRight() {
    MoveTo(WindowAnchor::Right);
}

void MoveToBottomLeft() {
    MoveTo(WindowAnchor::BottomLeft);
}

void MoveToBottom() {
    MoveTo(WindowAnchor::Bottom);
}

void MoveToBottomRight() {
    MoveTo(WindowAnchor::BottomRight);
}

void MoveTo(WindowAnchor anchor) {
    HWND hwnd = GetHandleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::Detail::GetWorkAreaSize();

    LONG targetX, targetY;

    switch (anchor) {
        case WindowAnchor::TopLeft: {
            targetX = 0;
            targetY = 0;
            break;
        }
        case WindowAnchor::Top: {
            targetX = (workAreaSize.cx - extendedFrameBoundsSize.cx) / 2;
            targetY = 0;
            break;
        }
        case WindowAnchor::TopRight: {
            targetX = workAreaSize.cx - extendedFrameBoundsSize.cx;
            targetY = 0;
            break;
        }
        case WindowAnchor::Left: {
            targetX = 0;
            targetY = (workAreaSize.cy - extendedFrameBoundsSize.cy) / 2;
            break;
        }
        case WindowAnchor::Center: {
            targetX = (workAreaSize.cx - extendedFrameBoundsSize.cx) / 2;
            targetY = (workAreaSize.cy - extendedFrameBoundsSize.cy) / 2;
            break;
        }
        case WindowAnchor::Right: {
            targetX = workAreaSize.cx - extendedFrameBoundsSize.cx;
            targetY = (workAreaSize.cy - extendedFrameBoundsSize.cy) / 2;
            break;
        }
        case WindowAnchor::BottomLeft: {
            targetX = 0;
            targetY = workAreaSize.cy - extendedFrameBoundsSize.cy;
            break;
        }
        case WindowAnchor::Bottom: {
            targetX = (workAreaSize.cx - extendedFrameBoundsSize.cx) / 2;
            targetY = workAreaSize.cy - extendedFrameBoundsSize.cy;
            break;
        }
        case WindowAnchor::BottomRight: {
            targetX = workAreaSize.cx - extendedFrameBoundsSize.cx;
            targetY = workAreaSize.cy - extendedFrameBoundsSize.cy;
            break;
        }
        default: {
            throw std::invalid_argument("Unhandled WindowAnchor in MoveTo");
        }
    }

    MoveToImpl(hwnd, targetX, targetY);
}

void MoveTo(LONG targetX, LONG targetY) {
    HWND hwnd = GetHandleWindow();

    MoveToImpl(hwnd, targetX, targetY);
}

}  // namespace Syskos::Window::Detail::Visual
