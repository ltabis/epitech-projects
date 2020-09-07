/*
** EPITECH PROJECT, 2019
** SickKoalaList.hpp
** File description:
** sick list
*/

#ifndef KOALANURSELIST_H_
#define KOALANURSELIST_H_

#include "KoalaNurse.hpp"

class KoalaNurseList {
public:
    // Init
    KoalaNurseList(KoalaNurse *);
    ~KoalaNurseList();

    // Member methods
    bool isEnd();
    void append(KoalaNurseList *node);
    KoalaNurseList *getFromID(int s);
    KoalaNurseList *remove(KoalaNurseList *node);
    KoalaNurseList *removeFromID(int s);
    KoalaNurseList *getContent();
    KoalaNurseList *getNext();
    void dump();
private:
    KoalaNurse *_itr;
    KoalaNurseList *_next;
};

#endif /* !KOALANURSELIST_H_ */
