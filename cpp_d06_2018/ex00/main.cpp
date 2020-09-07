/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main function
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char *av[])
{
    std::string line;

    if (ac <= 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return 84;
    }
    for (auto i = 1; i < ac; i++) {
        std::ifstream myfile;
        myfile.open(av[i]);
        if (myfile.is_open()) {
            while(std::getline(myfile, line))
                std::cout << line << std::endl;
            myfile.close();
        } else
            std::cerr << "my_cat: "<< av[i] <<
            ": No such file or directory" << std::endl;
    }
    return 0;
}
