#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a,b,c,result;
    cout << "Введите коэффициенты для квадратного уравнения" << endl;
    cin >> a >> b >> c;
    double D = b * b - 4 * a * c;
    if(D < 0){
        cout << "Нет действительных корней" << endl;
        cout << "Комплексные корни уравнения: "<<-b/(2*a) << "+" << sqrt(-D)/(2*a)<<"i и "<<-b/(2*a) << "-" << sqrt(-D)/(2*a)<<"i"<<endl;
    }
    else{
        if(D==0){
            cout << "Действительные корни совпадают" << endl;
            cout << "Корень уравнения: "<<-b/(2*a)<<endl;
        }
        else{
            cout << "Два действительных корня" << endl;
            cout << "Корни уравнения: "<<-b/(2*a)+sqrt(D)/(2*a)<<" и "<<-b/(2*a)-sqrt(D)/(2*a)<<endl;
        }
    }
    return 0;
}

