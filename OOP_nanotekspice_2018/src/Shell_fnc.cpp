//
// EPITECH PROJECT, 2019
// Shell_fnc.cpp
// File description:
// Shell_fnc
//

#include "Shell.hpp"

void exit()
{
        exit (84);
}

void display() //display les différentes valeurs des outputs
{
        std::cout << "display" << std::endl;
}

void dump() //active le DUMP de chaque component
{
        std::cout << "dump" << std::endl;
}

void simulate() //réalise 1 simulation
{
        std::cout << "simulate" << std::endl;
}

void loop() //réalise des simulations jusqu'à l'arrêt forcé du programme
{
        std::cout << "loop" << std::endl;
}
