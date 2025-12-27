#pragma once
#ifndef WINDOWSTANDARD_HPP
#define WINDOWSTANDARD_HPP

#include <Windows.h>

#include <Syskos/Detail/Screen.hpp>

namespace Syskos::Detail::Window::Standard {

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

}  // namespace Syskos::Detail::Window::Standard

#endif  // end WINDOWSTANDARD_HPP
