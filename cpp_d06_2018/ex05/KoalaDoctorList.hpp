/*
** EPITECH PROJECT, 2019
** SickKoalaList.hpp
** File description:
** sick list
*/

#ifndef SICKKOALALIST_H_
#define SICKKOALALIST_H_

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
public:
    // Init
    KoalaDoctorList(KoalaDoctor *);
    ~KoalaDoctorList();

    // Member methods
    bool isEnd();
    void append(KoalaDoctorList *node);
    KoalaDoctorList *getFromName(std::string s);
    KoalaDoctorList *remove(KoalaDoctorList *node);
    KoalaDoctorList *removeFromName(std::string s);
    KoalaDoctorList *getContent();
    KoalaDoctorList *getNext();
    void dump();
private:
    KoalaDoctor *_itr;
    KoalaDoctorList *_next;
};

#endif /* !SICKKOALALIST_H_ */
