#pragma once
#ifndef WINDOWVISUAL_HPP
#define WINDOWVISUAL_HPP

#include <Windows.h>
#include <dwmapi.h>
#include <optional>
#include <stdexcept>

#include <Syskos/Detail/Screen.hpp>
#include <Syskos/Detail/WindowUtilities.hpp>
#include <Syskos/WindowAnchor.hpp>

#pragma comment(lib, "Dwmapi.lib")

namespace Syskos::Detail::Window::Visual {

std::optional<RECT> GetRect(HWND hwnd);

void MoveToTopLeft();
void MoveToTop();
void MoveToTopRight();
void MoveToLeft();
void MoveToCenter();
void MoveToRight();
void MoveToBottomLeft();
void MoveToBottom();
void MoveToBottomRight();
void MoveTo(Syskos::Window::Anchor anchor);
void MoveTo(LONG targetX, LONG targetY);

}  // namespace Syskos::Detail::Window::Visual

#endif  // end WINDOWVISUAL_HPP
