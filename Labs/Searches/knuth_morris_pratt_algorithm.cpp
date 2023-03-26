#include <iostream>
using namespace std;

int* Prefix_function(string substr, int size){
    int* lps = new int[size];
    int len = 0,i=1;
    lps[0] = 0;
    while( i < size){
        if(substr[i] == substr[len]){
            lps[i] = len;
            len++;
            i++;
        }
        else{
            if(len!=0) len=lps[len-1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void Knuth_Morris_Pratt_algorithm(string substr,string string){
    int substr_size = (int)substr.length();
    int str_size = (int)string.length();
    int* lps = Prefix_function(substr, substr_size);
    int substr_ind, str_ind = substr_ind = 0;
    while((str_size - str_ind) >= (substr_size - substr_ind)){
        if(substr[substr_ind] == string[str_ind]){
            substr_ind++;
            str_ind++;
        }
        if(substr_ind == substr_size){
            cout<<"Substring was found at index "<<str_ind-substr_ind<<endl;
            substr_ind = lps[substr_ind-1];
        }
        else if(str_ind<str_size && substr[substr_ind]!=string[str_ind]){
            if (substr_ind!=0) substr_ind = lps[substr_ind-1];
            else str_ind = str_ind+1;
        }
    }
}

int main(){
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    Knuth_Morris_Pratt_algorithm(pat, txt);
    return 0;
}