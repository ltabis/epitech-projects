
#include <cmath>
#include "Errors.hpp"
#include "Engine.hpp"

#define POW_2(x) (x * x)
#define ABS(x) (x < 0 ? -x : x)

Engine::Engine(float power, float x, float y)
    : _power(power),
      _x(x),
      _y(y)
{
}

Engine::~Engine()
{
}

#include <iostream>

void
Engine::goTorward(float x, float y)
{
    if (_power < distanceTo(x, y)) {
        std::string message = "Cannot reach destination (";
        message = message + std::to_string((int)x);
        message = message + ", ";
        message = message + std::to_string((int)y);
        message = message + ").";
        throw UserError(message.c_str(), "Engine");
    }
    _x = x;
    _y = y;
}

float
Engine::distanceTo(float x, float y) const
{
    return std::sqrt(POW_2(ABS(x - _x)) + POW_2(ABS(y - _y)));
}

float
Engine::getX() const
{
    return _x;
}

float
Engine::getY() const
{
    return _y;
}

