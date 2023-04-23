#include <string>
#include <iostream>
#include "Dialog.h"

Dialog::Dialog():Vector(0) {
    EndState=0;
}

void Dialog::GetEvent(TEvent &event) {
    std::string possible = "m+-s?/q";
    std::string s;
    std::string param;
    char code;
    std::cout<<'>';
    std::cin>>s;
    code = s[0];
    if(possible.find(code)>=0){
        event.what= EvMessage;
        switch (code) {
            case 'm':event.command=cmMake;break;
            case '+':event.command=cmAdd;break;
            case '-':event.command=cmDel;break;
            case '?':event.command=cmShow;break;
            case 's':event.command=cmShowAll;break;
            case 'q':event.command=cmQuit;break;
            case '/':event.command=cmGet;break;
        }
        if(s.length()>1){
            param=s.substr(1,s.length()-1);
            int tmp = atoi(param.c_str());
            event.param =tmp;
        }
    }
    else event.what=EvNothing;
}

int Dialog::Execute() {
    TEvent event;
    do{
        EndState=0;
        GetEvent(event);
        HandleEvent(event);
    }
    while(!Valid());
    return EndState;
}

int Dialog::Valid() {
    if(EndState) return 1;
    return 0;
}

void Dialog::ClearEvent(TEvent &event) {
    event.what=EvNothing;
}

void Dialog::EndExec() {
    EndState=1;
}

void Dialog::HandleEvent(TEvent &event) {
    if(event.what==EvMessage){
        switch (event.command) {
            case cmMake:
                size=event.param;
                data = new Object * [size];
                curr=0;
                ClearEvent(event);
                break;
            case cmAdd:
                Object*p;
                Add(p);
                ClearEvent(event);
                break;
            case cmDel:
                Del();
                ClearEvent(event);
                break;
            case cmShow:
                Show();
                ClearEvent(event);
                break;
            case cmShowAll:
                Show();
                ClearEvent(event);
                break;
            case cmQuit:
                EndExec();
                ClearEvent(event);
                break;
            default: Vector::HandleEvent(event);//?
        }
    }
}
