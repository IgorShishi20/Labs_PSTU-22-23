//
// Created by 1 on 31.03.2023.
//

#ifndef MAIN_CPP_TIME_H
#define MAIN_CPP_TIME_H

#include "iostream"
#include "fstream"

class Time {
    int seconds;
    int minutes;
public:
    Time();

    Time(int m, int s);

    Time(Time &t);

    ~Time() {/*cout<<"destruct this time:"<<minutes<<":"<<seconds<<endl;*/};

    [[nodiscard]] int get_minutes() const { return minutes; }

    [[nodiscard]] int get_seconds() const { return seconds; }

    void set_minutes(int m) { minutes = m; }

    void set_seconds(int s) { seconds = s; }

    Time& operator=(const Time& t);

    friend bool operator==(const Time &tl, const Time &tr) { return tl.minutes == tr.minutes && tl.seconds == tr.seconds; };

    Time &operator+(Time &t);

    void Show() const { std::cout << minutes << ":" << seconds << std::endl; };

    friend std::istream& operator>>(std::istream &in, Time& t);
    friend std::ostream& operator<<(std::ostream &out, Time& t);

    friend bool operator >(const Time &tl,const Time &tr){ return tl.minutes > tr.minutes || tl.minutes == tr.minutes && tl.seconds > tr.seconds;}
    friend bool operator <(const Time &tl,const Time &tr){ return tl.minutes < tr.minutes || tl.minutes == tr.minutes && tl.seconds < tr.seconds;}
    Time operator / (int n);

};

#endif //MAIN_CPP_TIME_H
