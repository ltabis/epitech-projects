/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef EX05_HPP
#define EX05_HPP

#include <iostream>
#include <exception>

template<typename T>
class array
{
public:
    array(const array &arr)
    {
        _size = arr._size;
        _arr = arr._arr;
    }
    array() : _size(0), _arr(nullptr) {};
    array(unsigned int n)
    {
        _size = n;
        _arr = new T[n];
        for (unsigned int i = 0; i < n; i++)
            _arr[i] = 0;
    }
    array &operator=(const array &arr)
    {
        _arr = arr._arr;
        _size = arr._size;
        return *this;
    }
    T &operator[](int idx)
    {
        if (idx >= size())
            resizeArray(idx + 1);
        return _arr[idx];
    }
    T &operator[](int idx) const
    {
        if (idx >= size())
            throw std::exception();
        return _arr[idx];
    }

    int size() const { return _size; }

    void resizeArray(int idx)
    {
        T *new_array = new T[idx];

        for (int i = 0; i < idx; i++) {
            if (i >= size())
                new_array[i] = 0;
            else
                new_array[i] = _arr[i];
        }
        _size = idx;
        delete _arr;
        _arr = new_array;
    }

    void dump() const
    {
        if (!_arr) {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
        for (int i = 0; i < size(); i++) {
            if (i + 1 < size() && typeid(_arr[i]) != typeid(bool))
                std::cout << _arr[i] << ", ";
            else if (i + 1 < size() && typeid(_arr[i]) == typeid(bool)) {
                std::cout << (_arr[i] ? "true" : "false") << ", ";
            } else if (i + 1 >= size() && typeid(_arr[i]) == typeid(bool)) {
                std::cout << (_arr[i] ? "true" : "false");
            } else
                std::cout << _arr[i];
        }
        std::cout << "]" << std::endl;
    }

    template <typename U, typename G>
    array<U> convertTo(U (*conversion)(G const &))
    {
        array<U> new_array(size());

        for (int i = 0; i < size(); i++)
            new_array[i] = conversion(_arr[i]);
        return new_array;
    }
private:
    int _size;
    T *_arr;
};


#endif /* !EX05_HPP */
