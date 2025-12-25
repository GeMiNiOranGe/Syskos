#pragma once
#ifndef WINDOWVISUAL_HPP
#define WINDOWVISUAL_HPP

#include <Windows.h>
#include <dwmapi.h>
#include <stdexcept>

#include <Syskos/Detail/Screen.hpp>
#include <Syskos/WindowAnchor.hpp>

#pragma comment(lib, "Dwmapi.lib")

namespace Syskos::Window::Detail::Visual {

void MoveToTopLeft();
void MoveToTop();
void MoveToTopRight();
void MoveToLeft();
void MoveToCenter();
void MoveToRight();
void MoveToBottomLeft();
void MoveToBottom();
void MoveToBottomRight();
void MoveTo(WindowAnchor anchor);
void MoveTo(LONG targetX, LONG targetY);

}  // namespace Syskos::Window::Detail::Visual

#endif  // end WINDOWVISUAL_HPP
