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

/**
 * @def setTimeout(code, timeout)
 * @brief Executes the specified code block after a specified timeout.
 *
 * This macro creates a C++ thread that waits for the specified timeout
 * and then executes the provided code block.
 *
 * @param code The code block to be executed after the timeout.
 * @param timeout The time duration (in milliseconds) to wait before executing the code block.
 *
 * Example usage:
 * @code
 * setTimeout({
 *     std::cout << "Delayed execution!";
 * }, 2000);
 * @endcode
 */
#define setTimeout(code, timeout)                                            \
    do {                                                                     \
        std::thread([=]() {                                                  \
            std::this_thread::sleep_for(std::chrono::milliseconds(timeout)); \
                                                                             \
            code;                                                            \
        }).detach();                                                         \
    } while (0)
