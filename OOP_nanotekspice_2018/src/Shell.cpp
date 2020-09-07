//
// EPITECH PROJECT, 2019
// shell.cpp
// File description:
// shell
//

#include "Shell.hpp"
#include "Circuit.hpp"

Shell::Shell()
{
    _func.emplace("dump", [this](crc::Circuit &circuit) {dump(circuit);});
    _func.emplace("simulate", [this](crc::Circuit &circuit) {simulate(circuit);});
    _func.emplace("loop", [this](crc::Circuit &circuit) {loop(circuit);});
    _func.emplace("display", [this](crc::Circuit &circuit) {display(circuit);});
}

void Shell::run(crc::Circuit &circuit)
{
    std::string line;

    circuit.simulate();
    std::cout << "> ";
    while (std::getline(std::cin, line) && (line = Parser::cutSpaces(line)) != "exit") {
        if (_func.find(line) == _func.end()) {
            if (!isFunctionInput(line, circuit))
                std::cerr << line << ": Unknown command." << std::endl;
        } else
            _func.at(line)(circuit);
        std::cout << "> ";
    }
}

void Shell::dump(crc::Circuit &circuit)
{
    circuit.dump();
}

void Shell::simulate(crc::Circuit &circuit)
{
    circuit.simulate();
}

void Shell::loop(crc::Circuit &circuit)
{
    circuit.simulate();
}

void Shell::display(crc::Circuit &circuit)
{
    circuit.display();
}

bool Shell::isFunctionInput(std::string line, crc::Circuit &circuit)
{
    std::size_t p = 0;

    if (line.find('=') == line.npos)
        return false;
    if (!Parser::isNumber(line.substr(line.find('=') + 1, line.size() - 1))) {
        std::cerr << "Error: " << line.substr(0, line.find('=')) << " value must be 0 or 1." << std::endl;
        return false;
    }
    std::istringstream iss(line.substr(line.find('=') + 1, line.size() - 1));
    iss >> p;
    if (p != 0 && p != 1) {
        std::cerr << "Error: " << line.substr(0, line.find('=')) << " value must be 0 or 1." << std::endl;
        return false;
    }
    return circuit.setInput(line.substr(0, line.find('=')), p);
}