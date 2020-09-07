/*
** EPITECH PROJECT, 2019
** Skat.cpp
** File description:
** skat
*/

#include "Parts.hpp"

// Ctor
Arms::Arms(const std::string &serial, bool functional) :
_serial(serial), _isFunctional(functional) {}
Legs::Legs(const std::string &serial, bool functional) :
_serial(serial), _isFunctional(functional) {}
Head::Head(const std::string &serial, bool functional) :
_serial(serial), _isFunctional(functional) {}

Arms::Arms() : Arms("A-01", true) {}
Legs::Legs() : Legs("L-01", true) {}
Head::Head() : Head("H-01", true) {}

// Dtor
Arms::~Arms() {}
Legs::~Legs() {}
Head::~Head() {}

// Member methods
bool Arms::isFunctionnal() const { return (this->_isFunctional); }
bool Legs::isFunctionnal() const { return (this->_isFunctional); }
bool Head::isFunctionnal() const { return (this->_isFunctional); }

std::string  Arms::serial() const { return (this->_serial); }
std::string  Legs::serial() const { return (this->_serial); }
std::string  Head::serial() const { return (this->_serial); }

void Arms::informations() const
{
    std::cout << "\t" << "[Parts] Arms " << this->_serial <<
    " status : " << (this->isFunctionnal() ? "OK" : "KO") << std::endl;
}
void Legs::informations() const
{
    std::cout << "\t" << "[Parts] Legs " << this->_serial <<
    " status : " << (this->isFunctionnal() ? "OK" : "KO") << std::endl;
}

void Head::informations() const
{
    std::cout << "\t" << "[Parts] Head " << this->_serial <<
    " status : " << (this->isFunctionnal() ? "OK" : "KO") << std::endl;
}
