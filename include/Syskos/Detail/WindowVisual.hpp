#pragma once
#ifndef WINDOWVISUAL_HPP
#define WINDOWVISUAL_HPP

#include <Windows.h>
#include <dwmapi.h>
#include <optional>

#include <Syskos/Detail/WindowLegacy.hpp>

#pragma comment(lib, "Dwmapi.lib")

namespace Syskos::Detail::Window::Visual {

std::optional<RECT> GetRect(HWND hwnd);

void MoveTo(HWND hwnd, LONG targetX, LONG targetY);

}  // namespace Syskos::Detail::Window::Visual

#endif  // end WINDOWVISUAL_HPP
