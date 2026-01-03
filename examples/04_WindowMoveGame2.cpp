#include <conio.h>
#include <iostream>

#include <Syskos/Syskos.hpp>

bool CanIncreaseSpeed(int speed);

bool CanDecreaseSpeed(int speed);

// Move axis and bounce when hitting boundary
void UpdateAxis(LONG & position, int & speed, LONG min, LONG max);

int main(int argc, char const * argv[]) {
    constexpr DWORD FRAME_TIME_MS = 16;  // ~60 FPS
    constexpr int KEY_TAB = 9;
    constexpr int KEY_CTRL_TAB = 148;
    constexpr int KEY_ESC = 27;
    constexpr int KEY_SPACE = 32;
    constexpr int KEY_MODE = 'm';

    Syskos::Window::MoveToCenter();

    bool isVisualMode = true, isRunning = false;
    int key = 0;
    int speedX = -1;  // pixels per frame (negative = move left)
    int speedY = -1;  // pixels per frame (negative = move up)

    SIZE workAreaSize = Syskos::Screen::GetWorkAreaSize();
    Syskos::Window::Geometry windowGeometry =
        Syskos::Window::GetGeometry(isVisualMode);

    LONG upperLimitX = workAreaSize.cx - windowGeometry.size.cx;
    LONG upperLimitY = workAreaSize.cy - windowGeometry.size.cy;

    std::cout << "[Esc]        Exit" << '\n';
    std::cout << "[Space]      Pause / Run" << '\n';
    std::cout << "[Tab]        Increase speed" << '\n';
    std::cout << "[Ctrl + Tab] Decrease speed" << '\n';
    std::cout << "[M]          Toggle Move Mode (Default: Visual)" << "\n\n";

    do {
        if (kbhit()) {
            key = _getch();

            if (key == KEY_SPACE) {
                isRunning = !isRunning;
            }

            // Tab or Ctrl + i
            if (key == KEY_TAB && CanIncreaseSpeed(speedX * 2)
                && CanIncreaseSpeed(speedY * 2)) {
                speedX *= 2;
                speedY *= 2;
                std::cout << "Speed increased: " << abs(speedX) << '\n';
            }

            // 148: Ctrl + Tab (Windows console)
            if (key == 0 || key == 224) {
                key = _getch();

                if (key == KEY_CTRL_TAB && CanDecreaseSpeed(speedX / 2)
                    && CanDecreaseSpeed(speedY / 2)) {
                    speedX /= 2;
                    speedY /= 2;
                    std::cout << "Speed decreased: " << abs(speedX) << '\n';
                }
            }

            if (key == KEY_MODE) {
                isVisualMode = !isVisualMode;

                std::string mode = isVisualMode ? "Visual" : "Legacy";
                std::cout << "Current move mode: " << mode << '\n';

                windowGeometry = Syskos::Window::GetGeometry(isVisualMode);

                upperLimitX = workAreaSize.cx - windowGeometry.size.cx;
                upperLimitY = workAreaSize.cy - windowGeometry.size.cy;

                UpdateAxis(windowGeometry.point.x, speedX, 0, upperLimitX);
                UpdateAxis(windowGeometry.point.y, speedY, 0, upperLimitY);

                Syskos::Window::MoveTo(
                    windowGeometry.point.x, windowGeometry.point.y, isVisualMode
                );

                // Simple frame limiter for demo purposes only
                Sleep(FRAME_TIME_MS);
                continue;
            }
        }

        if (isRunning) {
            UpdateAxis(windowGeometry.point.x, speedX, 0, upperLimitX);
            UpdateAxis(windowGeometry.point.y, speedY, 0, upperLimitY);

            Syskos::Window::MoveTo(
                windowGeometry.point.x, windowGeometry.point.y, isVisualMode
            );

            // Simple frame limiter for demo purposes only
            Sleep(FRAME_TIME_MS);
        }
    } while (key != KEY_ESC);

    return 0;
}

bool CanIncreaseSpeed(int speed) {
    const int MAX_SPEED_RATIO = 64;

    return abs(speed) <= MAX_SPEED_RATIO;
}

bool CanDecreaseSpeed(int speed) {
    return abs(speed) >= 1;
}

void UpdateAxis(LONG & position, int & speed, LONG min, LONG max) {
    position -= speed;

    if (position <= min) {
        position = min;
        speed = -speed;
    }

    if (position >= max) {
        position = max;
        speed = -speed;
    }
}
