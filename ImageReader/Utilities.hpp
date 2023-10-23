/**
 * @file Utilities.hpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

/// @headerfile System headers
#include <time.h>
#include <chrono>
#include <utility>

#define FILE_NAME "Logging.txt"
#define DTTMFMT "%Y-%m-%d %H:%M:%S "
#define DTTMSZ 21

/// @brief 
/// @tparam ...Args 
/// @param ...arg 
/// @return 
template < typename... Args >
auto unused(Args... arg) -> void { /* do nothing */ }

/// @brief 
enum class STATUS
{
    SUCCESS,
    FAILED
};

/// @brief 
/// @param buff 
/// @return 
auto getDtTm (char *buff) -> char *;

#endif // UTILITIES_HPP_
