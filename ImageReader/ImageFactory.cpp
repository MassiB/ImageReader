/**
 * @file ImageFactory.cpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/// @headerfile Internal headers
#include "ImageFactory.hpp"
#include "ImageRead.hpp"
#include "Logger.hpp"
/// @headerfile External headers
#include <vtkPNGReader.h>
#include <vtkImageData.h>
#include <vtkJPEGReader.h>
#include <vtkBMPReader.h>
#include <vtkDICOMImageReader.h>

/// @brief 
namespace IMG
{
auto ImageFactory::create(IMG_TYPE type) -> std::unique_ptr<IReader>
{
    switch (type)
    {
        case IMG_TYPE::IMG_TYPE_IMAGE_DATA:
            Logger::Log("Creating image data");
            return std::unique_ptr<ImageRead<vtkImageData>>();
        break;
        case IMG_TYPE::IMG_TYPE_PNG:
            Logger::Log("Creating PNG image");
            return std::unique_ptr<ImageRead<vtkPNGReader>>();
        break;
        case IMG_TYPE::IMG_TYPE_JPEG:
            Logger::Log("Creating JPEG image");
            return std::unique_ptr<ImageRead<vtkJPEGReader>>();
        break;
        case IMG_TYPE::IMG_TYPE_BMP:
            Logger::Log("Creating BMP image");
            return std::unique_ptr<ImageRead<vtkBMPReader>>();
        break;
        case IMG_TYPE::IMG_TYPE_DICOM:
            Logger::Log("Creating dicom image");
            return std::unique_ptr<ImageRead<vtkDICOMImageReader>>();
        break;
        default:
            Logger::Log("Image type not supported");
            return nullptr;
    }
}
} /* namespace IMG */
