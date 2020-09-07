/**
 *  @file     src/modules/ModuleException.hpp
 *  @author   amillot on the 2020-02-09
 *  @date     2020-02-09
 * 
 *  project: zia
 * 
 */

#pragma once

#include "Exception.hpp"

namespace zia::mod {

    /** 
     * @brief A class which inherits from the zia Exception class.
     * This class allows to throw exceptions designed for the modules.
     */
    class ModuleException : public zia::Exception {
    public:
        /** 
         * @brief ModuleException destructor, set by default.
         */
        ~ModuleException() override = default;
       
        /** 
         * @brief ModuleException default constructor, which is deleted.
         */
        ModuleException() noexcept = delete;
       
        /** 
         * @brief ModuleException constructor with std::strings.
         * @param what : The description of the exception.
         * @param where : The optional origin of the exception.
         */
        explicit ModuleException(std::string what, std::string where = "") noexcept;
       
        /** 
         * @brief ModuleException constructor with const C-strings.
         * @param what : The description of the exception.
         * @param where : The optional origin of the exception.
         */
        explicit ModuleException(const char *what, const char *where = "") noexcept;
       
        /** 
         * @brief ModuleException copy constructor, set by default.
         * @param other : The other ModuleException to copy.
         */
        ModuleException(const ModuleException &other) = default;
       
        /** 
         * @brief operator= default overloading.
         * @return ModuleException &
         * @param other : The other ModuleException to copy.
         */
        ModuleException &operator=(const ModuleException &other) = default;

    };

}

