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

Syskos::Window::Geometry GetGeometry(bool visual) {
    RECT rect = GetRect(visual);
    Syskos::Window::Geometry geometry;

    geometry.point.x = rect.left;
    geometry.point.y = rect.top;
    geometry.size.cx = rect.right - rect.left;
    geometry.size.cy = rect.bottom - rect.top;

    return geometry;
}

void MoveToTopLeft(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToTopLeft();
    } else {
        Detail::Window::Legacy::MoveToTopLeft();
    }
}

void MoveToTop(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToTop();
    } else {
        Detail::Window::Legacy::MoveToTop();
    }
}

void MoveToTopRight(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToTopRight();
    } else {
        Detail::Window::Legacy::MoveToTopRight();
    }
}

void MoveToLeft(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToLeft();
    } else {
        Detail::Window::Legacy::MoveToLeft();
    }
}

void MoveToCenter(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToCenter();
    } else {
        Detail::Window::Legacy::MoveToCenter();
    }
}

void MoveToRight(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToRight();
    } else {
        Detail::Window::Legacy::MoveToRight();
    }
}

void MoveToBottomLeft(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToBottomLeft();
    } else {
        Detail::Window::Legacy::MoveToBottomLeft();
    }
}

void MoveToBottom(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToBottom();
    } else {
        Detail::Window::Legacy::MoveToBottom();
    }
}

void MoveToBottomRight(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToBottomRight();
    } else {
        Detail::Window::Legacy::MoveToBottomRight();
    }
}

void MoveTo(Syskos::Window::Anchor anchor, bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveTo(anchor);
    } else {
        Detail::Window::Legacy::MoveTo(anchor);
    }
}

void MoveTo(LONG targetX, LONG targetY, bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveTo(targetX, targetY);
    } else {
        Detail::Window::Legacy::MoveTo(targetX, targetY);
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
