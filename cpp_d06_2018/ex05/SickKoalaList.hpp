/*
** EPITECH PROJECT, 2019
** SickKoalaList.hpp
** File description:
** sick list
*/

#ifndef SICKKOALALIST_H_
#define SICKKOALALIST_H_

#include "SickKoala.hpp"

class SickKoalaList {
public:
    // Init
    SickKoalaList(SickKoala *);
    ~SickKoalaList();

    // Member methods
    bool isEnd();
    void append(SickKoalaList *node);
    SickKoalaList *getFromName(std::string s);
    SickKoalaList *remove(SickKoalaList *node);
    SickKoalaList *removeFromName(std::string s);
    SickKoalaList *getContent();
    SickKoalaList *getNext();
    void dump();
private:
    SickKoala *_itr;
    SickKoalaList *_next;
};

#endif /* !SICKKOALALIST_H_ */
