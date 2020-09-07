/*
** EPITECH PROJECT, 2019
** SickKoalaList.cpp
** File description:
** sick list
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *koala) :
    _itr(koala), _next(NULL) {}
KoalaNurseList::~KoalaNurseList() {}

bool KoalaNurseList::isEnd()
{
    return (!this->_next ? true : false);
}

void KoalaNurseList::append(KoalaNurseList *node)
{
    KoalaNurseList *tmp = this;

    for (; tmp->_next; tmp = tmp->_next);
    tmp->_next = node;
}

KoalaNurseList *KoalaNurseList::getFromID(int s)
{
    KoalaNurseList *tmp = this;

    for (; tmp->_next; tmp = tmp->_next)
        if (tmp->_itr && tmp->_itr->getID() == s)
            return (tmp);
    return (NULL);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *node)
{
    KoalaNurseList *tmp = this;
    KoalaNurseList *last = this;

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

KoalaNurseList *KoalaNurseList::removeFromID(int s)
{
    KoalaNurseList *tmp = this;
    KoalaNurseList *last = this;

    if (tmp->_itr && tmp->_itr->getID() == s) {
        if (!tmp->_next)
            return (NULL);
        else
            return (tmp->_next);
    }
    for (; tmp->_next; tmp = tmp->_next) {
        if (tmp->_itr && tmp->_itr->getID() == s) {
            tmp = tmp->_next;
            last->_next = tmp;
            return (this);
        }
        last = tmp != this && tmp->_next ? last->_next : last;
    }
    if (tmp->_itr && tmp->_itr->getID() == s)
        last->_next = NULL;
    return (this);
}

KoalaNurseList *KoalaNurseList::getContent()
{
    KoalaNurseList *ptr = this;

    return (ptr);
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return (this->_next);
}

void KoalaNurseList::dump()
{
    KoalaNurseList *tmp = this;

    std::cout << "Patients: ";
    for (; tmp->_next; tmp = tmp->_next) {
        if (tmp->_itr)
            std::cout << tmp->_itr->getID() << ", ";
        else
            std::cout << "[NULL], ";
    }
    if (tmp->_itr)
        std::cout << tmp->_itr->getID();
    else
        std::cout << "[NULL]";
    std::cout << std::endl;
}
