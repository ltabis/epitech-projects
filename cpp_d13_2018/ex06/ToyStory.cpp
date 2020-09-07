/*
** EPITECH PROJECT, 2019
** ToyStory.cpp
** File description:
** ToyStory methods
*/

#include "ToyStory.hpp"

void ToyStory::tellMeAStory(const std::string &file, Toy &toy1,
                  bool (Toy::*func1)(const std::string &),
                  Toy &toy2,
                  bool (Toy::*func2)(const std::string &))
{
    std::string newFile = "";
    std::string line = "";
    std::ifstream myfile;
    std::ofstream outfile;
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;

    myfile.open(file);
    if (myfile.is_open()) {
        for (unsigned int i = 0; std::getline(myfile, line); i++) {
            newFile += (line + "\n");
            checkToyToUse(toy1, toy2, line, i, func1, func2, newFile);
        }
        myfile.close();
        outfile.open(file);
        if (outfile.is_open()) {
            outfile << newFile;
            outfile.close();
        }
    } else
        std::cerr << "Error, can't open " << file << std::endl;
}

void ToyStory::checkToyToUse(Toy &toy1, Toy &toy2,
                             std::string &line, unsigned int i,
                             bool (Toy::*func1)(const std::string &),
                             bool (Toy::*func2)(const std::string &),
                             std::string &newFile)
{
    if (i % 2 == 0) {
        if (!changePicture(line, toy1, newFile))
            (toy1.*func1)(line);
    } else if (i % 2 != 0) {
        if (!changePicture(line, toy2, newFile))
            (toy2.*func2)(line);
    }
}

bool ToyStory::changePicture(const std::string &line, Toy &toy,
                             std::string &newFile) {
    std::string str = line.substr(0, 8);

    if (str == "picture:") {
        toy.setAscii(line.substr(8, line.size()));
        newFile += toy.getAscii() + "\n";
        return true;
    }
    return false;
}