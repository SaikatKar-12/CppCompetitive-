#include<iostream>
using namespace std;

int main(){
    string str;
    string s="abdgsjwxgdyeyerygsvxhszuzrzfgvz";
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='x'){
            str.push_back(s[i]);
        }
    }
    for(int i=0;str[i+1]!='\0';i++){
        for(int j=0;str[j+1]!='\0';j++){
            if(str[j]>str[j+1]){
                swap(str[j],str[j+1]);
            }
        }
    }
    for(int i=0;str[i]!='\0';i++){
        cout<<str[i];
    }
    return 0;
}