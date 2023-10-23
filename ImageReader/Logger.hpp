/**
 * @file Logger.hpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef LOGGER_HPP_
#define LOGGER_HPP_
/// @headerfile System headers
#include <fstream>
#include <thread>
#include <mutex>

/// @brief 
class Logger final
{
public:
    /// @brief 
    Logger() = delete;
    Logger(const Logger &) = delete;
    Logger(const Logger &&) = delete;
    auto operator=(const Logger &) -> Logger& = delete;
    auto operator=(const Logger &&) -> Logger& = delete;
    /// @brief 
    /// @tparam ...Args 
    /// @param message 
    /// @param ...args 
    /// @return 
    template < typename... Args >
    static auto Log(const char * message, Args&&... args) -> void;
    /// @brief 
    /// @param message 
    /// @return
    static auto Log(const char * message) -> void;
private:
    static std::ofstream mfile;
    static std::mutex mmutex;
};

#endif // LOGGER_HPP_
