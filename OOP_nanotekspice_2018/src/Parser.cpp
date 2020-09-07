/*
** EPITECH PROJECT, 2019
** Parser.hpp
** File description:
** Parser class
*/

#include "Parser.hpp"
#include "Circuit.hpp"

// Ctor / Dtor

Parser::Parser(const std::string &filename) : _filename(filename) {}

// Member methods

crc::Circuit Parser::parseFile(int ac, char **av)
{
    std::ifstream myFile;
    crc::Circuit circuit;

    myFile.open(_filename);
    if (!myFile.is_open()) {
        err::Errors::displayError("Can't open file");
        return circuit;
    }
    if (!searchForComponents(myFile, circuit))
        return circuit;
    myFile.close();
    for (int i = 2; i < ac; i++)
        if (!parseParameters(av[i], circuit))
            return circuit;
    circuit.setReady();
    return circuit;
}

/*
 * search for all components inside the file.
 * if there is no .chipset header, the function returns
 * false.
 */

bool Parser::searchForComponents(std::ifstream &myFile, crc::Circuit &circuit)
{
    std::string line;
    bool toParse = false;

    while (std::getline(myFile, line) &&
    parseComments(cutSpaces(line)) != ".links:") {
        if (line == std::string(".chipsets:"))
            toParse = true;
        if (toParse && line != std::string(".chipsets:")) {
            line = parseComments(line);
            std::string::iterator new_end = std::unique(line.begin(), line.end(), deleteSpaces);
            line.erase(new_end, line.end());
            if (!addChipset(line, circuit))
                return false;
        }
    }
    if (line != ".links:" || !toParse)
        return false;
    while (std::getline(myFile, line)) {
        line = parseComments(line);
        std::string::iterator new_end = std::unique(line.begin(), line.end(), deleteSpaces);
        line.erase(new_end, line.end());
        if (!addLink(line, circuit))
            return false;
    }
    return circuit.checkOutputs();
}

std::string Parser::parseComments(std::string line)
{
    return line.find('#') != std::string::npos ? line.substr(0, line.find('#')) : line;
}

std::string Parser::cutSpaces(std::string line)
{
    line.erase(std::remove_if(line.begin(), line.end(), isblank), line.end());
    return line;
}

bool Parser::addChipset(std::string &line, crc::Circuit &circuit)
{
    std::istringstream iss(line);
    std::vector<std::string> words((std::istream_iterator<std::string>(iss)),
                                   std::istream_iterator<std::string>());

    if (line.empty())
        return true;
    if (words.size() <= 1 || words.size() > 2) {
        if (words.size() <= 1)
            std::cerr << "Error: " << words.at(0) << " is undefined." << std::endl;
        else
            std::cerr << "Error: " << words.at(0) << " has to much arguments." << std::endl;
        return false;
    }
    return circuit.createComponent(words.at(0), words.at(1));
}

bool Parser::addLink(std::string &line, crc::Circuit &circuit)
{
    std::istringstream iss(line);
    std::vector<std::string> words((std::istream_iterator<std::string>(iss)),
                                   std::istream_iterator<std::string>());

    if (line.empty())
        return true;
    if (words.size() <= 1 || words.size() > 2) {
        if (words.size() <= 1)
            std::cerr << "Error: " << words.at(0) << " isn't linked to anything." << std::endl;
        else
            std::cerr << "Error: " << words.at(0) << " has to much arguments." << std::endl;
        return false;
    }
    if (words.at(0).find(':') == std::string::npos || words.at(1).find(':') == std::string::npos) {
        if (words.at(0).find(':') == std::string::npos)
            std::cerr << "Error: " << words.at(0) << " has no pin to link." << std::endl;
        else if (words.at(1).find(':') == std::string::npos)
            std::cerr << "Error: " << words.at(1) << " has no pin to link." << std::endl;
        return false;
    }
    std::string pin1 = words.at(0).substr(words.at(0).find(':') + 1, words.at(0).at(words.at(0).size() - 1));
    std::string pin2 = words.at(1).substr(words.at(1).find(':') + 1, words.at(1).at(words.at(1).size() - 1));
    std::string sub1 = words.at(0).substr(0, words.at(0).find(':'));
    std::string sub2 = words.at(1).substr(0, words.at(1).find(':'));
    if (!isNumber(pin1) || !isNumber(pin2)) {
        if (!isNumber(pin1))
            std::cerr << "Error: " << sub1 << "'s pin is invalid" << std::endl;
        else if (!isNumber(pin2))
            std::cerr << "Error: " << sub2 << "'s pin is invalid" << std::endl;
        return false;
    }
    return setNewLink(sub1, sub2, pin1, pin2, circuit);
}

bool Parser::setNewLink(std::string &c1, std::string &c2,
        std::string &p1, std::string &p2, crc::Circuit &circuit)
{
    std::size_t pi1 = 0;
    std::size_t pi2 = 0;
    std::istringstream iss1 (p1);
    std::istringstream iss2 (p2);

    iss1 >> pi1;
    iss2 >> pi2;
    if (!circuit.findComponent(c1) || !circuit.findComponent(c2)) {
        if (!circuit.findComponent(c1))
            std::cerr << "Error:" << c1 << " doesn't exist." << std::endl;
        else if (!circuit.findComponent(c2))
            std::cerr << "Error:" << c2 << " doesn't exist." << std::endl;
        return false;
    }
    circuit.setNewLink(c1, pi1, c2, pi2);
    circuit.setNewLink(c2, pi2, c1, pi1);
    return true;
}

bool Parser::isNumber(const std::string &s)
{
    return !s.empty() && std::find_if(s.begin(),
            s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

bool Parser::parseParameters(char *av, crc::Circuit &circuit)
{
    std::string cpy = av;
    std::size_t p = 0;

    if (cpy.find('=') == cpy.npos) {
        std::cerr << "Error: " << av << " is an invalid argument." << std::endl;
        return false;
    }
    if (!isNumber(cpy.substr(cpy.find('=') + 1, cpy.size() - 1))) {
        std::cerr << "Error: " << cpy.substr(0, cpy.find('=')) << " value must be 0 or 1." << std::endl;
        return false;
    }
    std::istringstream iss(cpy.substr(cpy.find('=') + 1, cpy.size() - 1));
    iss >> p;
    if (p != 0 && p != 1) {
        std::cerr << "Error: " << cpy.substr(0, cpy.find('=')) << " value must be 0 or 1." << std::endl;
        return false;
    }
    return circuit.setInput(cpy.substr(0, cpy.find('=')), p);
}