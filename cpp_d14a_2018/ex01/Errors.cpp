/*
** EPITECH PROJECT, 2019
** Errors.cpp
** File description:
** Errors methods
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
        : _message(message), _name(component) {}

MissionCriticalError::MissionCriticalError(std::string const &message,
                                           std::string const &component)
        : NasaError(message, component) {}

LifeCriticalError::LifeCriticalError(std::string const &message,
                                     std::string const &component)
        : NasaError(message, component) {}

UserError::UserError(std::string const &message,
                     std::string const &component)
        : NasaError(message, component) {}

CommunicationError::CommunicationError(std::string const &message)
        : NasaError(message, "CommunicationDevice") {}

std::string const &NasaError::getComponent() const
{
    return _name;
}

const char *NasaError::what() const noexcept
{
    return _message.c_str();
}
