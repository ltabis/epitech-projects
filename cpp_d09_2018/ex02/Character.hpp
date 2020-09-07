/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** Character header
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>

class Character
{
public:
    enum AttackRange {CLOSE, RANGE};
    // Ctor / Dtor
    Character(const std::string &name, int level);
    ~Character();

    // Member methods
    bool checkEnergy(const int);
    virtual int CloseAttack();
    void Heal();
    virtual int RangeAttack();
    void RestorePower();
    void TakeDamage(int);

    // Getters
    const std::string &getName() const;
    int getLvl() const;
    int getPv() const;
    int getPower() const;
    int getStrength() const;
    int getStamina() const;
    int getIntelligence() const;
    int getSpirit() const;
    int getAgility() const;
    std::string getRace() const;
    std::string getClass() const;

    // Setters
    void setRace(std::string &);

    AttackRange Range;
private:
    std::string _name;
    int _level;
    int _pv;
    int _pe;
protected:
    std::string _race;
    std::string _class;
    int _strength;
    int _stamina;
    int _intelligence;
    int _spirit;
    int _agility;
};

#endif /* !CHARACTER_HPP_ */
