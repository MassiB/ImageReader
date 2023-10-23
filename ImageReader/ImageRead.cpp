/**
 * @file ImageRead.cpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/// @headerfile Internal headers
#include "ImageRead.hpp"
#include "ImageViewer.hpp"
#include "Logger.hpp"

/// @brief 
namespace IMG
{
template < typename T >
ImageRead<T>::ImageRead() : mptr{ new T() } {
}

template< typename T >
auto ImageRead<T>::setFileName(const char * filepath) -> void
{
    mptr->SetFileName(filepath);
    Logger::Log("ImageRead::%s file path: %s", __func__, filepath);
}

template < typename T >
auto ImageRead<T>::display() -> void
{
    ImageViewer(mptr).render();
    Logger::Log("ImageRead::%s image displayed", __func__);
}

template< typename T >
vtkAlgorithmOutput* ImageRead<T>::getOutput() const
{
    if (nullptr == mptr) {
        Logger::Log("ImageRead::%s mptr is null", __func__);
        return nullptr;
    }
    return mptr->GetOutputPort();
}
} // namespace IMG
