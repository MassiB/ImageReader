/**
 * @file ImageFactory.hpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef IMAGEFACTORY_HPP_
#define IMAGEFACTORY_HPP_
/// @headerfile Internal headers
#include "IReader.hpp"
#include "ImageType.hpp"
/// @headerfile System headers 
#include <memory>

/// @brief 
namespace IMG
{
/// @brief 
class ImageFactory final
{
public:
    /// @brief 
    /// @param type 
    /// @return 
    static auto create(IMG_TYPE type) -> std::unique_ptr<IReader>;
    /// @brief 
    ImageFactory() = delete;
    ImageFactory(ImageFactory &&) = delete;
    ImageFactory(const ImageFactory &) = delete;
    auto operator=(const ImageFactory &) -> ImageFactory& = delete;
    auto operator=(ImageFactory &&) -> ImageFactory& = delete;
};
} // namespace IMG

#endif // IMAGEFACTORY_HPP_
