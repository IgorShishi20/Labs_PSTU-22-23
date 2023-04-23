
#ifndef MAIN_CPP_DIALOG_H
#define MAIN_CPP_DIALOG_H
#include "Vector.h"
#include "Event.h"

class Dialog:public Vector{
protected:
    int EndState;
public:
    Dialog();
    ~Dialog(){};
    virtual void GetEvent(TEvent& event);
    virtual void HandleEvent(TEvent& event);
    virtual void ClearEvent(TEvent& event);
    virtual int Execute();
    int Valid();
    void EndExec();
};

#endif //MAIN_CPP_DIALOG_H
