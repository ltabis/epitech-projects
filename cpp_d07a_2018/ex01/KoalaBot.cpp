/*
** EPITECH PROJECT, 2019
** Skat.cpp
** File description:
** skat
*/

#include "KoalaBot.hpp"

// Ctor
KoalaBot::KoalaBot(const std::string &serial) : _serial(serial) {}
KoalaBot::KoalaBot() : KoalaBot("Bob-01") {}

// Dtor
KoalaBot::~KoalaBot() {}

void KoalaBot::setParts(const Arms &arms)
{
    this->_arms = arms;
}
void KoalaBot::setParts(const Legs &legs)
{
    this->_legs = legs;
}
void KoalaBot::setParts(const Head &head)
{
    this->_head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    arms = this->_arms;
}
void KoalaBot::swapParts(Legs &legs)
{
    legs = this->_legs;
}
void KoalaBot::swapParts(Head &head)
{
    head = this->_head;
}
