#include <iostream>
#include <cmath>
#include <iomanip>
#define eps 0.000001
#define r (std::numbers::e+pow(std::numbers::e,-1))
#define lambda pow(-r,-1)


double f(double x){
    return pow(std::numbers::e,x)-pow(std::numbers::e,-x)-2;
}

double f_first_der(double x){
    return pow(std::numbers::e,x)+pow(std::numbers::e,-x);
}

double f_second_der(double x){
    return pow(std::numbers::e,x)-pow(std::numbers::e,-x);
}

double half(double a,double b){
    while(std::abs(f(a))>eps and std::abs(f(b))>eps){
        double c = (a+b)/2;
        if(f(c)>0)
            b = c;
        else
            a=c;
    }
    if(std::abs(f(a))>eps)
        return b;
    else
        return a;
}

double newton(double a,double b){
    //f(0)*f''(0)=(1-1-2)*(1-1)=0
    //f(1)*f''(1)=(e-e^(-1)-2)*(e-1/e)>0
    double x_i=b,x_pred=a;
    while(std::abs(x_pred-x_i)>eps){
        x_pred = x_i;
        x_i -= f(x_i)/ f_first_der(x_i);
    }
    return x_i;
}

double iterations(double a,double b){
    double x_i=b,x_pred=a;
    while(std::abs(x_i-x_pred)>eps){
        x_pred=x_i;
        x_i += lambda * f(x_i);
    }
    return x_i;
}

int main() {
    std::cout<<"Ðåçóëüòàò ðàáîòû"<<std::endl;
    std::cout<<"Ìåòîä ïîëîâèííîãî äåëåíèÿ: êîðåíü ðàâåí "<<std::setprecision(10)<<half(0,1)<<std::endl;
    std::cout<<"Ìåòîä Íüþòîíà: êîðåíü ðàâåí "<<std::setprecision(10)<<newton(0,1)<<std::endl;
    std::cout<<"Ìåòîä èòåðàöèé: êîðåíü ðàâåí "<<std::setprecision(10)<<iterations(0,1)<<std::endl;
    return 0;
}
