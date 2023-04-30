#include "iostream"
#include "cmath"
#include "fstream"

using namespace std;

struct Person{
    string name;
    string surname;
    string middle_name;
    long phone_region_code;
    long phone_number;
    int pass_series;
    int pass_number;
};

int get_int(int min,int max){
    return min+rand()%(max-min);
}

string get_str(int size){
    string str;
    char alpha[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                       'h', 'i', 'j', 'k', 'l', 'm', 'n',
                       'o', 'p', 'q', 'r', 's', 't', 'u',
                       'v', 'w', 'x', 'y', 'z' };
    for(int i=0;i<size;i++){
        str+=alpha[rand()%26];
    }
    return str;
}

void fill_data(int m){
    ofstream f1 = ofstream("./input.txt",ios::app);
    for(int i=0;i<m;i++){
        f1<<get_str(20)<<endl;
        f1<<get_str(20)<<endl;
        f1<<get_str(20)<<endl;
        f1<<get_int(100,1000)<<" "<<get_int(1000000,10000000)<<endl;
        f1<<get_int(1000,10000)<<" "<<get_int(100000,1000000)<<endl;
    }
    f1.close();
}

int hash_code(long k,int m){
    double temp = k * (sqrt(5)-1)/2;
    double intpart;
    double fractpart = modf(temp,&intpart);
    fractpart *= m;
    double tmp2 = modf(fractpart,&intpart);
    return intpart;
}

void read_data(Person* arr,int m){
    ifstream f1(R"(C:\Users\1\CLionProjects\untitled\input.txt)",ios::app);
    for(int i=0;i<m;i++){
        f1>>arr[i].name;
        f1>>arr[i].surname;
        f1>>arr[i].middle_name;
        f1>>arr[i].phone_region_code>>arr[i].phone_number;
        f1>>arr[i].pass_series>>arr[i].pass_number;
    }
    f1.close();
}

void print_data(Person* arr,int m){
    ofstream f2(R"(C:\Users\1\CLionProjects\untitled\output.txt)",ios::app);
    for(int i=0;i<m;i++){
        f2<<"-----------------"<<endl;
        f2<<arr[i].name<<endl;
        f2<<arr[i].surname<<endl;
        f2<<arr[i].middle_name<<endl;
        f2<<arr[i].phone_region_code<<" "<<arr[i].phone_number<<endl;
        f2<<arr[i].pass_series<<" "<<arr[i].pass_number<<endl;
        f2<<"------------------"<<endl;
    }
    f2.close();
}

void hash_function(Person* arr,int m,int &collision_counter){
    auto* data = new Person[m];
    read_data(data,m);

    bool free[m];
    for(int i=0;i<m;i++){
        free[i]=true;
    }
    for(int i=0;i<m;i++){
        bool collision =false;
        int k = hash_code(data[i].phone_number,m);
        if(free[k]){
            arr[k]=data[i];
            free[k]=false;
        }
        else{
            collision_counter++;
            collision=true;

            for(int j=k;j<m;j++){
                if(free[j]){
                    arr[j]=data[i];
                    collision=false;
                    free[j]=false;
                    break;
                }
            }
            for(int j=0;j<k;j++){
                if(free[j] && collision){
                    arr[j]=data[i];
                    collision=false;
                    free[j]=false;
                    break;
                }
            }
            if(collision) cout<<"No place to put into"<<endl;
        }
    }
    print_data(arr,m);
}

int find_elem(Person* arr,int m,long k){
    int possible = hash_code(k,m);
    if(arr[possible].phone_number==k){
        return possible;
    }
    else{
        for(int j=possible;j<m;j++){
            if(arr[j].phone_number==k){
                return j;
            }
        }
        for(int j=0;j<possible;j++){
            if(arr[j].phone_number==k){
                return j;
            }
        }
    }
    return -1;
}

void check(int m){
    auto* arr = new Person[m];
    int collision_counter = 0;
    hash_function(arr,m,collision_counter);
    cout<<"there are "<<collision_counter<<" collisions"<<endl;
    cout<<"element on position "<<find_elem(arr,m,arr[m/3].phone_number)<<endl;
}

int main(){
    //fill_data(120);
    check(120);
    check(90);
    check(75);
    check(40);
    return 0;
}
