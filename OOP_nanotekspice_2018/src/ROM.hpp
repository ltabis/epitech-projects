/*
** EPITECH PROJECT, 2019
** ROM.hpp
** File description:
** ROM class
*/

#ifndef ROM_HPP
#define ROM_HPP

#include "CompProperties.hpp"

namespace nts {
    class ROM : public CompProperties {
    public:
        void dump() const final;

    };
}


#endif /* !ROM_HPP */
