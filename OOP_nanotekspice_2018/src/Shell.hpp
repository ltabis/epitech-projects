//
// EPITECH PROJECT, 2019
// Shell.hpp
// File description:
// Shell
//

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>
#include <map>
#include <functional>
#include "Circuit.hpp"
#include "Parser.hpp"

class Shell {
public:
    Shell();
    void run(crc::Circuit &);

    void dump(crc::Circuit &);
    void simulate(crc::Circuit &);
    void loop(crc::Circuit &);
    void display(crc::Circuit &);
    bool isFunctionInput(std::string, crc::Circuit &);
private:
    std::map<std::string, std::function<void(crc::Circuit &)>> _func;
};