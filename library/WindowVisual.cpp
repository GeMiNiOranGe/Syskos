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

namespace Syskos::Detail::Window::Visual {

HRESULT GetGeometry(Syskos::Window::Geometry & geometry) {
    HWND hwnd = Utilities::GetHandleWindow();

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
    MoveTo(Syskos::Window::Anchor::TopLeft);
}

void MoveToTop() {
    MoveTo(Syskos::Window::Anchor::Top);
}

void MoveToTopRight() {
    MoveTo(Syskos::Window::Anchor::TopRight);
}

void MoveToLeft() {
    MoveTo(Syskos::Window::Anchor::Left);
}

void MoveToCenter() {
    MoveTo(Syskos::Window::Anchor::Center);
}

void MoveToRight() {
    MoveTo(Syskos::Window::Anchor::Right);
}

void MoveToBottomLeft() {
    MoveTo(Syskos::Window::Anchor::BottomLeft);
}

void MoveToBottom() {
    MoveTo(Syskos::Window::Anchor::Bottom);
}

void MoveToBottomRight() {
    MoveTo(Syskos::Window::Anchor::BottomRight);
}

void MoveTo(Syskos::Window::Anchor anchor) {
    HWND hwnd = Utilities::GetHandleWindow();
    SIZE extendedFrameBoundsSize = GetExtendedFrameBoundsSize(hwnd);
    SIZE workAreaSize = Screen::GetWorkAreaSize();

    LONG targetX, targetY;

    switch (anchor) {
        case Syskos::Window::Anchor::TopLeft: {
            targetX = 0;
            targetY = 0;
            break;
        }
        case Syskos::Window::Anchor::Top: {
            targetX = (workAreaSize.cx - extendedFrameBoundsSize.cx) / 2;
            targetY = 0;
            break;
        }
        case Syskos::Window::Anchor::TopRight: {
            targetX = workAreaSize.cx - extendedFrameBoundsSize.cx;
            targetY = 0;
            break;
        }
        case Syskos::Window::Anchor::Left: {
            targetX = 0;
            targetY = (workAreaSize.cy - extendedFrameBoundsSize.cy) / 2;
            break;
        }
        case Syskos::Window::Anchor::Center: {
            targetX = (workAreaSize.cx - extendedFrameBoundsSize.cx) / 2;
            targetY = (workAreaSize.cy - extendedFrameBoundsSize.cy) / 2;
            break;
        }
        case Syskos::Window::Anchor::Right: {
            targetX = workAreaSize.cx - extendedFrameBoundsSize.cx;
            targetY = (workAreaSize.cy - extendedFrameBoundsSize.cy) / 2;
            break;
        }
        case Syskos::Window::Anchor::BottomLeft: {
            targetX = 0;
            targetY = workAreaSize.cy - extendedFrameBoundsSize.cy;
            break;
        }
        case Syskos::Window::Anchor::Bottom: {
            targetX = (workAreaSize.cx - extendedFrameBoundsSize.cx) / 2;
            targetY = workAreaSize.cy - extendedFrameBoundsSize.cy;
            break;
        }
        case Syskos::Window::Anchor::BottomRight: {
            targetX = workAreaSize.cx - extendedFrameBoundsSize.cx;
            targetY = workAreaSize.cy - extendedFrameBoundsSize.cy;
            break;
        }
        default: {
            throw std::invalid_argument("Unhandled Anchor in MoveTo");
        }
    }

    MoveToImpl(hwnd, targetX, targetY);
}

void MoveTo(LONG targetX, LONG targetY) {
    HWND hwnd = Utilities::GetHandleWindow();

    MoveToImpl(hwnd, targetX, targetY);
}

}  // namespace Syskos::Detail::Window::Visual
