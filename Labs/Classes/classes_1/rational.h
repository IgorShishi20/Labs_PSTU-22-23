//
// Created by 1 on 31.03.2023.
//

#ifndef MAIN_CPP_RATIONAL_H
#define MAIN_CPP_RATIONAL_H

#include "iostream"

class rational {
    unsigned int first;
    unsigned int second;
public:
    void Init(unsigned int f, unsigned int s);

    void Read();

    void Show() { std::cout << "Numerator is " << first << "and denominator is " << " " << second << std::endl; }

    void ipart();
};

#endif //MAIN_CPP_RATIONAL_H
