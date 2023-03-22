#include "iostream"
#include <bits/stdc++.h>
#include "string"
using namespace std;

void char_table(string str,int size,int char_table[256]){
    for(int i=0;i<256;i++){
        char_table[i]=-1;
    }
    for(int i=0;i<size;i++){
        char_table[(int)str[i]]=i;
    }
}

int Boyer_moore_search(string str,string substr){
    int s_str = str.size(),s_substr=substr.size();
    int shift_table[256];
    char_table(str,s_substr,shift_table);
    int shift = 0;
    while(shift<=(s_str-s_substr)){
        int j=s_substr-1;
        while(j>=0 && substr[j]==str[shift+j]){
            j--;
        }
        if(j<0){
            cout<<"Pattern found on place "<<shift<<endl;
            if(shift+s_substr<s_str) shift+= s_substr - shift_table[str[shift+s_substr]];
            else shift+=1;
        }
        else shift+=max(1,j-shift_table[str[shift+j]]);
    }
}

int main(){
    string str = "pneumonoultramicroscopicsilicovolcanoconiosis";
    string pattern = "noul";
    Boyer_moore_search(str,pattern);
    return 0;
}
