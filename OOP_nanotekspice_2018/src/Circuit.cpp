/*
** EPITECH PROJECT, 2019
** Circuit.hpp
** File description:
** Circuit class
*/

#include "Circuit.hpp"
#include "clockC.hpp"

crc::Circuit::Circuit()
{
    _Factory.emplace("2076", [this](std::string &value) {return crc::Circuit::create2076(value);});
    _Factory.emplace("4001", [this](std::string &value) {return crc::Circuit::create4001(value);});
    _Factory.emplace("4008", [this](std::string &value) {return crc::Circuit::create4008(value);});
    _Factory.emplace("4011", [this](std::string &value) {return crc::Circuit::create4011(value);});
    _Factory.emplace("4013", [this](std::string &value) {return crc::Circuit::create4013(value);});
    _Factory.emplace("4017", [this](std::string &value) {return crc::Circuit::create4017(value);});
    _Factory.emplace("4030", [this](std::string &value) {return crc::Circuit::create4030(value);});
    _Factory.emplace("4040", [this](std::string &value) {return crc::Circuit::create4040(value);});
    _Factory.emplace("4069", [this](std::string &value) {return crc::Circuit::create4069(value);});
    _Factory.emplace("4071", [this](std::string &value) {return crc::Circuit::create4071(value);});
    _Factory.emplace("4081", [this](std::string &value) {return crc::Circuit::create4081(value);});
    _Factory.emplace("4094", [this](std::string &value) {return crc::Circuit::create4094(value);});
    _Factory.emplace("4503", [this](std::string &value) {return crc::Circuit::create4503(value);});
    _Factory.emplace("4512", [this](std::string &value) {return crc::Circuit::create4512(value);});
    _Factory.emplace("4514", [this](std::string &value) {return crc::Circuit::create4514(value);});
    _Factory.emplace("i4004", [this](std::string &value) {return crc::Circuit::createi4004(value);});
    _Factory.emplace("mk4801", [this](std::string &value) {return crc::Circuit::createmk4801(value);});
    _Factory.emplace("false", [this](std::string &value) {return crc::Circuit::createFalse(value);});
    _Factory.emplace("true", [this](std::string &value) {return crc::Circuit::createTrue(value);});
    _Factory.emplace("input", [this](std::string &value) {return crc::Circuit::createInput(value);});
    _Factory.emplace("output", [this](std::string &value) {return crc::Circuit::createOutput(value);});
    _Factory.emplace("clock", [this](std::string &value) {return crc::Circuit::createClock(value);});
    _isReady = false;
}

bool crc::Circuit::createComponent(const std::string &type, const std::string &value)
{
    std::string n = value;

    if (_Factory.find(type) == _Factory.end()) {
        std::cerr << "Error: " << n << " is an unknown composant." << std::endl;
        return false;
    }
    if (findComponent(n)) {
        std::cerr << "Error: " << n << " already exists." << std::endl;
        return false;
    }
    _Components.emplace(value, _Factory[type](n));
    return true;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create2076(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4001(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::NOR(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4008(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new Adder(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4011(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::NAND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4013(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}
std::unique_ptr<nts::IComponent> crc::Circuit::create4017(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4030(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::XOR(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4040(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4069(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::INVERTER(value));
    return p;
}
std::unique_ptr<nts::IComponent> crc::Circuit::create4071(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::OR(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4081(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4094(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4503(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4512(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::create4514(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::createi4004(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::createmk4801(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::AND(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::createFalse(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::falseC(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::createTrue(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::trueC(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::createOutput(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::output(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::createInput(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::input(value));
    return p;
}

std::unique_ptr<nts::IComponent> crc::Circuit::createClock(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p(new nts::clockC(value));
    return p;
}

bool crc::Circuit::findComponent(std::string &name)
{
    return _Components.find(name) != _Components.end();
}

bool crc::Circuit::setNewLink(std::string &name, std::size_t pin, std::string &other, std::size_t otherPin)
{
    auto p1 = _Components.at(name).get();
    auto p2 = _Components.at(other).get();

    p1->setLink(pin, *p2, otherPin);
    return true;
}

bool crc::Circuit::simulate()
{
    for (auto const &x : _Components)
        if (x.second->getType() == "output")
            x.second->compute(1);
    return true;
}

bool crc::Circuit::dump()
{
    for (auto const &x : _Components)
        x.second->dump();
    return true;
}

bool crc::Circuit::display()
{
    for (auto const &x : _Components)
        if (x.second->getType() == "output")
            x.second->compute(3);
    return true;
}

bool crc::Circuit::checkOutputs()
{
    for (auto const &x : _Components)
        if (x.second->getType() == "output")
            x.second->compute(2);
    return true;
}

bool crc::Circuit::setInput(std::string name, std::size_t state)
{
    for (auto const &x : _Components)
        if (x.second->getType() == "input" && x.second->getName() == name) {
            x.second->compute(state + 2);
            return true;
        }
    std::cerr << "Error: " << name << " input doesn't exists." << std::endl;
    return false;
}