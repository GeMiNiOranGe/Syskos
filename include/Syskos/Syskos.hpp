#pragma once
#ifndef SYSKOS_HPP
#define SYSKOS_HPP

#include <Windows.h>
#include <stdexcept>

#include <Syskos/Detail/Screen.hpp>
#include <Syskos/Detail/WindowUtilities.hpp>
#include <Syskos/Detail/WindowVisual.hpp>
#include <Syskos/WindowAnchor.hpp>
#include <Syskos/WindowGeometry.hpp>

namespace Syskos::Window {

void SetResizable(bool enabled);

RECT GetRect(bool visual = true);
Geometry GetGeometry(bool visual = true);

void MoveToTopLeft(bool visual = true);
void MoveToTop(bool visual = true);
void MoveToTopRight(bool visual = true);
void MoveToLeft(bool visual = true);
void MoveToCenter(bool visual = true);
void MoveToRight(bool visual = true);
void MoveToBottomLeft(bool visual = true);
void MoveToBottom(bool visual = true);
void MoveToBottomRight(bool visual = true);
void MoveTo(Anchor anchor, bool visual = true);
void MoveTo(LONG targetX, LONG targetY, bool visual = true);

void Resize(LONG width, LONG height);
void ResizeByChars(int columns, int rows);

}  // namespace Syskos::Window

namespace Syskos::Screen {

inline SIZE GetWorkAreaSize() {
    return Detail::Screen::GetWorkAreaSize();
}

inline int GetTaskbarHeight() {
    return Detail::Screen::GetTaskbarHeight();
}

}  // namespace Syskos::Screen

#endif  // end SYSKOS_HPP
