/**
 * @file ImageViewer.cpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/// @headerfile Internal headers
#include "ImageViewer.hpp"
#include "Logger.hpp"
/// @headerfile System headers
#include <iostream>
/// @headerfile External headers
#include <vtkImageViewer2.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>

/// @brief 
namespace IMG
{
ImageViewer::ImageViewer(const IReader &&image) : imgptr{ std::move(image) } {
}


auto ImageViewer::render() -> void
{
    if (nullptr == imgptr) {
        Logger::Log("ImageViewer::%s imgptr is null", __func__);
        return;
    }
    std::unique_ptr<vtkImageViewer2> imageViewer(new vtkImageViewer2());
    imageViewer->SetInputConnection(imgptr->getOutput());
    std::unique_ptr<vtkRenderWindowInteractor> renderWindowInteractor(new vtkRenderWindowInteractor());
    imageViewer->SetupInteractor(renderWindowInteractor);
    imageViewer->Render();
    imageViewer->GetRenderer()->ResetCamera();
    imageViewer->Render();
    renderWindowInteractor->Start();
}

auto ImageViewer::operator()() -> ImageViewer&
{
    return *this;
}
} // namespace IMG
