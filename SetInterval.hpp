#pragma once

#include <thread>
#include <chrono>

/**
 * @def setInterval(code, interval)
 * @brief Executes the specified code block at regular intervals.
 *
 * This macro creates a detached C++ thread that repeatedly executes the provided
 * code block at the specified interval.
 *
 * @param code The code block to be executed at each interval.
 * @param interval The time interval (in milliseconds) at which the code block should be executed.
 *
 * Example usage:
 * @code
 * setInterval({
 *     std::cout << "hi!";
 * }, 1000);
 * @endcode
 */
#define setInterval(code, interval)                                               \
    do {                                                                          \
        std::thread([this]() {                                                    \
            while (true) {                                                        \
                code;                                                             \
                                                                                  \
                std::this_thread::sleep_for(std::chrono::milliseconds(interval)); \
            }                                                                     \
        }).detach();                                                              \
    } while (0)
