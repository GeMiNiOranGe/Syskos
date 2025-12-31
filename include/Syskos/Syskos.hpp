#pragma once
#ifndef SYSKOS_HPP
#define SYSKOS_HPP

#include <Windows.h>
#include <stdexcept>

#include <Syskos/Detail/Console.hpp>
#include <Syskos/Detail/Screen.hpp>
#include <Syskos/Detail/WindowUtilities.hpp>
#include <Syskos/Detail/WindowVisual.hpp>
#include <Syskos/WindowAnchor.hpp>
#include <Syskos/WindowGeometry.hpp>

namespace Syskos::Console {

COORD GetCursorPosition();

inline void SetCursorPosition(SHORT x, SHORT y) {
    Detail::Console::SetCursorPosition(x, y);
}

}  // namespace Syskos::Console

namespace Syskos::Window {

void SetResizable(bool enabled);

RECT GetRect(bool useVisualBounds = true);
Geometry GetGeometry(bool useVisualBounds = true);

void MoveToTopLeft(bool useVisualBounds = true);
void MoveToTop(bool useVisualBounds = true);
void MoveToTopRight(bool useVisualBounds = true);
void MoveToLeft(bool useVisualBounds = true);
void MoveToCenter(bool useVisualBounds = true);
void MoveToRight(bool useVisualBounds = true);
void MoveToBottomLeft(bool useVisualBounds = true);
void MoveToBottom(bool useVisualBounds = true);
void MoveToBottomRight(bool useVisualBounds = true);
void MoveTo(Anchor anchor, bool useVisualBounds = true);
void MoveTo(LONG targetX, LONG targetY, bool useVisualBounds = true);

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
