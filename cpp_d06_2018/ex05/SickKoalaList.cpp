/*
** EPITECH PROJECT, 2019
** SickKoalaList.cpp
** File description:
** sick list
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala) :
    _itr(koala), _next(NULL) {}
SickKoalaList::~SickKoalaList() {}

bool SickKoalaList::isEnd()
{
    return (!this->_next ? true : false);
}

void SickKoalaList::append(SickKoalaList *node)
{
    SickKoalaList *tmp = this;

    for (; tmp->_next; tmp = tmp->_next);
    tmp->_next = node;
}

SickKoalaList *SickKoalaList::getFromName(std::string s)
{
    SickKoalaList *tmp = this;

    for (; tmp->_next; tmp = tmp->_next)
        if (tmp->_itr && s.compare(tmp->_itr->getName()) == 0)
            return (tmp);
    return (NULL);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *node)
{
    SickKoalaList *tmp = this;
    SickKoalaList *last = this;

    if (tmp == node) {
        if (!tmp->_next)
            return (NULL);
        else
            return (tmp->_next);
    }
    for (; tmp->_next; tmp = tmp->_next) {
        if (tmp == node) {
            tmp = tmp->_next ? tmp->_next : NULL;
            last->_next = tmp;
            return (this);
        }
        last = tmp != this && tmp->_next ? last->_next : last;
    }
    if (tmp == node)
        last->_next = NULL;
    return (this);
}

SickKoalaList *SickKoalaList::removeFromName(std::string s)
{
    SickKoalaList *tmp = this;
    SickKoalaList *last = this;

    if (tmp->_itr && s.compare(tmp->_itr->getName()) == 0) {
        if (!tmp->_next)
            return (NULL);
        else
            return (tmp->_next);
    }
    for (; tmp->_next; tmp = tmp->_next) {
        if (tmp->_itr && s.compare(tmp->_itr->getName()) == 0) {
            tmp = tmp->_next;
            last->_next = tmp;
            return (this);
        }
        last = tmp != this && tmp->_next ? last->_next : last;
    }
    if (tmp->_itr && s.compare(tmp->_itr->getName()) == 0)
        last->_next = NULL;
    return (this);
}

SickKoalaList *SickKoalaList::getContent()
{
    SickKoalaList *ptr = this;

    return (ptr);
}

SickKoalaList *SickKoalaList::getNext()
{
    return (this->_next);
}

void SickKoalaList::dump()
{
    SickKoalaList *tmp = this;

    std::cout << "Patients: ";
    for (; tmp->_next; tmp = tmp->_next) {
        if (tmp->_itr)
            std::cout << tmp->_itr->getName() << ", ";
        else
            std::cout << "[NULL], ";
    }
    if (tmp->_itr)
        std::cout << tmp->_itr->getName();
    else
        std::cout << "[NULL]";
    std::cout << std::endl;
}
