/*
** EPITECH PROJECT, 2019
** Federation.hpp
** File description:
** fed header
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

#include <string>
#include <iostream>
#include "Destination.hpp"

namespace WarpSystem {
    class QuantumReactor {
    public:
        // Ctor / Dtor
        QuantumReactor();
        ~QuantumReactor();

        // Member method
        bool isStable();
        void setStability(bool stability);
    private:
        // Attributes
        bool _stability;
    };
    class Core {
    public:
        // Ctor / Dtor
        Core(QuantumReactor *coreReactor);
        ~Core();

        //Member method
        QuantumReactor *checkReactor();
    private:
        QuantumReactor *_coreReactor;
    };
};

#endif /* !WARPSYSTEM_HPP_ */
