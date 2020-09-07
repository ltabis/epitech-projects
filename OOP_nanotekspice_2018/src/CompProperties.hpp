/*
** EPITECH PROJECT, 2019
** CompProperties.hpp
** File description:
** CompProperties class
*/

#ifndef CompProperties_HPP
#define CompProperties_HPP

#include "IComponent.hpp"
#include "Pin.hpp"

class CompProperties : public nts::IComponent {
public:
    explicit CompProperties(const std::string &name);

    virtual nts::Tristate compute(std::size_t pin);
    void setLink(std::size_t, nts::IComponent &, std::size_t) final;
    virtual void dump() const;
    std::string getName() const {return _name;}
    std::string getType() const final {return _type;}
    bool getPin(std::size_t pin) const {return _pins.find(pin) == _pins.end();}

protected:
    std::map<std::size_t, nts::Pin> _pins;
    std::string _name;
    std::string _type;
};

#endif /* !CompProperties_HPP */
