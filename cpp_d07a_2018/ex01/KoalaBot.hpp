/*
** EPITECH PROJECT, 2019
** Skat.hpp
** File description:
** Skat header
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot
{
    private:
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string _serial;
    public:
        // Gtor / Dtor
        KoalaBot();
        KoalaBot(const std::string &serial);
        ~KoalaBot();

        // Member methods
        void setParts(const Arms &arms);
        void setParts(const Legs &legs);
        void setParts(const Head &head);
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);
        void informations() const {
            std::cout << "[KoalaBot] " << _serial << std::endl;
            _arms.informations();
            _legs.informations();
            _head.informations();
        }
        bool status() const {
            if (!_arms.isFunctionnal() ||
            !_legs.isFunctionnal() ||
            !_head.isFunctionnal())
                return (false);
            return (true);
        }
};
#endif /* !KOALABOT_HPP_ */
