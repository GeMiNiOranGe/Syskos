#include <syskos/syskos.hpp>

namespace Syskos::Window {

HRESULT GetWindowGeometry(WindowGeometry & geometry) {
    return Detail::Visual::GetWindowGeometry(geometry);
}

void MoveToTopLeft(bool visual) {
    if (visual) {
        Detail::Visual::MoveToTopLeft();
    } else {
        Detail::Standard::MoveToTopLeft();
    }
}

void MoveToTop(bool visual) {
    if (visual) {
        Detail::Visual::MoveToTop();
    } else {
        Detail::Standard::MoveToTop();
    }
}

void MoveToTopRight(bool visual) {
    if (visual) {
        Detail::Visual::MoveToTopRight();
    } else {
        Detail::Standard::MoveToTopRight();
    }
}

void MoveToLeft(bool visual) {
    if (visual) {
        Detail::Visual::MoveToLeft();
    } else {
        Detail::Standard::MoveToLeft();
    }
}

void MoveToCenter(bool visual) {
    if (visual) {
        Detail::Visual::MoveToCenter();
    } else {
        Detail::Standard::MoveToCenter();
    }
}

void MoveToRight(bool visual) {
    if (visual) {
        Detail::Visual::MoveToRight();
    } else {
        Detail::Standard::MoveToRight();
    }
}

void MoveToBottomLeft(bool visual) {
    if (visual) {
        Detail::Visual::MoveToBottomLeft();
    } else {
        Detail::Standard::MoveToBottomLeft();
    }
}

void MoveToBottom(bool visual) {
    if (visual) {
        Detail::Visual::MoveToBottom();
    } else {
        Detail::Standard::MoveToBottom();
    }
}

void MoveToBottomRight(bool visual) {
    if (visual) {
        Detail::Visual::MoveToBottomRight();
    } else {
        Detail::Standard::MoveToBottomRight();
    }
}

void MoveTo(LONG xCoord, LONG yCoord, bool visual) {
    if (visual) {
        Detail::Visual::MoveTo(xCoord, yCoord);
    } else {
        Detail::Standard::MoveTo(xCoord, yCoord);
    }
}

void Resize(LONG width, LONG height) {
    RECT client, bounds;
    POINT offset;
    HWND hwnd = GetConsoleWindow();
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
