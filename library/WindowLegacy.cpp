#include <Syskos/Detail/WindowLegacy.hpp>

namespace {

void MoveToImpl(HWND hwnd, LONG targetX, LONG targetY) {
    RECT bounds;
    GetWindowRect(hwnd, &bounds);

    int width = bounds.right - bounds.left;
    int height = bounds.bottom - bounds.top;

    MoveWindow(hwnd, targetX, targetY, width, height, TRUE);
}

}  // namespace

namespace Syskos::Detail::Window::Legacy {

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
    SIZE workAreaSize = Screen::GetWorkAreaSize();
    RECT bounds;
    GetWindowRect(hwnd, &bounds);

    LONG targetX, targetY;

    switch (anchor) {
        case Syskos::Window::Anchor::TopLeft: {
            targetX = 0;
            targetY = 0;
            break;
        }
        case Syskos::Window::Anchor::Top: {
            targetX = workAreaSize.cx / 2 - (bounds.right - bounds.left) / 2;
            targetY = 0;
            break;
        }
        case Syskos::Window::Anchor::TopRight: {
            targetX = workAreaSize.cx - (bounds.right - bounds.left);
            targetY = 0;
            break;
        }
        case Syskos::Window::Anchor::Left: {
            targetX = 0;
            targetY = workAreaSize.cy / 2 - (bounds.bottom - bounds.top) / 2;
            break;
        }
        case Syskos::Window::Anchor::Center: {
            targetX = workAreaSize.cx / 2 - (bounds.right - bounds.left) / 2;
            targetY = workAreaSize.cy / 2 - (bounds.bottom - bounds.top) / 2;
            break;
        }
        case Syskos::Window::Anchor::Right: {
            targetX = workAreaSize.cx - (bounds.right - bounds.left);
            targetY = workAreaSize.cy / 2 - (bounds.bottom - bounds.top) / 2;
            break;
        }
        case Syskos::Window::Anchor::BottomLeft: {
            targetX = 0;
            targetY = workAreaSize.cy - (bounds.bottom - bounds.top);
            break;
        }
        case Syskos::Window::Anchor::Bottom: {
            targetX = workAreaSize.cx / 2 - (bounds.right - bounds.left) / 2;
            targetY = workAreaSize.cy - (bounds.bottom - bounds.top);
            break;
        }
        case Syskos::Window::Anchor::BottomRight: {
            targetX = workAreaSize.cx - (bounds.right - bounds.left);
            targetY = workAreaSize.cy - (bounds.bottom - bounds.top);
            break;
        }
        default: {
            throw std::invalid_argument("Unhandled Anchor in MoveTo");
        }
    }

    MoveToImpl(hwnd, targetX, targetY);
}

void MoveTo(LONG targetX, LONG targetY) {
    HWND hwnd = GetConsoleWindow();

    MoveToImpl(hwnd, targetX, targetY);
}

}  // namespace Syskos::Detail::Window::Legacy
