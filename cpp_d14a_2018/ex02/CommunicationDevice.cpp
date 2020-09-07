
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
    : _api(input, output)
{
    try {
        CommunicationAPI(input, output);
    } catch (const std::exception &exept) {
        std::cerr << "Error: " << exept.what() << std::endl;
    }

}

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
    for (size_t i = 0; i < nbUsers; ++i)
        _api.addUser(users[i]);
    try {
        _api.startMission(missionName);
    } catch (std::logic_error &exept)  {
        std::cerr << "LogicError: " << exept.what() << std::endl;
    } catch (std::runtime_error &exept) {
        std::cerr << "RuntimeError: " << exept.what() << std::endl;
    } catch (std::exception &exept) {
        std::cerr << "Error: " << exept.what() << std::endl;
    }
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    try {
    _api.sendMessage(user, message);
    } catch (const std::exception &exept) {
        std::cerr << exept.what() << std::endl;
    }
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
    try {
        _api.receiveMessage(user, message);
    } catch (const std::exception &exept) {
        message = "INVALID MESSAGE";
        std::cerr << exept.what() << std::endl;
    }
}
