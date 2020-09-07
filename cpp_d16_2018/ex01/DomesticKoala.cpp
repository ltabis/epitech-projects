/*
** EPITECH PROJECT, 2019
** DomesticKoala.cpp
** File description:
** DomesticKoala methods
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &act) : _kActions(act) {}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &dom)
{
    _commands = dom._commands;
    _actions = dom._actions;
    _kActions = dom._kActions;
    return *this;
}

DomesticKoala::~DomesticKoala() {}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    _actions.push_back(action);
    _commands.push_back(command);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    for (unsigned int idx = 0; idx < _commands.size(); idx++) {
        if (command == _commands.at(idx)) {
            _actions.erase(_actions.begin() + idx);
            _commands.erase(_commands.begin() + idx);
        }
    }
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    for (unsigned int idx = 0; idx < _commands.size(); idx++) {
        if (command == _commands.at(idx)) {
            void (KoalaAction::*func)(const std::string &) = _actions.at(idx);
            (_kActions.*func)(param);
        }
    }
}

void DomesticKoala::setKoalaAction(KoalaAction &actions)
{
    _kActions = actions;
}