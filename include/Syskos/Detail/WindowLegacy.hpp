#pragma once
#ifndef WINDOWLEGACY_HPP
#define WINDOWLEGACY_HPP

#include <Windows.h>

#include <Syskos/Detail/Screen.hpp>

namespace Syskos::Detail::Window::Legacy {

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

}  // namespace Syskos::Detail::Window::Legacy

#endif  // end WINDOWLEGACY_HPP
