#pragma once
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <Windows.h>

namespace Syskos::Detail::Screen {

int GetTaskbarHeight();
SIZE GetWorkAreaSize();

}  // namespace Syskos::Detail::Screen

#endif  // end SCREEN_HPP
