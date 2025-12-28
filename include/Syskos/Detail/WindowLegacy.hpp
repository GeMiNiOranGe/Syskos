#pragma once
#ifndef WINDOWLEGACY_HPP
#define WINDOWLEGACY_HPP

#include <Windows.h>
#include <stdexcept>

#include <Syskos/Detail/Screen.hpp>
#include <Syskos/Detail/WindowUtilities.hpp>
#include <Syskos/WindowAnchor.hpp>

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
void MoveTo(Syskos::Window::Anchor anchor);
void MoveTo(LONG targetX, LONG targetY);

}  // namespace Syskos::Detail::Window::Legacy

#endif  // end WINDOWLEGACY_HPP
