/**
 * @file IReader.hpp
 * @author Massinissa Bandou
 * @brief Image reader abstraction
 * @version 0.1
 * @date 2023-10-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef IREADER_HPP_
#define IREADER_HPP_

// Forward declaration
class vtkAlgorithmOutput;

/// @brief 
namespace IMG 
{
/// @brief 
class IReader 
{
public:
    /// @brief 
    IReader() = default; 
    IReader(const IReader &) = delete; 
    IReader(const IReader &&) = delete;
    auto operator=(const IReader &) -> IReader& = delete;
    auto operator=(const IReader &&) -> IReader& = delete;
    /// @brief 
    virtual ~IReader() = default;
    /// @brief 
    /// @param filepath 
    virtual auto setFileName(const char * filepath) -> void = 0;
    /// @brief 
    virtual auto display() -> void = 0;
    /// @brief 
    /// @return 
    virtual vtkAlgorithmOutput* getOutput() const { return nullptr; }
};
} // namespace IMG

#endif // IREADER_HPP_
