/**
 * @file main.cpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/// @headerfile System headers
#include <thread>
/// @headerfile Internal headers
#include "Logger.hpp"
#include "Utilities.hpp"
#include "ImageFactory.hpp"
#include "ImageType.hpp"

// Declarations
using namespace IMG;

/// @brief main thread
/// @param arg - integer
/// @param Args - constant array of char
/// @return 0
int main(int argc, const char * argv[])
{
    unused(argc, argv);
    Logger::Log("Image reader has started...");
    
    // Thread to read PNG image
    std::thread([&](){
        auto png = ImageFactory::create(IMG_TYPE::IMG_TYPE_PNG);
        png->setFileName("${fileDirname}/Images/mustang.png");
        png->display();
    }).join();

    // Thread to read JPG image
    std::thread([&](){
        auto jpeg = ImageFactory::create(IMG_TYPE::IMG_TYPE_JPEG);
        jpeg->setFileName("${fileDirname}/Images/mustang.jpg");
        jpeg->display();
    }).join();

    Logger::Log("Image reader has finished.");
    return (EXIT_SUCCESS);
} // main thread
