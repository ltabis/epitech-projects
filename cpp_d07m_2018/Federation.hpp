/*
** EPITECH PROJECT, 2019
** Federation.hpp
** File description:
** fed header
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include "WarpSystem.hpp"

namespace Federation {
    namespace Starfleet {
        class Captain {
        public:
            // Ctor / Dtor
            Captain(std::string name);
            ~Captain();

            // Member method
            std::string getName();
            int getAge();
            void setAge(int age);
        private:
            std::string _name;
            int _age;
        };
        class Ensign {
        public:
            // Ctor / Dtor
            Ensign(std::string name);
            ~Ensign();
        private:
            std::string _name;
        };
        class Ship {
        public:
            // Ctor / Dtor
            Ship(int length, int width, std::string name, short maxWarp);
            ~Ship();

            // Member method
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            void promote(Captain *captain);
            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
        private:
            // Attributes
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Captain *_captain;
            Destination _home;
            Destination _location;
        };
    };
    class Ship {
    public:
        // Ctor / Dtor
        Ship(int length, int width, std::string name);
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
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Destination _home;
        Destination _location;
    };
};

#endif /* !FEDERATION_HPP_ */
