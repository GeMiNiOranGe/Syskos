#include <Syskos/Detail/Screen.hpp>

namespace Syskos::Screen::Detail {

int GetTaskbarHeight() {
    RECT rect;
    HWND taskbar = FindWindow("Shell_traywnd", NULL);
    GetWindowRect(taskbar, &rect);
    int height = rect.bottom - rect.top;
    return height;
}

SIZE GetWorkAreaSize() {
    RECT workArea;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0);
    LONG cx = workArea.right - workArea.left;
    LONG cy = workArea.bottom - workArea.top;
    return {cx, cy};
}

}  // namespace Syskos::Screen::Detail
