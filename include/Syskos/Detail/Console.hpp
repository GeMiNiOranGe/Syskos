#pragma once
#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <Windows.h>
#include <optional>

namespace Syskos::Detail::Console {

std::optional<COORD> GetCursorPosition();
void SetCursorPosition(SHORT x, SHORT y);

}  // namespace Syskos::Detail::Console

#endif  // end CONSOLE_HPP
