/*
** EPITECH PROJECT, 2019
** Federation.hpp
** File description:
** fed header
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "WarpSystem.hpp"

namespace Borg {
    class Ship {
    public:
        // Ctor / Dtor
        Ship();
        ~Ship();

        // Member method
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
    private:
        // Attributes
        int _side;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _home;
        Destination _location;
    };
};

#endif /* !BORG_HPP_ */
