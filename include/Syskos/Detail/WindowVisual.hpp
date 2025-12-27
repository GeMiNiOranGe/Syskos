#pragma once
#ifndef WINDOWVISUAL_HPP
#define WINDOWVISUAL_HPP

#include <Windows.h>
#include <dwmapi.h>
#include <stdexcept>

#include <Syskos/Detail/Screen.hpp>
#include <Syskos/Detail/WindowUtilities.hpp>
#include <Syskos/WindowAnchor.hpp>
#include <Syskos/WindowGeometry.hpp>

#pragma comment(lib, "Dwmapi.lib")

namespace Syskos::Window::Detail::Visual {

HRESULT GetWindowGeometry(WindowGeometry & geometry);

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
