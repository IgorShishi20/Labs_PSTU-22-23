#ifndef MAIN_CPP_TIME_H
#define MAIN_CPP_TIME_H

#include "iostream"

class Time {
    int seconds;
    int minutes;
public:
    Time();

    Time(int, int);

    Time(const Time &t);

    ~Time() {/*cout<<"destruct this time:"<<minutes<<":"<<seconds<<endl;*/};

  //  [[nodiscard]] int get_minutes() const { return minutes; }

  //  [[nodiscard]] int get_seconds() const { return seconds; }

  //  void set_minutes(int m) { minutes = m; }

   // void set_seconds(int s) { seconds = s; }

    Time& operator=(const Time& t);

  //  bool operator==(Time &t) const { return minutes == t.minutes && seconds == t.seconds; };

    Time &operator+(Time &t);

    Time &operator+(int);

  //  void Show() const { std::cout << minutes << ":" << seconds << std::endl; };

    friend std::istream& operator>>(std::istream &in, Time& t);
    friend std::ostream& operator<<(std::ostream &out, Time& t);
};

#endif //MAIN_CPP_TIME_H
