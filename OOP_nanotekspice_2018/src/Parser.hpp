/*
** EPITECH PROJECT, 2019
** Parser.hpp
** File description:
** Parser class
*/

#ifndef Parser_HPP
#define Parser_HPP

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include "Errors.hpp"
#include "Circuit.hpp"

class Parser {
public:
    // Ctor / Dtor
    explicit Parser(const std::string &filename);
    ~Parser() = default;

    crc::Circuit parseFile(int, char **);
    bool parseParameters(char *av, crc::Circuit &);
    bool addChipset(std::string &, crc::Circuit &);
    bool addLink(std::string &, crc::Circuit &);
    bool searchForComponents(std::ifstream &, crc::Circuit &);
    std::string parseComments(std::string);
    static std::string cutSpaces(std::string);
    static bool deleteSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }
    static bool isNumber(const std::string &);
    bool setNewLink(std::string &, std::string &,
            std::string &, std::string &, crc::Circuit &);

private:
    const std::string _filename;
};

#endif /* !Parser_HPP */
