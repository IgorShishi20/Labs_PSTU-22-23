#include <iostream>
#include <fstream>

using namespace std;

void Distribution(string path1,string path2,string main_path){
    ofstream f1(path1,ios::app);
    ofstream f2(path2,ios::app);
    ifstream mainf(main_path,ios::app);
    string tmp,curr;
    int itmp,icurr;
    if(!f1.is_open() || !f2.is_open()) cout<<"There is an error"<<endl;
    else{
        bool firstfile = true;
        mainf>>curr;
        while(!mainf.eof()){
            if(firstfile){
                f1<<curr<<endl;
                tmp=curr;
                mainf>>curr;
                if(mainf.eof()){
                    f1<<"/"<<endl;
                    return;
                }
                f1<<curr<<endl;
                itmp=stoi(tmp);
                icurr= stoi(curr);
                while(itmp<=icurr){
                    if(mainf.eof()){
                        f1<<"/"<<endl;
                        return;
                    }
                    f1<<curr<<endl;
                    tmp=curr;
                    mainf>>curr;
                    itmp=stoi(tmp);
                    icurr= stoi(curr);
                }
                f1<<"/"<<endl;
                firstfile=false;
            }
            else{
                f2<<curr<<endl;
                tmp=curr;
                mainf>>curr;
                if(mainf.eof()){
                    f2<<"/"<<endl;
                    return;
                }
                f2<<curr<<endl;
                itmp=stoi(tmp);
                icurr= stoi(curr);
                while(itmp<=icurr){
                    if(mainf.eof()){
                        f2<<"/"<<endl;
                        return;
                    }
                    f2<<curr<<endl;
                    tmp=curr;
                    mainf>>curr;
                    itmp=stoi(tmp);
                    icurr= stoi(curr);
                }
                f1<<"/"<<endl;
                firstfile=true;
            }
        }
    }
    f1.close();
    f2.close();
    mainf.close();
}

void Merge(string path1,string path2,string mainpath){
    Distribution(path1,path2,mainpath);
    ifstream f1(path1,ios::app);
    ifstream f2(path2,ios::app);
    ofstream mainf(mainpath,ios::app);
    string tmp1,tmp2;
    int itmp1,itmp2;
    if(!f1.is_open() || !f2.is_open()) cout<<"There is an error"<<endl;
    else {
        int i=0,j=0;
        while(!f1.eof()){
            f1 >> tmp1;
            f2 >> tmp2;
            if(tmp2=="") return;
            while(tmp1!="/" || tmp2!="/"){
                if(tmp1=="/"){
                    mainf<<tmp2<<endl;
                    f2>>tmp2;
                }
                else if(tmp2=="/"){
                    mainf<<tmp1<<endl;
                    f1>>tmp1;
                }
                else{
                    itmp1 = stoi(tmp1);
                    itmp2 = stoi(tmp2);
                    if(itmp1<=itmp2){
                        mainf<<tmp1<<endl;
                        f1>>tmp1;
                    }
                    else{
                        mainf<<tmp2<<endl;
                        f2>>tmp2;
                    }
                }
            }
        }
    }
    f1.close();
    f2.close();
    mainf.close();
    Merge(path1,path2,mainpath);
}

void PrintArr(int mas[],string file_path,int size){
    ofstream file_out(file_path,ios::app);
    for(int i=0;i<size;i++){
        file_out<<mas[i]<<" ";
    }
    cout<<endl;
}

void FillArr(int mas[],int N,int min,int max){
    srand(time(NULL));
    for(int i=0;i<N;i++){
        mas[i]=min+rand()%(max-min+1);
    }
}

int main(){
    int N;
    cin>>N;
    int* arr = new int[N];
    FillArr(arr,N,0,1000);
    PrintArr(arr,"./input.txt",N);
    Merge("./output1.txt","./output2.txt","./input.txt");

    return 0;
}