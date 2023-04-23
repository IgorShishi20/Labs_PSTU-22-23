
#ifndef MAIN_CPP_EVENT_H
#define MAIN_CPP_EVENT_H

const int EvNothing = 0;
const int EvMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmShowAll =5;
const int cmMake =6;
const int cmQuit = 101;

struct TEvent{
    int what;
    union {
        int command;
        struct {
            int message;
            //what is 'a' ?
            int param;
        };
    };
};

#endif //MAIN_CPP_EVENT_H
