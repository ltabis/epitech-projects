/*
** EPITECH PROJECT, 2019
** .cpp
** File description:
** file
*/

#include "KreogCom.hpp"

// Ctor
KreogCom::KreogCom(const int x, const int y, const int serial) : _x(x), _y(y), m_serial(serial), _com(NULL)
{
    std::cout << "KreogCom " << this->m_serial << " initialized" << std::endl;
}

// Dtor
KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

// Member methods
void KreogCom::addCom(const int x, const int y, const int serial)
{
    KreogCom *tmp = NULL;
    KreogCom *tmp2 = NULL;

    if (this->_com) {
        tmp = this->_com;
        this->_com = new KreogCom(x, y, serial);
        tmp2 = this->_com;
        tmp2->_com = tmp;
    } else
        this->_com = new KreogCom(x, y, serial);
}

KreogCom *KreogCom::getCom() const
{
    return (this->_com);
}

void KreogCom::removeCom()
{
    KreogCom *tmp = NULL;

    if (this->_com) {
        tmp = this->_com->getCom();
        delete this->_com;
        if (tmp) {
            this->_com = tmp;
        } else {
            this->_com = NULL;
        }
    }
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial <<
    " currently at " << this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *tmp = this->_com;

    for (; tmp && tmp->_com; tmp = tmp->_com)
        tmp->ping();
    tmp->ping();
    this->ping();
}
