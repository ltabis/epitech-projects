/*
** EPITECH PROJECT, 2019
** KreogCom.hpp
** File description:
**
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <string>
#include <iostream>

class  KreogCom
{
public:
    // Gtor / Dtor
    KreogCom(const int x, const int y, const int serial);
    ~KreogCom();

    // Member methods
    void addCom(const int x, const int y, const int serial);
    void removeCom();
    KreogCom *getCom() const;
    void ping() const;
    void locateSquad() const;

private:
    const int _x;
    const int _y;
    const int m_serial;
    KreogCom *_com;
};

#endif /* !KREOGCOM_HPP_ */
