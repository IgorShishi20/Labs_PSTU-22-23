#include <iostream>
#include <complex>
using namespace std;

double substraction(double a,double b){
    //returns difference of real numbers
    return a-b;
}

complex<double> substraction(complex<double> a, complex<double> b){
    //returns complex number equal to difference a-b (Ra-Rb,Ia-Ib)
    return a-b;
}

int main(){
    cout<<"������� ��� �������������� �����"<<endl;
    double a,b;
    cin>>a>>b;
    complex<double>c,d;
    cout<<"������� ��� ����������� ����� � ������� (Ra,Ia) (Rb,Ib) ��� �������� � �������"<<endl;
    cin>>c>>d;
    cout<<"�������� �������������� ����� ����� "<<substraction(a,b)<<endl;
    cout<<"�������� ����������� ����� ����� "<<substraction(c,d)<<endl;
    return 0;
}