/**
 * @file Logger.cpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/// @headerfile Internal headers
#include "Logger.hpp"
#include "Utilities.hpp"

std::ofstream Logger::mfile(FILE_NAME);
std::mutex Logger::mmutex;

template < typename... Args >
auto Logger::Log(const char * message, Args&&... args) -> void
{
    std::lock_guard<std::mutex> guard(mmutex);
    char buff[DTTMSZ];
    mfile.open(FILE_NAME);
    mfile << getDtTm(buff) << ": " << message << " ";
    (mfile << ... << std::forward<Args>(args)); 
    mfile.close();
}

auto Logger::Log(const char * message) -> void
{
    std::lock_guard<std::mutex> guard(mmutex);
    char buff[DTTMSZ];
    mfile.open(FILE_NAME);
    mfile << getDtTm(buff) << ": " << message << std::endl; 
    mfile.close();
}
