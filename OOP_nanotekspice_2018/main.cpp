/*
** EPITECH PROJECT, 2019
** main.hpp
** File description:
** main class
*/

#include "Errors.hpp"
#include "Parser.hpp"
#include "Shell.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "No file selected." << std::endl;
        return 84;
    }
    Parser p(av[1]);
    crc::Circuit c;
    Shell shell;

    if (!(c = p.parseFile(ac, av)).isReady())
        return (84);
    shell.run(c);
    return 0;
}
