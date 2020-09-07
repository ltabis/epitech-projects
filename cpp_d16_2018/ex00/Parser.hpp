/*
** EPITECH PROJECT, 2019
** Parser.hpp
** File description:
** Parser class
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <stack>
#include <iostream>
#include <algorithm>

class Parser
{
public:
    // Ctor / Dtor
    Parser();
    ~Parser();

    void feed(const std::string &);
    int result() const;
    void reset();
    std::string getLastExpression(std::string);
    void computeOperations();
    void reconstruct();
    int selectOperator(int);
    void checkOrder(std::string);

private:
    int _result;

    std::stack<int> _operands;
    std::stack<char> _operators;
};


#endif /* !PARSER_HPP */
