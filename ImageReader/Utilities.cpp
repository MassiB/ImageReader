/**
 * @file Utilities.cpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/// @headerfile Internal headers
#include "Utilities.hpp"

auto getDtTm (char *buff) -> char *
{
    std::time_t t = std::time(0);
    std::strftime (buff, DTTMSZ, DTTMFMT, std::localtime (&t));
    return buff;
}
