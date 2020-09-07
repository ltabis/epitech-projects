/*
** EPITECH PROJECT, 2019
** SickKoala.cpp
** File description:
** main file
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id) : _id(id), _isWorking(0) {}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->_id <<
    ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string Drug, SickKoala *koala)
{
    if (!koala)
        return;
    koala->takeDrug(Drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::string str;
    std::ifstream myfile;
    std::string::size_type pos = 0;

    pos = filename.find(".report");
    if (pos == std::string::npos)
        return (str);
    myfile.open(filename);
    if (!(myfile.is_open()) ||
    myfile.peek() == std::ifstream::traits_type::eof())
        return (str);
    std::getline(myfile, str);
    std::cout << "Nurse " << this->_id <<
    ": Kreog! Mr."<< filename.substr(0, pos) <<
    " needs a " << str << "!" << std::endl;
    return (str);
}

void KoalaNurse::timeCheck()
{
    if (this->_isWorking == 0) {
        this->_isWorking = 1;
        std::cout << "Nurse " << this->_id <<
        ": Time to get to work!" << std::endl;
    } else {
        this->_isWorking = 0;
        std::cout << "Nurse " << this->_id <<
        ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}
