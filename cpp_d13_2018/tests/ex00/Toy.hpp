/*
** EPITECH PROJECT, 2019
** Toy.hpp
** File description:
** toy header
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy
{
public:
    enum ToyType {BASIC_TOY, ALIEN};

    Toy();
    Toy(ToyType, const std::string &, const std::string &);

    std::string getName() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &file);
    std::string getAscii() const;
    ToyType getType() const;

private:
    const ToyType _type;
    std::string _name;
    Picture _picture;
};


#endif /* !TOY_HPP_ */
