/*
** EPITECH PROJECT, 2019
** AND.hpp
** File description:
** AND class
*/

#ifndef AND_HPP
#define AND_HPP

#include <memory>
#include "CompProperties.hpp"

namespace nts {
    class AND : public CompProperties {

    public:
        explicit AND(std::string);
        nts::Tristate compute(std::size_t);
        void dump() const;
    };
}

#endif /* !AND_HPP */
