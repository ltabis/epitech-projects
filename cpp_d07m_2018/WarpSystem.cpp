/*
** EPITECH PROJECT, 2019
** Federation.cpp
** File description:
** fed cpp file
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor() : _stability(true) {}
WarpSystem::QuantumReactor::~QuantumReactor() {}
WarpSystem::Core::Core(QuantumReactor *coreReactor) : _coreReactor(coreReactor) {}
WarpSystem::Core::~Core() {}

bool WarpSystem::QuantumReactor::isStable()
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (this->_coreReactor);
}
