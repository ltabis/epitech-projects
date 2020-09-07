/*
** EPITECH PROJECT, 2019
** Circuit.hpp
** File description:
** Circuit class
*/

#ifndef Circuit_HPP
#define Circuit_HPP

#include <functional>
#include <memory>
#include <map>
#include "IComponent.hpp"
#include "NOR.hpp"
#include "AND.hpp"
#include "input.hpp"
#include "output.hpp"
#include "NAND.hpp"
#include "OR.hpp"
#include "XOR.hpp"
#include "Adder.hpp"
#include "falseC.hpp"
#include "trueC.hpp"
#include "clockC.hpp"
#include "INVERTER.hpp"

namespace crc {
    class Circuit {
    public:
        bool setInput(std::string, std::size_t);
        Circuit();
        bool isReady() {return _isReady;};
        void setReady() {_isReady = true;};
        bool createComponent(const std::string &, const std::string &);
        bool findComponent(std::string &);
        bool setNewLink(std::string &, std::size_t, std::string &, std::size_t);
        bool checkOutputs();
        bool simulate();
        bool display();
        bool dump();

        std::unique_ptr<nts::IComponent> create2076(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4001(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4008(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4011(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4013(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4017(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4030(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4040(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4069(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4071(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4081(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4094(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4503(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4512(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> create4514(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> createi4004(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> createmk4801(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> createFalse(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> createTrue(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> createOutput(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> createInput(const std::string &) const noexcept;
        std::unique_ptr<nts::IComponent> createClock(const std::string &) const noexcept;

    private:
        std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(std::string &)>> _Factory;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _Components;
        bool _isReady;
    };
}

#endif /* !Circuit_HPP */
