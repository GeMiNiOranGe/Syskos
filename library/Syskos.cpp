#include <Syskos/Syskos.hpp>

namespace Syskos::Window {

void SetResizable(bool enabled) {
    HWND console = Detail::Window::Utilities::GetConsoleWindowHandle();

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

RECT GetRect(bool useVisualBounds) {
    HWND hwnd = Detail::Window::Utilities::GetConsoleWindowHandle();
    std::optional<RECT> rect;

    if (useVisualBounds) {
        rect = Detail::Window::Visual::GetRect(hwnd);
    } else {
        rect = Detail::Window::Legacy::GetRect(hwnd);
    }

    if (!rect.has_value()) {
        throw std::runtime_error("Failed to get window RECT");
    }

    return rect.value();
}

Geometry GetGeometry(bool useVisualBounds) {
    RECT rect = GetRect(useVisualBounds);
    Geometry geometry;

    geometry.point.x = rect.left;
    geometry.point.y = rect.top;
    geometry.size.cx = rect.right - rect.left;
    geometry.size.cy = rect.bottom - rect.top;

    return geometry;
}

void MoveToTopLeft(bool useVisualBounds) {
    MoveTo(Anchor::TopLeft, useVisualBounds);
}

void MoveToTop(bool useVisualBounds) {
    MoveTo(Anchor::Top, useVisualBounds);
}

void MoveToTopRight(bool useVisualBounds) {
    MoveTo(Anchor::TopRight, useVisualBounds);
}

void MoveToLeft(bool useVisualBounds) {
    MoveTo(Anchor::Left, useVisualBounds);
}

void MoveToCenter(bool useVisualBounds) {
    MoveTo(Anchor::Center, useVisualBounds);
}

void MoveToRight(bool useVisualBounds) {
    MoveTo(Anchor::Right, useVisualBounds);
}

void MoveToBottomLeft(bool useVisualBounds) {
    MoveTo(Anchor::BottomLeft, useVisualBounds);
}

void MoveToBottom(bool useVisualBounds) {
    MoveTo(Anchor::Bottom, useVisualBounds);
}

void MoveToBottomRight(bool useVisualBounds) {
    MoveTo(Anchor::BottomRight, useVisualBounds);
}

void MoveTo(Anchor anchor, bool useVisualBounds) {
    SIZE windowSize = GetGeometry(useVisualBounds).size;
    SIZE workAreaSize = Screen::GetWorkAreaSize();

    LONG targetX, targetY;

    switch (anchor) {
        case Anchor::TopLeft: {
            targetX = 0;
            targetY = 0;
            break;
        }
        case Anchor::Top: {
            targetX = (workAreaSize.cx - windowSize.cx) / 2;
            targetY = 0;
            break;
        }
        case Anchor::TopRight: {
            targetX = workAreaSize.cx - windowSize.cx;
            targetY = 0;
            break;
        }
        case Anchor::Left: {
            targetX = 0;
            targetY = (workAreaSize.cy - windowSize.cy) / 2;
            break;
        }
        case Anchor::Center: {
            targetX = (workAreaSize.cx - windowSize.cx) / 2;
            targetY = (workAreaSize.cy - windowSize.cy) / 2;
            break;
        }
        case Anchor::Right: {
            targetX = workAreaSize.cx - windowSize.cx;
            targetY = (workAreaSize.cy - windowSize.cy) / 2;
            break;
        }
        case Anchor::BottomLeft: {
            targetX = 0;
            targetY = workAreaSize.cy - windowSize.cy;
            break;
        }
        case Anchor::Bottom: {
            targetX = (workAreaSize.cx - windowSize.cx) / 2;
            targetY = workAreaSize.cy - windowSize.cy;
            break;
        }
        case Anchor::BottomRight: {
            targetX = workAreaSize.cx - windowSize.cx;
            targetY = workAreaSize.cy - windowSize.cy;
            break;
        }
        default: {
            throw std::invalid_argument("Unhandled Anchor in MoveTo");
        }
    }

    MoveTo(targetX, targetY, useVisualBounds);
}

void MoveTo(LONG targetX, LONG targetY, bool useVisualBounds) {
    HWND hwnd = Detail::Window::Utilities::GetConsoleWindowHandle();

    if (useVisualBounds) {
        Detail::Window::Visual::MoveTo(hwnd, targetX, targetY);
    } else {
        Detail::Window::Legacy::MoveTo(hwnd, targetX, targetY);
    }
}

void Resize(LONG width, LONG height) {
    RECT client, bounds;
    POINT offset;
    HWND hwnd = Detail::Window::Utilities::GetConsoleWindowHandle();
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
