/*
** EPITECH PROJECT, 2019
** Skat.hpp
** File description:
** Skat header
*/

#ifndef PARTS_HPP
#define PARTS_HPP

#include <string>
#include <iostream>

class Arms
{
public:
    // Gtor / Dtor
    Arms();
    Arms(const std::string &serial, bool functional);
    ~Arms();

    // Member methods
    bool isFunctionnal() const;
    std::string serial() const;
    void informations() const;

private:
    std::string _serial;
    bool _isFunctional;
};

class Legs
{
public:
    // Gtor / Dtor
    Legs();
    Legs(const std::string &serial, bool functional);
    ~Legs();

    // Member methods
    bool isFunctionnal() const;
    std::string serial() const;
    void informations() const;

private:
    std::string _serial;
    bool _isFunctional;
};

class Head
{
public:
    // Gtor / Dtor
    Head();
    Head(const std::string &serial, bool functional);
    ~Head();

    // Member methods
    bool isFunctionnal() const;
    std::string serial() const;
    void informations() const;

private:
    std::string _serial;
    bool _isFunctional;
};

#endif /* !PARTS_HPP */
