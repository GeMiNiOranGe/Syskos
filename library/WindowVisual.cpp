#include <Syskos/Detail/WindowVisual.hpp>

namespace Syskos::Detail::Window::Visual {

std::optional<RECT> GetRect(HWND hwnd) {
    RECT bounds{};
    HRESULT result = DwmGetWindowAttribute(
        hwnd, DWMWA_EXTENDED_FRAME_BOUNDS, &bounds, sizeof(bounds)
    );

    if (FAILED(result)) {
        return std::nullopt;
    }

    return bounds;
}

void MoveTo(HWND hwnd, LONG targetX, LONG targetY) {
    std::optional<RECT> bounds = GetRect(hwnd);

    if (!bounds) {
        return;
    }

    std::optional<RECT> window = Legacy::GetRect(hwnd);

    if (!window) {
        return;
    }

    LONG offsetX = bounds.value().left - window.value().left;
    LONG offsetY = bounds.value().top - window.value().top;

    LONG adjustedX = targetX - offsetX;
    LONG adjustedY = targetY - offsetY;

    LONG width = window.value().right - window.value().left;
    LONG height = window.value().bottom - window.value().top;

    MoveWindow(hwnd, adjustedX, adjustedY, width, height, TRUE);
}

}  // namespace Syskos::Detail::Window::Visual
