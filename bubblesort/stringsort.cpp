#include<iostream>
using namespace std;

int main(){
    string s="avmskjfiowppkfbmzvzgfwtua";
    int n=s.length();
    for(int i=0;s[i+1]!='\0';i++){
        for(int j=0;s[j+1]!='\0';j++){
            if(s[j]<s[j+1]){
                swap(s[j],s[j+1]);
            }
        }
    }
    for(int i=0;s[i]!='\0';i++){
        cout<<s[i]<<" ";
    }
    return 0;
}