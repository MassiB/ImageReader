/**
 * @file ImageViewer.hpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef IMAGEVIEWER_HPP_
#define IMAGEVIEWER_HPP_
/// @headerfile Internal headers
#include "IReader.hpp"
/// @headerfile System headers
#include <memory>

/// @brief 
namespace IMG
{
class ImageViewer final
{
public:
    /// @brief 
    /// @param image 
    explicit ImageViewer(const IReader &&image);
    /// @brief 
    ~ImageViewer() = default;
    /// @brief 
    /// @return 
    auto render() -> void;
    /// @brief 
    /// @return 
    auto operator()() -> ImageViewer&;
private:
    std::unique_ptr<IReader> imgptr;
};
} // namespace IMG

#endif // IMAGEVIEWER_HPP_
