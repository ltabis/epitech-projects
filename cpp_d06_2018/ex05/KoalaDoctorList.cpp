/*
** EPITECH PROJECT, 2019
** SickKoalaList.cpp
** File description:
** sick list
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *koala) :
    _itr(koala), _next(NULL) {}
KoalaDoctorList::~KoalaDoctorList() {}

bool KoalaDoctorList::isEnd()
{
    return (!this->_next ? true : false);
}

void KoalaDoctorList::append(KoalaDoctorList *node)
{
    KoalaDoctorList *tmp = this;

    for (; tmp->_next; tmp = tmp->_next);
    tmp->_next = node;
}

KoalaDoctorList *KoalaDoctorList::getFromName(std::string s)
{
    KoalaDoctorList *tmp = this;

    for (; tmp->_next; tmp = tmp->_next)
        if (tmp->_itr && s.compare(tmp->_itr->getName()) == 0)
            return (tmp);
    return (NULL);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *node)
{
    KoalaDoctorList *tmp = this;
    KoalaDoctorList *last = this;

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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string s)
{
    KoalaDoctorList *tmp = this;
    KoalaDoctorList *last = this;

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

KoalaDoctorList *KoalaDoctorList::getContent()
{
    KoalaDoctorList *ptr = this;

    return (ptr);
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return (this->_next);
}

void KoalaDoctorList::dump()
{
    KoalaDoctorList *tmp = this;

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
