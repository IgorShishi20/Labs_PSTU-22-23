#include "custom_time.h"
#include "custom_vector_stack.h"

using namespace std;
int main(){
    custom_vector_stack<custom_time> v(3);
    v.Print();
    custom_time t = v.max();
    cout<<"Maximum is "<<t<<endl;
    cout<<"Add maximum "<<endl;
    cout<<"on which position?"<<endl;
    int pos;
    cin>>pos;
    v.add_elem(t,pos);
    v.Print();
    cout<<"Minimum is "<<v.min_pos()<<"th element"<<endl;
    cout<<"Delete mimimum "<<endl;
    v.delete_elem();
    v.Print();
    cout<<"Sum with average value"<<endl;
    t = v.average();
    cout<<"Average is "<<t<<endl;
    v.add_value();
    v.Print();
    return 0;
}