/*
** EPITECH PROJECT, 2019
** KoalaDoctor.cpp
** File description:
** doctor object
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : _name(name), _isWorking(0)
{
    std::cout << "Dr." << this->_name <<
    ": I'm Dr." << this->_name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor() {}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::ofstream report;
    std::string drugs[5] = {"mars", "Buronzand",
                            "Viagra", "Extasy",
                            "Eucalyptus leaf"};

    std::cout << "Dr." << this->_name <<
    ": So what's goerking you Mr." << patient->getName() << "?" << std::endl;
    patient->poke();
    report.open(patient->getName() + ".report");
    if (report.bad())
        return;
    report << drugs[random()% 5];
    if (report.bad())
        return;
    report.close();
}

void KoalaDoctor::timeCheck()
{
    if (this->_isWorking == 0) {
        this->_isWorking = 1;
        std::cout << "Dr." << this->_name <<
            ": Time to get to work!" << std::endl;
    } else {
        this->_isWorking = 0;
        std::cout << "Dr." << this->_name <<
        ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}
