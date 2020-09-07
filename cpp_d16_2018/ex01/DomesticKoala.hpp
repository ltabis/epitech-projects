/*
** EPITECH PROJECT, 2019
** DomesticKoala.hpp
** File description:
** DomesticKoala header
*/

#ifndef DOMESTICKOALA_HPP
#define DOMESTICKOALA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "KoalaAction.hpp"

class DomesticKoala
{
public:
    using methodPointer_t = void (KoalaAction::*)(const std::string &);

    DomesticKoala() = delete;
    explicit DomesticKoala(KoalaAction &);
    ~DomesticKoala();
    DomesticKoala(const DomesticKoala &) = default;

    DomesticKoala &operator=(const DomesticKoala &);
    const std::vector<methodPointer_t> *getActions() const
    {
        return &_actions;
    }
    void learnAction(unsigned char command, methodPointer_t action);
    void unlearnAction(unsigned char command);
    void doAction(unsigned char command, const std::string &param);
    void setKoalaAction(KoalaAction  &);

private:
    std::vector<methodPointer_t> _actions;
    std::vector<unsigned char> _commands;
    KoalaAction _kActions;
};

#endif /* !DOMESTICKOALA_HPP */
