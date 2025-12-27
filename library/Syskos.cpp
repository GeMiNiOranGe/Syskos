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

HRESULT GetGeometry(Geometry & geometry) {
    return Detail::Window::Visual::GetGeometry(geometry);
}

void MoveToTopLeft(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToTopLeft();
    } else {
        Detail::Window::Standard::MoveToTopLeft();
    }
}

void MoveToTop(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToTop();
    } else {
        Detail::Window::Standard::MoveToTop();
    }
}

void MoveToTopRight(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToTopRight();
    } else {
        Detail::Window::Standard::MoveToTopRight();
    }
}

void MoveToLeft(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToLeft();
    } else {
        Detail::Window::Standard::MoveToLeft();
    }
}

void MoveToCenter(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToCenter();
    } else {
        Detail::Window::Standard::MoveToCenter();
    }
}

void MoveToRight(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToRight();
    } else {
        Detail::Window::Standard::MoveToRight();
    }
}

void MoveToBottomLeft(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToBottomLeft();
    } else {
        Detail::Window::Standard::MoveToBottomLeft();
    }
}

void MoveToBottom(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToBottom();
    } else {
        Detail::Window::Standard::MoveToBottom();
    }
}

void MoveToBottomRight(bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveToBottomRight();
    } else {
        Detail::Window::Standard::MoveToBottomRight();
    }
}

void MoveTo(LONG xCoord, LONG yCoord, bool visual) {
    if (visual) {
        Detail::Window::Visual::MoveTo(xCoord, yCoord);
    } else {
        Detail::Window::Standard::MoveTo(xCoord, yCoord);
    }
}

void Resize(LONG width, LONG height) {
    RECT client, bounds;
    POINT offset;
    HWND hwnd = Detail::Window::Utilities::GetHandleWindow();
    GetClientRect(hwnd, &client);
    GetWindowRect(hwnd, &bounds);
    // find the offset to add to the screen (e.g: x = 33, y = 39)
    offset.x = (bounds.right - bounds.left) - client.right;
    offset.y = (bounds.bottom - bounds.top) - client.bottom;
    LONG finalWidth = width + offset.x;
    LONG finalHeight = height + offset.y;
    MoveWindow(hwnd, bounds.left, bounds.top, finalWidth, finalHeight, TRUE);
}

}  // namespace Syskos::Window
