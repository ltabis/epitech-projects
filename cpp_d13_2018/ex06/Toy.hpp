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
    enum ToyType {BASIC_TOY, ALIEN, BUZZ, WOODY};

    // Coplien
    Toy();
    Toy(const Toy &);
    virtual ~Toy();
    Toy &operator=(const Toy &);

    Toy(ToyType, const std::string &, const std::string &);

    std::string getName() const;
    Picture getPicture() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &file);
    std::string getAscii() const;
    ToyType getType() const;
    virtual bool speak(const std::string &);
    virtual bool speak_es(const std::string &);
    Toy &operator<<(const std::string &);

    class Error
    {
    public:
        enum ErrorType {UNKNOWN, PICTURE, SPEAK};

        std::string what() const;
        std::string where() const;
        void setErrType(Toy &toy) {type = toy.getErrorType();}
        ErrorType type;
    };

    Error::ErrorType getErrorType() {return _errType;}
    Error getLastError();
protected:
    const ToyType _type;
    std::string _name;
    Picture _picture;
    Error::ErrorType _errType  ;
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);

#endif /* !TOY_HPP_ */
