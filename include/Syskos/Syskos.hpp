#pragma once
#ifndef SYSUTILS_HPP
#define SYSUTILS_HPP

#include <Windows.h>

#include <Syskos/Detail/WindowStandard.hpp>
#include <Syskos/Detail/WindowVisual.hpp>

namespace Syskos::Window {

void SetResizable(bool enabled);

HRESULT GetGeometry(Geometry & geometry);

void MoveToTopLeft(bool visual = true);
void MoveToTop(bool visual = true);
void MoveToTopRight(bool visual = true);
void MoveToLeft(bool visual = true);
void MoveToCenter(bool visual = true);
void MoveToRight(bool visual = true);
void MoveToBottomLeft(bool visual = true);
void MoveToBottom(bool visual = true);
void MoveToBottomRight(bool visual = true);
void MoveTo(LONG xCoord, LONG yCoord, bool visual = true);
void Resize(LONG width, LONG height);

}  // namespace Syskos::Window

namespace Syskos::Screen {

inline SIZE GetWorkAreaSize() {
    return Detail::Screen::GetWorkAreaSize();
}

inline int GetTaskbarHeight() {
    return Detail::Screen::GetTaskbarHeight();
}

}  // namespace Syskos::Screen

#endif  // end SYSUTILS_HPP
