#include "Vector.h"

template <class T>
Vector<T>::Vector(int s,T t){
    size = s;
    data = new int [size];
    for(int i=0;i<size;i++){
        data[i]=t;
    }
}
template <class T>
Vector<T>::~Vector() {
    delete [] data;
    data = nullptr;
}
template <class T>
Vector<T>::Vector(const Vector &a) {
    size = a.size;
    data = new int[size];
    for(int i=0;i<size;i++){
        data[i]=a.data[i];
    }
}
template <class T>
Vector<T> &Vector<T>::operator=(const Vector &a) {
    size=a.size;
    if(data != nullptr) delete[] data;
    data = new int[size];
    for(int i=0;i<size;i++){
        data[i] = a.data[i];
    }
    return *this;
}
template <class T>
T &Vector<T>::operator[](int index) {
    if(index<size) return data[index];
    else std::cout<<"Error. Out of bounds!"<<std::endl;
}
template <class T>
int Vector<T>::operator()() {return size;}

template <class T>
Vector<T> Vector<T>::operator+(const T k) {
    Vector tmp(size);
    for(int i=0;i<size;i++){
        tmp.data[i]+=data[i]+k;
    }
    return tmp;
}
template <class T>
std::ostream& operator<<(std::ostream& out,const Vector<T>& a){
    for(int i=0;i<a.size;i++){
        out<<a.data[i]<<" ";
    }
    return out;
}

template <class T>
std::istream& operator>>(std::istream& in,Vector<T>& a){
    for(int i=0;i<a.size;i++){
        in>>a.data[i];
    }
    return in;
}
