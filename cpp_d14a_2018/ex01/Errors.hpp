/*
** EPITECH PROJECT, 2019
** Errors.hpp
** File description:
** Errors class
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
    public:
    explicit NasaError(std::string const &,
                std::string const & = "Unknown");

        virtual std::string const &getComponent() const;
        virtual const char *what() const noexcept;

protected:
        std::string _message;
        std::string _name;
};

class MissionCriticalError : public NasaError
{
    public:
        explicit MissionCriticalError(std::string const &,
                std::string const & = "Unknown");
};

class LifeCriticalError : public NasaError
{
    public:
    explicit LifeCriticalError(std::string const &,
                std::string const & = "Unknown");
};

class UserError : public NasaError
{
    public:
    explicit UserError(std::string const &,
                std::string const & = "Unknown");
};

class CommunicationError : public NasaError
{
    public:
    explicit CommunicationError(std::string const &);
};

#endif
