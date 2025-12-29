#include <Syskos/Syskos.hpp>

namespace Syskos::Window {

void SetResizable(bool enabled) {
    HWND console = Detail::Window::Utilities::GetHandleWindow();

    LONG style = GetWindowLong(console, GWL_STYLE);

    if (enabled) {
        // Add resize border and maximize button
        style |= WS_SIZEBOX;
        style |= WS_MAXIMIZEBOX;
    } else {
        // Remove resize border and maximize button
        style &= ~WS_SIZEBOX;
        style &= ~WS_MAXIMIZEBOX;
    }

    SetWindowLong(console, GWL_STYLE, style);
}

RECT GetRect(bool visual) {
    HWND hwnd = Detail::Window::Utilities::GetHandleWindow();
    std::optional<RECT> rect;

    if (visual) {
        rect = Detail::Window::Visual::GetRect(hwnd);
    } else {
        rect = Detail::Window::Legacy::GetRect(hwnd);
    }

    if (!rect.has_value()) {
        throw std::runtime_error("Failed to get window RECT");
    }

    return rect.value();
}

Geometry GetGeometry(bool visual) {
    RECT rect = GetRect(visual);
    Geometry geometry;

    geometry.point.x = rect.left;
    geometry.point.y = rect.top;
    geometry.size.cx = rect.right - rect.left;
    geometry.size.cy = rect.bottom - rect.top;

    return geometry;
}

void MoveToTopLeft(bool visual) {
    MoveTo(Anchor::TopLeft, visual);
}

void MoveToTop(bool visual) {
    MoveTo(Anchor::Top, visual);
}

void MoveToTopRight(bool visual) {
    MoveTo(Anchor::TopRight, visual);
}

void MoveToLeft(bool visual) {
    MoveTo(Anchor::Left, visual);
}

void MoveToCenter(bool visual) {
    MoveTo(Anchor::Center, visual);
}

void MoveToRight(bool visual) {
    MoveTo(Anchor::Right, visual);
}

void MoveToBottomLeft(bool visual) {
    MoveTo(Anchor::BottomLeft, visual);
}

void MoveToBottom(bool visual) {
    MoveTo(Anchor::Bottom, visual);
}

void MoveToBottomRight(bool visual) {
    MoveTo(Anchor::BottomRight, visual);
}

void MoveTo(Anchor anchor, bool visual) {
    SIZE boundsSize = GetGeometry(visual).size;
    SIZE workAreaSize = Screen::GetWorkAreaSize();

    LONG targetX, targetY;

    switch (anchor) {
        case Anchor::TopLeft: {
            targetX = 0;
            targetY = 0;
            break;
        }
        case Anchor::Top: {
            targetX = (workAreaSize.cx - boundsSize.cx) / 2;
            targetY = 0;
            break;
        }
        case Anchor::TopRight: {
            targetX = workAreaSize.cx - boundsSize.cx;
            targetY = 0;
            break;
        }
        case Anchor::Left: {
            targetX = 0;
            targetY = (workAreaSize.cy - boundsSize.cy) / 2;
            break;
        }
        case Anchor::Center: {
            targetX = (workAreaSize.cx - boundsSize.cx) / 2;
            targetY = (workAreaSize.cy - boundsSize.cy) / 2;
            break;
        }
        case Anchor::Right: {
            targetX = workAreaSize.cx - boundsSize.cx;
            targetY = (workAreaSize.cy - boundsSize.cy) / 2;
            break;
        }
        case Anchor::BottomLeft: {
            targetX = 0;
            targetY = workAreaSize.cy - boundsSize.cy;
            break;
        }
        case Anchor::Bottom: {
            targetX = (workAreaSize.cx - boundsSize.cx) / 2;
            targetY = workAreaSize.cy - boundsSize.cy;
            break;
        }
        case Anchor::BottomRight: {
            targetX = workAreaSize.cx - boundsSize.cx;
            targetY = workAreaSize.cy - boundsSize.cy;
            break;
        }
        default: {
            throw std::invalid_argument("Unhandled Anchor in MoveTo");
        }
    }

    MoveTo(targetX, targetY, visual);
}

void MoveTo(LONG targetX, LONG targetY, bool visual) {
    HWND hwnd = Detail::Window::Utilities::GetHandleWindow();

    if (visual) {
        Detail::Window::Visual::MoveTo(hwnd, targetX, targetY);
    } else {
        Detail::Window::Legacy::MoveTo(hwnd, targetX, targetY);
    }
}

void Resize(LONG width, LONG height) {
    RECT client, bounds;
    POINT offset;
    HWND hwnd = Detail::Window::Utilities::GetHandleWindow();
    GetClientRect(hwnd, &client);
    GetWindowRect(hwnd, &bounds);

    offset.x = (bounds.right - bounds.left) - client.right;
    offset.y = (bounds.bottom - bounds.top) - client.bottom;

    LONG finalWidth = width + offset.x;
    LONG finalHeight = height + offset.y;

    MoveWindow(hwnd, bounds.left, bounds.top, finalWidth, finalHeight, TRUE);
}

void ResizeByChars(int columns, int rows) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // nFont is usually 0 for the default font
    CONSOLE_FONT_INFO cfi{};
    if (!GetCurrentConsoleFont(hOut, FALSE, &cfi)) {
        return;
    }

    // Size of a charactor (pixel)
    COORD fontSize = GetConsoleFontSize(hOut, cfi.nFont);

    LONG charWidthPx = fontSize.X;
    LONG charHeightPx = fontSize.Y;

    LONG targetClientWidth = columns * charWidthPx;
    LONG targetClientHeight = rows * charHeightPx;

    Resize(targetClientWidth, targetClientHeight);
}

}  // namespace Syskos::Window
