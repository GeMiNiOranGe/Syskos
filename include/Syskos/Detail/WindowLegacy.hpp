#pragma once
#ifndef WINDOWLEGACY_HPP
#define WINDOWLEGACY_HPP

#include <Windows.h>
#include <optional>

namespace Syskos::Detail::Window::Legacy {

std::optional<RECT> GetRect(HWND hwnd);

void MoveTo(HWND hwnd, LONG targetX, LONG targetY);

}  // namespace Syskos::Detail::Window::Legacy

#endif  // end WINDOWLEGACY_HPP
