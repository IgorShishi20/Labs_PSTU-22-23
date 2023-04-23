
#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H
#include "Event.h"

class Object{
public:
    Object(void);
    ~Object();
    virtual void Show()= 0;
    virtual void Input()= 0;
    virtual void HandleEvent(const TEvent& event)= 0;
};

#endif //MAIN_CPP_OBJECT_H
