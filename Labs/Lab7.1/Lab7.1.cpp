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
    cout<<"Ââåäèòå äâà äåéñòâèòåëüíûõ ÷èñëà"<<endl;
    double a,b;
    cin>>a>>b;
    complex<double>c,d;
    cout<<"Ââåäèòå äâà êîìïëåêñíûõ ÷èñëà â ôîðìàòå (Ra,Ia) (Rb,Ib) áåç ïðîáåëîâ â ñêîáêàõ"<<endl;
    cin>>c>>d;
    cout<<"Ðàçíîñòü äåéñòâèòåëüíûõ ÷èñåë ðàâíà "<<substraction(a,b)<<endl;
    cout<<"Ðàçíîñòü êîìïëåêñíûõ ÷èñåë ðàâíà "<<substraction(c,d)<<endl;
    return 0;
}
