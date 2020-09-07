/*
** EPITECH PROJECT, 2019
** Parser.cpp
** File description:
** Parser methods
*/

#include <sstream>
#include "Parser.hpp"

Parser::Parser() : _result(0), _operands(), _operators() {}

Parser::~Parser() {}

void Debug(std::stack<int> newOperands, std::stack<char> newOperators)
{
    std::cout << "Operands : ";
    for (; newOperands.size() != 0;) {
        std::cout << newOperands.top() << " ";
        newOperands.pop();
    }
    std::cout << std::endl;
    std::cout << "Operator : ";
    for (; newOperators.size() != 0;) {
        std::cout << newOperators.top() << " ";
        newOperators.pop();
    }
    std::cout << std::endl;
}

void Parser::feed(const std::string &exp)
{
    std::string cpy(exp);
    std::string lastExpression;
    std::string::size_type find = 0;

    cpy.erase(std::remove(cpy.begin(), cpy.end(), ' '), cpy.end());
    while (lastExpression != "X") {
        lastExpression = getLastExpression(cpy);
        find = cpy.find(lastExpression, 0);
        cpy.replace(find, lastExpression.size(), "X");
    }
    reconstruct();
    computeOperations();
}

int Parser::result() const
{
    return _result;
}
void Parser::reset()
{
    _result = 0;
    while (_operands.size() != 0)
        _operands.pop();
    while (_operators.size() != 0)
        _operators.pop();
}

std::string Parser::getLastExpression(std::string cpy)
{
    unsigned long idxS = cpy.find_last_of('(');
    unsigned long idxE = cpy.find_first_of(')', idxS);
    std::string cut;
    std::string cut2;

    if (idxS == std::string::npos || idxE == std::string::npos) {
        idxS = 0;
        idxE = cpy.size() - 1;
        if (cpy == "X")
            return ("X");
    }
    if (idxE == cpy.size() - 1) {
        cut = cpy.substr(idxS, cpy.size());
    } else
        cut = cpy.substr(idxS, idxE - idxS + 1);
    cut2 = cut;
    cut.erase(std::remove(cut.begin(), cut.end(), '('), cut.end());
    cut.erase(std::remove(cut.begin(), cut.end(), ')'), cut.end());
    checkOrder(cut);
    return cut2;
}

void Parser::checkOrder(std::string cut)
{
    int a, b = 0;
    char c, d = 0;

    std::stringstream ss(cut);
    if (cut.find('X') == std::string::npos) {
        ss >> a >> c >> b;
        _operators.push(c);
        _operands.push(a);
        _operands.push(b);
    } else if (cut.find('X') == 0) {
        ss >> d >> c >> b;
        _operators.push(c);
        _operands.push(b);
    } else {
        ss >> b >> c >> d;
        if (c == '-') {
            int n = _operands.top() * -1;
            _operands.pop();
            _operands.push(n);
            _operators.push('+');
            _operands.push(b);
        } else {
            _operators.push(c);
            _operands.push(b);
        }
    }
}

void Parser::computeOperations()
{
    int result = 0;

    for (bool passed = false; _operators.size() != 0; passed = true) {
        if (!passed) {
            result = _operands.top();
            _operands.pop();
        } else
            result = selectOperator(result);
    }
    _result += (result + _operands.top());
}

int Parser::selectOperator(int result)
{
    switch (_operators.top()) {
        case '*': result *= _operands.top();
            break;
        case '/': result /= _operands.top();
            break;
        case '+': result += _operands.top();
            break;
        case '-': result -= _operands.top();
            break;
        case '%': result %= _operands.top();
        default:
            break;
    }
    _operators.pop();
    _operands.pop();
    return result;
}

void Parser::reconstruct()
{
    std::stack<int> newOperands;
    std::stack<char> newOperators;

    for (; _operands.size() != 0;) {
        newOperands.push(_operands.top());
        _operands.pop();
    }
    for (; _operators.size() != 0;) {
        newOperators.push(_operators.top());
        _operators.pop();
    }
    _operands = newOperands;
    _operators = newOperators;
}