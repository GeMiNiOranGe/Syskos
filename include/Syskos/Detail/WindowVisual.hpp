#pragma once
#ifndef WINDOWVISUAL_HPP
#define WINDOWVISUAL_HPP

#include <Windows.h>
#include <dwmapi.h>

#include <Syskos/Detail/Screen.hpp>

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
void MoveTo(LONG xCoord, LONG yCoord);

}  // namespace Syskos::Window::Detail::Visual

#endif  // end WINDOWVISUAL_HPP
