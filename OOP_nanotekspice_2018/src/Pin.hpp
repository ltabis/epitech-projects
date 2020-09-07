/*
** EPITECH PROJECT, 2019
** Pin.hpp
** File description:
** Pin class
*/

#ifndef Pin_HPP
#define Pin_HPP

#include "IComponent.hpp"

namespace nts {

    enum Type {INPUT, OUTPUT};

    class Pin {
    public:
        // Ctor / Dtor
        Pin(std::string, Type);
        ~Pin() = default;

        std::unordered_map<std::size_t, std::size_t> getLink();
        std::unordered_map<std::size_t, nts::IComponent &> getRef();
        std::string getName() const {return _name;}
        Tristate getStatus() const {return _state;}
        Type getType() const {return _type;}
        void setState(Tristate status) {_state = status;}

        void setLink(std::size_t, std::size_t);
        void setRef(std::size_t, nts::IComponent &);
    private:
        std::unordered_map<std::size_t, std::size_t> _link;
        std::unordered_map<std::size_t, nts::IComponent &> _ref;
        Tristate _state;
        Type _type;
        std::string _name;
    };
}

#endif /* !Pin_HPP */
