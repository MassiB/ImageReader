/**
 * @file ImageRead.hpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef IMAGEREAD_HPP_
#define IMAGEREAD_HPP_
/// @headerfile Internal headers
#include "IReader.hpp"
/// @headerfile System headers
#include <memory>
/// @headerfile External headers
#include <vtkImageReader2.h>

/// @brief 
namespace IMG
{
/// @brief 
/// @tparam T 
template < typename T = vtkImageReader2 >
class ImageRead : public IReader
{
public:
    /// @brief 
    ImageRead();
    /// @brief 
    ~ImageRead() = default;
    /// @brief 
    /// @param filepath 
    /// @return 
    auto setFileName(const char * filepath) -> void override;
    /// @brief 
    auto display() -> void override;
    /// @brief 
    /// @return 
    vtkAlgorithmOutput *getOutput() const override;
private:
    /// @brief 
    std::unique_ptr<T> mptr {nullptr};
};
} // namespace IMG

#endif // IMAGEREAD_HPP_
