#pragma once
#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <Windows.h>

namespace Syskos::Screen::Detail {

int GetTaskbarHeight();
SIZE GetWorkAreaSize();

}  // namespace Syskos::Screen::Detail

#endif  // end SCREEN_HPP
