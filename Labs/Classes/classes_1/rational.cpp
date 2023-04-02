#include "rational.h"

void rational::Init(unsigned int f, unsigned int s) {
    first = f;
    second = s;
}

void rational::Read() {
    std::cin >> first;
    std::cin >> second;
}

void rational::ipart() {
    if (!second) {
        std::cout << "Number is not defined properly" << std::endl;
    } else {
        std::cout << first / second << std::endl;
    }
}
