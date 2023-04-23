#include "Time.h"

Time::Time() {
    seconds = 0;
    minutes = 0;
}

Time::Time(int m, int s) {
    seconds = s;
    minutes = m;
}

Time::Time(const Time &t) {
    seconds = t.seconds;
    minutes = t.minutes;
}

Time &Time::operator=(const Time& t){
    minutes = t.minutes;
    seconds = t.seconds;
    return *this;
}

std::istream& operator>>(std::istream &in,Time &t) {
    int a,b;
    in>>t.minutes>>t.seconds;
    return in;
}

std::ostream& operator<<(std::ostream &out,Time &t) {
    std::cout<<t.minutes<<" "<<t.seconds;
    return out;
}

Time &Time::operator+(Time &t) {
    int tmp = (60 * minutes + seconds) + (60 * t.minutes + t.seconds);
    minutes = tmp / 60;
    seconds = tmp % 60;
    return *this;
}
Time &Time::operator+(int c) {
    int tmp = 60 * minutes + seconds + c;
    minutes = tmp / 60;
    seconds = tmp % 60;
    return *this;
}
